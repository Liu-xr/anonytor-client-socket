//
// Created by 16977 on 2020/9/10.
//

#ifndef CSOCK_SLICE_H
#define CSOCK_SLICE_H


class Slice {
private:

    int len;
    int cap;
public:
    char *buffer;
    Slice(char*data,int length,int expectCap);
    ~Slice();
    void append(Slice);
    int getLen() const;
    int getCap() const;
    char get(int index);
    void set(int index,char c);
    Slice get(int i,int j);
};


#endif //CSOCK_SLICE_H
