//
// Created by 16977 on 2020/9/10.
//

#include "BaseTask.h"
#include <windows.h>

using namespace std;

string BaseTask::retrieveError() {
    return this->errorDescription;
}

bool BaseTask::validateParam() {
    return true;
}

bool BaseTask::execute() {
    Sleep(1000);
    return true;
}

bool BaseTask::checkIfTransConnNeeded() {
    return true;
}

string BaseTask::getSerializedResult() {
    return this->result;
}

bool BaseTask::sendResultThroughConn(SOCKET socket) {
    char d[] = "TaskFinished";
    int sentLen = send(socket, d, strlen(d), 0);
    return sentLen == strlen(d);

}

bool BaseTask::checkFinish() {
    return true;
}