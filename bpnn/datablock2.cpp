#include "datablock2.h"

datablock2::datablock2()
{

}

datablock2::datablock2(datablock2 *block)
{
    if(rows==block->getRows()&&cols==block->getCols()&&inited){
        for (int var = 0; var < m_num; ++var) {
            data[var]=block->getData()[var];
        }
    }else{
        rows=block->getRows();
        cols=block->getCols();
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

datablock2::datablock2(int rows, int cols)
{
    init(rows,cols);
}

datablock2::~datablock2()
{
    if(inited){
        delete data;
        data=NULL;
        inited=false;
        std::cout<<"delete block2"<<std::endl;
    }
}

void datablock2::init(int r, int c)
{
    rows=r;
    cols=c;
    m_num=rows*cols;

    if(!inited){
        //m_num=num;
        data=new double[m_num];
        for (int var = 0; var < m_num; ++var) {
            data[var]=0.1;
        }
        //memset(data,0.5,num);
        inited=true;
    }
}

double datablock2::getvalue(int y, int x)
{
    return data[y*cols+x];
}

double *datablock2::getrowspoint(int y)
{
    return data+y*cols;
}

void datablock2::mul(datablock *b1, datablock *bout)
{
    if(b1->getNum()!=cols){
        return;
    }
    if(!bout->getInited()){
        bout->init(rows);
    }
    double *inpoint=b1->getData();
    double *outpoint=bout->getData();
    for (int var = 0; var < rows; ++var) {
        double* rowpoint=getrowspoint(var);
        double total=0;
        for (int var2 = 0; var2 < cols; ++var2) {
            total+=rowpoint[var2]*inpoint[var2];
            //std::cout<<total<<" ";
        }
        outpoint[var]=total;
    }
}
void datablock2::show()
{
    std::cout<<"[";
    for (int var = 0; var < m_num; ++var) {
        std::cout<< std::setprecision(3)<<data[var]<<" ";
    }
    std::cout<<"]"<<std::endl;
}

double *datablock2::getData() const
{
    return data;
}

int datablock2::getNum() const
{
    return m_num;
}

int datablock2::getRows() const
{
    return rows;
}

int datablock2::getCols() const
{
    return cols;
}
