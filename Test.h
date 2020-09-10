//
// Created by 16977 on 2020/9/10.
//

#ifndef CSOCK_TEST_H
#define CSOCK_TEST_H
#include <iostream>
#include "controller/connection/ControlConnection.h"
#include "controller/task/BaseTask.h"
using namespace Connection;
namespace Test{
    void TestConnect(ControlConnection cc){
        cc.Connect();
    }
    void TestSendResponse(ControlConnection cc){
        Response r=Response("testTaskID",Protocol::TaskReceived,"");
        bool status=cc.sendResponse(r);
        printf("%b",status);
    }
    void TestRecvRequest(ControlConnection cc){
        Request r=cc.recvRequest();
        cout<<r.TaskID<<endl;
        cout<<r.Cmd<<endl;
        cout<<r.Param<<endl;
    }
    void TestTaskExecute(BaseTask bt ,ControlConnection cc){
        // Received
        Response r=Response(bt.taskId, Protocol::TaskReceived, "");
        cc.sendResponse(r);
        bt.OnTaskReceived();
        //
        r.TaskStatus=Protocol::TaskWantRetrieveThroughCtrl;
        r.Data="result";
        bt.OnTaskWantRetrieveThroughCtrl()

    }
}
#endif //CSOCK_TEST_H