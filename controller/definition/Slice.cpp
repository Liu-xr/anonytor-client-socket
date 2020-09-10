//
// Created by 16977 on 2020/9/10.
//

#include "Slice.h"
#include <iostream>

using namespace std;

Slice::Slice(char *data, int length, int expectCap) {
    if (expectCap < length) {
        expectCap = length;
    }
    this->buffer = (char *) malloc(sizeof(char) * expectCap);
    memcpy(this->buffer, data, length);
    this->len = length;
    this->cap = expectCap;
}

void Slice::append(Slice s) {
    this->cap += s.cap;
    char *newBuffer = (char *) malloc(sizeof(char) * this->cap);
    memcpy(newBuffer, this->buffer, this->len);
    memcpy(newBuffer + this->len, s.buffer, s.len);
    this->len += s.len;
    free(s.buffer);
    free(this->buffer);
    this->buffer=newBuffer;
}

int Slice::getCap() const {
    return this->cap;
}

int Slice::getLen() const {
    return this->len;
}

char Slice::get(int index) {
    return this->buffer[index];
}

void Slice::set(int index, char c) {
    this->buffer[index] = c;
}

Slice Slice::get(int i, int j) {
    if (j < i) {
        j = i;
    }
    char data[j - i ];
    for (int c = 0; c < j - i ; c++) {
        data[c] = this->buffer[c + i];
    }
    Slice ns = Slice(data, j - i , this->getCap());
    return ns;
}
Slice::~Slice() {
    free(this->buffer);
}