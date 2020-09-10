//
// Created by 16977 on 2020/9/10.
//

#include "Response.h"

#include <utility>

using namespace Protocol;

Response::Response(string taskID, int taskStatus, char *data) {
    this->TaskID = std::move(taskID);
    this->TaskStatus = taskStatus;
    this->Data = data;
}