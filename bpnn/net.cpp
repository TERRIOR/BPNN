#include "net.h"

net::net()
{

}

net::net(int inputnum,int outputnum ,int iteration, int layernum, double learn_rate, double end)
{
    m_inputnum=inputnum;
    m_outputnum=outputnum;
    m_iiteration=iteration;
    m_ilayernum=layernum;
    m_dlearn_rate=learn_rate;
    enderror=end;
}

void net::run(datablock &input, datablock &output)
{
    datablock *block1;
    block1=&input;
    for (int var = 0; var < m_ilayernum; ++var) {
        layer *l=layervec[var];
        block1=l->forward(block1);
    }
    output=*block1;
}

void net::train(datablock &input,datablock &lableoutput)
{
    double *inputdata=input.getData();
    double *lableoutdata=lableoutput.getData();
    int iternum=0;
    int step=input.getNum()/m_inputnum;
    datablock inputblock(m_inputnum);
    datablock lableblock(m_outputnum);
    datablock outcalblock(m_outputnum);
    nowerror=1;
    while (nowerror>enderror&&iternum<m_iiteration) {
        //把所有的输入数据都跑一次
        nowerror=0;
        for (int var = 0; var < step; ++var) {
            lableblock.copyvalue(lableoutdata+var*m_outputnum,m_outputnum);
            inputblock.copyvalue(inputdata+var*m_inputnum,m_inputnum);
            run(inputblock,outcalblock);
            //outcalblock.show();
            //lableblock.show();
            outputlayer *lastlayer=dynamic_cast<outputlayer*>(layervec[m_ilayernum-1]);
            datablock *nexterror=lastlayer->backward(&lableblock);
            nowerror+=lastlayer->getError();
            for (int var2 = m_ilayernum-2; var2 >= 0; var2--) {
                layer *l=layervec[var2];
                nexterror=l->backward(nexterror);
            }

        }
        nowerror=nowerror/step;
        std::cout<<"error:"<<nowerror<<std::endl;
        iternum++;
    }
}

void net::addlayer(layer *lp)
{
    layervec.push_back(lp);
}

void net::clearlayer()
{

}
