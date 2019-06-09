#include "outputlayer.h"

outputlayer::outputlayer()
{

}

outputlayer::outputlayer(int i, int o,double lr)
{
    setup(i,o);
    mlr=lr;
}

outputlayer::~outputlayer()
{
    //std::cout<<"release outputlayer"<<std::endl;
}

void outputlayer::setup(int i, int o)
{
    innum=i;
    outnum=o;
    wblock.init(o,i);
    inblock.init(i);
    midblock.init(o);
    bblock.init(o);
    outblock.init(o);
    errorblock.init(o);
    enextblock.init(i);
}

datablock *outputlayer::forward(datablock *block)
{
    inblock=*block;
    wblock.mul(block,&midblock);
    midblock.add(bblock,outblock);
    sigblock(outblock);
    return &outblock;
}

datablock *outputlayer::backward(datablock *block)
{

    datablock oneblock(outblock.getNum());
    datablock tempblock1(outblock.getNum());
    datablock tempblock2(outblock.getNum());
    oneblock.setvalue(1);
    //����������errorj
    block->sub(outblock,tempblock2);
    oneblock.sub(outblock,tempblock1);//��������󵼲���
    outblock.mul(tempblock1,errorblock);
    errorblock.mul(tempblock2,errorblock);

    double *diff=tempblock2.getData();
    //����error
    m_error=0;
    for (int var = 0; var < outnum; ++var) {
        m_error+=diff[var]*diff[var];
    }
    m_error=m_error/2;
    //�����ݶ� ����Ȩֵ
    double *errordata=errorblock.getData();
    double *oidata=inblock.getData();
    double *bdata=bblock.getData();
    for (int var = 0; var < wblock.getRows(); ++var) {
        double *wcol=wblock.getrowspoint(var);
        for (int var2 = 0; var2 < wblock.getCols(); ++var2) {
            double adderror=mlr*oidata[var2]*errordata[var];
            wcol[var2]=wcol[var2]+adderror;
        }
        double adderrorb=mlr*errordata[var];
        bdata[var]=bdata[var]+adderrorb;
    }
    //���㴫�ݵ���һ���error����
    double *erndata=enextblock.getData();
    for (int var = 0; var < wblock.getCols(); ++var) {
        erndata[var]=0;
        for (int var2 = 0; var2 < wblock.getRows(); ++var2) {
            erndata[var]+=errordata[var2]*wblock.getvalue(var,var2);
        }
    }
    return &enextblock;
}

double outputlayer::getError() const
{
    return m_error;
}
