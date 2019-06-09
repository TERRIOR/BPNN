#ifndef FCLAYER_H
#define FCLAYER_H
#include "layer.h"
#include "datablock2.h"
#include "caculateblock.h"
class fclayer:public layer
{
public:
    fclayer();
    fclayer(int i,int o,double lr);
    ~fclayer();

    // layer interface
public:
    void setup(int i,int o);
    datablock *forward(datablock *block);
    datablock *backward(datablock *block);
private:
    datablock errorblock;
    datablock enextblock;
    datablock midblock;
    datablock inblock;
    datablock outblock;
    datablock2 wblock;
    datablock bblock;
};

#endif // FCLAYER_H
