//
// Created by 16977 on 2020/9/10.
//
#include <winsock.h>
#include "BaseConnection.h"
#include <iostream>
#include "spdlog/spdlog.h"
#include "../definition/Notice.h"
#include "../definition/Handshake.h"
#include "nlohmann/json.hpp"
#include <cstdlib>

#pragma comment(lib, "ws2_32.lib")
using namespace Connection;
using namespace std;
using namespace spdlog;
using json = nlohmann::json;

BaseConnection::BaseConnection(const char *addr, int port, const string &hostID, string key, int type) {
    this->ServerAddr.sin_family = AF_INET;
    this->ServerAddr.sin_addr.S_un.S_addr = inet_addr(addr);
    this->ServerAddr.sin_port = htons(port);
    this->Buffer=(char*)malloc(sizeof(char)*DefaultBufferLength);
    this->Socket = socket(AF_INET, SOCK_STREAM, 0);
    this->Key = move(key);
    this->Type = type;
    this->HostID = hostID;
}

int BaseConnection::Connect() {
    if (connect(this->Socket, (SOCKADDR *) &this->ServerAddr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        error(Notice::ServerConnectError);
    } else {
        debug(Notice::ServerConnected);
    }
    Handshake hs = Handshake(this->HostID, this->Key, this->Type, "");
    json j;
    j["host_id"] = hs.HostID;
    j["key"] = hs.Key;
    j["type"] = hs.Type;
    j["task_id"] = hs.TaskID;
    string s = j.dump();
    basicSend(s.data(), s.length());
}

int BaseConnection::basicSend(const char *data, int dataLen) {
    // get len of string(dataLen)
    char lenStr[512];
    itoa(dataLen, lenStr, 10);
    int numLen = strlen(lenStr);
    int wholeLen = numLen + 1 + dataLen;
    // alloc buffer
    char tmp[wholeLen];
    // copy data to buffer
    memcpy(tmp, lenStr, numLen);
    tmp[numLen] = '\n';
    memcpy(tmp + numLen + 1, data, dataLen);
    // send
    cout << tmp;
    int sendLen = send(this->Socket, tmp, wholeLen, 0);
    return sendLen == wholeLen;

}

int BaseConnection::basicRecv() char *{
    int readLength=this->readAndAppendToBuffer();
    // get index of \n
    int index = 0;
    while (this->Buffer[index] != '\n') {
        index++;
    }
    char possibleNum[index];
    memcpy(possibleNum, this->Buffer, index);
    int rawDataLen = atoi(possibleNum);
    int wholeDataLen = rawDataLen + 1 + index;
    while (readLength < wholeDataLen) {
        readLength+=readAndAppendToBuffer();
    }

}

int BaseConnection::readAndAppendToBuffer() {
    char tmpBuffer[DefaultBufferLength];
    int originLength=this->BufferLength;
    int newlyReadLen = recv(this->Socket, tmpBuffer, DefaultBufferLength, 0);
    this->BufferLength += newlyReadLen;
    if (originLength+newlyReadLen > this->BufferCapacity) {
        char *originBuffer = this->Buffer;
        this->BufferCapacity=DefaultBufferLength*(this->BufferLength/DefaultBufferLength+1);
        this->Buffer=(char*)malloc(sizeof(char)*this->BufferCapacity);
        memcpy(this->Buffer,originBuffer,originLength);
        free(originBuffer);
    }
    memcpy(this->Buffer+originLength,tmpBuffer,newlyReadLen);
    return newlyReadLen;
}
