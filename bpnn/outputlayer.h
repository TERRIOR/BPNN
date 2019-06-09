#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H
#include "layer.h"
#include "datablock2.h"
#include "caculateblock.h"
class outputlayer:public layer
{
public:
    outputlayer();
    outputlayer(int i,int o,double lr);

    ~outputlayer();

    // layer interface
public:
    void setup(int i,int o);
    datablock *forward(datablock *block);
    /**
     * @brief backward
     * @param block ±Í«©÷µ
     * @return
     */
    datablock *backward(datablock *block);
    double getError() const;

private:
    double m_error;
    datablock errorblock;
    datablock enextblock;
    datablock midblock;
    datablock outblock;
    datablock inblock;
    datablock2 wblock;
    datablock bblock;
};

#endif // OUTPUTLAYER_H
