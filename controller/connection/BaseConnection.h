//
// Created by 16977 on 2020/9/10.
//

#ifndef C_SOCKET_CLIENT_SOCKET_H
#define C_SOCKET_CLIENT_SOCKET_H

#include <winsock.h>
#include <string>

#define Control 0
#define Transfer 1
const int DefaultBufferLength = 256;
using namespace std;
namespace Connection {
    class BaseConnection {
    protected:
        SOCKADDR_IN ServerAddr;
        SOCKET Socket;
        char *Buffer;
        int BufferLength = 0;
        int BufferCapacity = DefaultBufferLength;
        string HostID;
        string Key;
        int Type;

        //methods
        int basicSend(const char [], int dataLen);

        int basicRecv();

        int readAndAppendToBuffer();

        int OK();

        int Reset();

        static void padData(const char *, char *dest);

        static int calLenNeeded(const char *);

    public:
        BaseConnection(const char *hostAddr, int port, const string &hostID, string key, int type);

        int Connect();


    };

}


#endif //C_SOCKET_CLIENT_SOCKET_H
