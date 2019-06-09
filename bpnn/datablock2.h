#ifndef DATABLOCK2_H
#define DATABLOCK2_H
#include "iostream"
#include "datablock.h"
class datablock2
{
public:
    datablock2();
    datablock2(datablock2 *);
    datablock2(int ,int );
    ~datablock2();
    void init(int ,int);
    double getvalue(int y,int x);
    double* getrowspoint(int y);
    void mul(datablock *b1,datablock *bout);

    double *getData() const;
    int getNum() const;
    int getRows() const;
    int getCols() const;
    void show();
private:
    bool inited=false;
    int m_num;
    int rows;
    int cols;
    double *data=NULL;
};


#endif // DATABLOCK2_H
