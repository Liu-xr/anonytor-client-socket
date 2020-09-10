//
// Created by 16977 on 2020/9/10.
//

#ifndef C_SOCKET_CLIENT_BASE_H
#define C_SOCKET_CLIENT_BASE_H

#include <string>
#include <iostream>
#include <utility>
#include <winsock2.h>
using namespace std;

class BaseTask {
private:
    string errorDescription;
    string result;
public:
    string taskId;
    string param;
    string transType;

    BaseTask(string taskId, string param) {
        this->taskId = std::move(taskId);
        this->param = std::move(param);
    };

    // Lifetimes
    //retrieveError 返回当前错误的描述。
    // 理想情况下，当其他方法返回的 bool=false 时
    // 调用此方法获取错误描述，然后上层发送给服务端
    virtual string retrieveError();
    virtual bool validateParam();
    virtual bool execute();
    virtual bool checkIfTransConnNeeded();
    virtual string getSerializedResult();
    virtual bool sendResultThroughConn(SOCKET socket);
    virtual bool checkFinish();


};


#endif //C_SOCKET_CLIENT_BASE_H
