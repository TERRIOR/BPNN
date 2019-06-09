#ifndef LAYER_H
#define LAYER_H
#include "datablock.h"
#include "iostream"
class layer
{
public:
    layer();
    virtual ~layer()=0;
    virtual void setup(int i,int o)=0;
    virtual datablock* forward(datablock *block)=0;
    virtual datablock* backward(datablock *block)=0;
    int innum;
    int outnum;
    double mlr;
private:
};

#endif // LAYER_H
