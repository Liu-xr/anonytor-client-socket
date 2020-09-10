//
// Created by 16977 on 2020/9/10.
//

#ifndef C_SOCKET_CLIENT_BASE_H
#define C_SOCKET_CLIENT_BASE_H
#include <string>
#include <iostream>
using namespace std;
class BaseTask{
private:
    string TaskID;
    int    Status ;
public:
    // Lifetimes
   virtual void OnTaskReceived(void );
    virtual void OnTaskWantRetrieveThroughCtrl(unsigned char *);
    virtual void OnTaskWantRetrieveThroughTrans(void );
    virtual void OnTransConnEstablished(void );
    virtual void OnTaskFinished(void );

};




#endif //C_SOCKET_CLIENT_BASE_H
