//
// Created by 16977 on 2020/9/10.
//

#ifndef CSOCK_SLICE_H
#define CSOCK_SLICE_H


class Slice {
private:
    char *buffer;
    int len;
    int cap;
public:
    void append(Slice);
    int getLen();
    int getCap();

};


#endif //CSOCK_SLICE_H
