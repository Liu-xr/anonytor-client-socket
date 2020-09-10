//
// Created by 16977 on 2020/9/10.
//

#ifndef CSOCK_CONTROLCONNECTION_H
#define CSOCK_CONTROLCONNECTION_H

#include "BaseConnection.h"
#include <string>

namespace Connection {
    class ControlConnection : public BaseConnection {
    private:
        string HostID;
        string Key;
    public:
        ControlConnection(const char* hostAddr, int port, const string& hostID, string key, bool type);
    };
}


#endif //CSOCK_CONTROLCONNECTION_H