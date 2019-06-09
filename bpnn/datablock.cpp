#include "datablock.h"

datablock::datablock(int num)
{

    init(num);
}

datablock::datablock(datablock *block)
{
    if(m_num==block->getNum()&&inited){
        for (int var = 0; var < m_num; ++var) {
            data[var]=block->getData()[var];
        }
    }else{

        m_num=block->getNum();
        if(inited){
            delete data;
            data=NULL;
            inited=false;
        }
        if(!inited){
            data=new double[m_num];
            for (int var = 0; var < m_num; ++var) {
                data[var]=block->getData()[var];
            }
            inited=true;
        }
    }
}

void datablock::add(datablock &bin, datablock &bout)
{
    if(bin.getNum()!=m_num||bout.getNum()!=m_num){
        return;
    }
    if(!bout.getInited()){
        bout.init(m_num);
    }
    double* binpoint=bin.getData();
    double* boutpoint=bout.getData();
    for (int var = 0; var < m_num; ++var) {
        boutpoint[var]=data[var]+binpoint[var];
    }
}

void datablock::sub(datablock &bin, datablock &bout)
{
    if(bin.getNum()!=m_num||bout.getNum()!=m_num){
        return;
    }
    if(!bout.getInited()){
        bout.init(m_num);
    }
    double* binpoint=bin.getData();
    double* boutpoint=bout.getData();
    for (int var = 0; var < m_num; ++var) {
        boutpoint[var]=data[var]-binpoint[var];
    }
}

void datablock::init(int num)
{
    if(!inited){
        m_num=num;
        data=new double[num];
        //memset(data,0.5,num);
        for (int var = 0; var < num; ++var) {
            data[var]=0.1;
        }
        inited=true;
    }
}

void datablock::copyvalue(double *valuep, int numin)
{
//    init(numin);
//    if(numin!=m_num){
//        return;
//    }
    for (int var = 0; var < numin; ++var) {
        data[var]=valuep[var];
    }
}

datablock::~datablock()
{
    if(inited){
        if(data!=NULL){
            delete[] data;
            data=NULL;
        }
        inited=false;
        //std::cout<<"delete block"<<std::endl;
    }
}

datablock::datablock()
{

}

bool datablock::getInited() const
{
    return inited;
}

void datablock::setvalue(double value )
{
    for (int var = 0; var < m_num; ++var) {
        data[var]=value;
    }
}

void datablock::show()
{
    std::cout<<"[";
    for (int var = 0; var < m_num; ++var) {
        std::cout<< std::setprecision(3)<<data[var]<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void datablock::mul(datablock &bin, datablock &bout)
{
    if(bin.getNum()!=m_num||bout.getNum()!=m_num){
        return;
    }
    if(!bout.getInited()){
        bout.init(m_num);
    }
    double* binpoint=bin.getData();
    double* boutpoint=bout.getData();
    for (int var = 0; var < m_num; ++var) {
        boutpoint[var]=data[var]*binpoint[var];
    }
}

int datablock::getNum() const
{
    return m_num;
}

double *datablock::getData() const
{
    return data;
}
