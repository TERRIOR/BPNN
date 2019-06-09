#ifndef CACULATEBLOCK_H
#define CACULATEBLOCK_H
#include "datablock.h"

inline double sigmoid(double x)
{
    double ans = 1 / (1+exp(-x));
    return ans;
}
void sigblock(datablock &block);


#endif // CACULATEBLOCK_H
