#include "inputlayer.h"

inputlayer::inputlayer()
{

}

inputlayer::inputlayer(int i, double lr)
{
    setup(i,i);
    mlr=lr;
}

inputlayer::~inputlayer()
{
    //std::cout<<"release inputlayer"<<std::endl;
}

void inputlayer::setup(int i, int o)
{
    innum=i;
    outnum=o;
    inblock.init(i);
    outblock.init(o);
}

datablock *inputlayer::forward(datablock *block)
{
    inblock=*block;
    outblock=inblock;
    return &outblock;
}

datablock *inputlayer::backward(datablock *block)
{
    return NULL;
}
