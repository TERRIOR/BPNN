#ifndef INPUTLAYER_H
#define INPUTLAYER_H
#include "layer.h"

class inputlayer:public layer
{
public:
    inputlayer();
    inputlayer(int i,double lr);
    ~inputlayer();
    // layer interface
public:
    void setup(int i,int o);
    datablock *forward(datablock *block);
    datablock *backward(datablock *block);
private:
    datablock inblock;
    datablock outblock;

};

#endif // INPUTLAYER_H
