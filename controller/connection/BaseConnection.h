//
// Created by 16977 on 2020/9/10.
//

#ifndef C_SOCKET_CLIENT_SOCKET_H
#define C_SOCKET_CLIENT_SOCKET_H

#include <winsock.h>
#include <string>

#define Control true
#define Transfer false
using namespace std;
namespace Connection {
    class BaseConnection {
    protected:
        SOCKADDR_IN ServerAddr;
        SOCKET Socket;
        char ReadBuffer[128]{};
        string HostID;
        string Key;
        bool Type;

        //methods
        int basicSend(const char []);

        int basicRecv();

    public:
        BaseConnection(const char *hostAddr, int port, const string &hostID, string key, bool type);

        int Connect();

        int OK();
        int Reset();
        static char *padData(const char *);


    };

}


#endif //C_SOCKET_CLIENT_SOCKET_H
