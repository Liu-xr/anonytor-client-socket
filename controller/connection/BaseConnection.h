//
// Created by 16977 on 2020/9/10.
//

#ifndef C_SOCKET_CLIENT_SOCKET_H
#define C_SOCKET_CLIENT_SOCKET_H

#include <winsock.h>
#include <string>
#include <vector>
#include "../definition/Slice.h"
#include "../definition/Request.h"
#define Control 0
#define Transfer 1
const int DefaultBufferLength = 256;
using namespace std;
using namespace Protocol;
namespace Connection {
    class BaseConnection {
    protected:
        SOCKADDR_IN ServerAddr;
        SOCKET Socket;
        Slice Buffer=Slice("",0,DefaultBufferLength);
        string HostID;
        string Key;
        int Type;

        //methods
        int basicSend(Slice) const;

        Slice basicRecv();

        int readAndAppendToBuffer();
        void sendHandshake();
        Request recvRequest();
        bool recvOK();
        int OK();
        int Reset();


    public:
        BaseConnection(const char *hostAddr, int port, const string &hostID, string key, int type);

        bool Connect();


    };

}


#endif //C_SOCKET_CLIENT_SOCKET_H
