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

BaseConnection::BaseConnection(const char *addr, int port, const string &hostID, string key, bool type) {
    this->ServerAddr.sin_family = AF_INET;
    this->ServerAddr.sin_addr.S_un.S_addr = inet_addr(addr);
    this->ServerAddr.sin_port = htons(port);
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
    basicSend(s.data());
    cout << s;
}

int BaseConnection::basicSend(const char *data) {
    char *padData=this->padData(data);
    return 0;
}
int BaseConnection::basicRecv() {

}
char *BaseConnection::padData(const char *rawData) {
    int rawLen = sizeof(rawData) / sizeof(char);
    char tmpBuf[1024];
    char *rawLenS = itoa(rawLen, tmpBuf, 10);
    int rawLenSLen = strlen(rawLenS);
    char *newBuf=(char*)malloc(sizeof(char)*(rawLenSLen+1+rawLen));
    memcpy(newBuf, rawLenS, rawLenSLen);
    newBuf[rawLenSLen]='\n';
    memcpy(newBuf+rawLenSLen+1,rawData,rawLen);
    return newBuf;
}