//
// Created by 16977 on 2020/9/10.
//

#include "ControlConnection.h"

#include <utility>

using namespace Connection;
using namespace std;

ControlConnection::ControlConnection(
        const char* hostAddr, int port, const string& hostID, string key, bool type)
        : BaseConnection(
        hostAddr, port, hostID, move(key),type
) {

}
