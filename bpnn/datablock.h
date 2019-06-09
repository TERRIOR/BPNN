#ifndef DATABLOCK_H
#define DATABLOCK_H
#include "iostream"
#include <iomanip>
class datablock
{
public:
    datablock(int num);
    datablock(datablock*);
    ~datablock();
    datablock();
    void init(int num);
    void copyvalue(double *valuep,int num);
    double *getData() const;
    int getNum() const;
    bool getInited() const;
    void setvalue(double value);
    void show();
    void mul(datablock &bin,datablock &bout);
    void add(datablock &bin,datablock &bout);
    void sub(datablock &bin, datablock &bout);
private:
    bool inited=false;
    int m_num;
    double *data=NULL;
};

#endif // DATABLOCK_H
