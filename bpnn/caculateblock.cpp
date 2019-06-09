#include "caculateblock.h"


void sigblock(datablock &block)
{
    double *datapoint=block.getData();
    for (int var = 0; var < block.getNum(); ++var) {
        datapoint[var]=sigmoid(datapoint[var]);
    }
}
