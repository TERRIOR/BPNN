#ifndef NET_H
#define NET_H
#include "layer.h"
#include "fclayer.h"
#include "inputlayer.h"
#include "outputlayer.h"
#include "vector"
class net
{
public:
    net();
    net(int inputnum,int outputnum ,int iteration,int layernum,double learn_rate,double end);
    void run(datablock &input,datablock &output);
    void addlayer(layer *);
    void clearlayer();
    void train(datablock &input,datablock &output);
private:
    std::vector<layer*> layervec;
    int m_iiteration;
    int m_ilayernum;
    int m_inputnum;
    int m_outputnum;
    double m_dlearn_rate;
    double enderror;
    double nowerror;
};

#endif // NET_H
