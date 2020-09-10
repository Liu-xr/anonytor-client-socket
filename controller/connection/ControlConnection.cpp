//
// Created by 16977 on 2020/9/10.
//

#include "ControlConnection.h"

#include <utility>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace Connection;
using namespace std;

ControlConnection::ControlConnection(
        const char *hostAddr, int port, const string &hostID, string key, bool type)
        : BaseConnection(
        hostAddr, port, hostID, move(key), type
) {

}



bool ControlConnection::sendResponse(Response response) {
    json j;
    j["task_id"] = response.TaskID;
    j["task_status"] = response.TaskStatus;
    j["Data"] = response.Data;
    string s = j.dump();
    Slice sl = Slice((char *) s.data(), s.length(), s.length());
    this->basicSend(sl);
    return this->recvOK();
}