#include "fclayer.h"

fclayer::fclayer()
{

}

fclayer::fclayer(int i, int o,double lr)
{
    setup(i,o);
    mlr=lr;
}

fclayer::~fclayer()
{
    //std::cout<<"release fclayer"<<std::endl;
}

void fclayer::setup(int i, int o)
{
    innum=i;
    outnum=o;
    errorblock.init(o);
    enextblock.init(i);
    midblock.init(o);
    inblock.init(i);
    outblock.init(o);
    wblock.init(o,i);
    bblock.init(o);
}

datablock *fclayer::forward(datablock *block)
{
    inblock=*block;
    wblock.mul(block,&midblock);
    midblock.add(bblock,outblock);
    sigblock(outblock);
    return &outblock;
}

datablock *fclayer::backward(datablock *block)
{
    datablock oneblock(outblock.getNum());
    datablock tempblock1(outblock.getNum());
    //计算输出层的errorj
    oneblock.setvalue(1);
    oneblock.sub(outblock,tempblock1);
    outblock.mul(tempblock1,errorblock);
    errorblock.mul(*block,errorblock);
    //计算梯度 更新权值
    double *errordata=errorblock.getData();
    double *oidata=inblock.getData();
    double *bdata=bblock.getData();
    for (int var = 0; var < wblock.getRows(); ++var) {
        double *wcol=wblock.getrowspoint(var);
        for (int var2 = 0; var2 < wblock.getCols(); ++var2) {
            wcol[var2]=wcol[var2]+mlr*oidata[var2]*errordata[var];
        }
        bdata[var]=bdata[var]+mlr*errordata[var];
    }
    //计算传递到下一层的error部分
    double *erndata=enextblock.getData();
    for (int var = 0; var < wblock.getCols(); ++var) {
        erndata[var]=0;
        for (int var2 = 0; var2 < wblock.getRows(); ++var2) {
            erndata[var]+=errordata[var2]*wblock.getvalue(var,var2);
        }
    }
    return &enextblock;
}
