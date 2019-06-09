#include <QCoreApplication>
#include "fclayer.h"
#include "net.h"
#include "stdlib.h"
#include "mytime.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /**************设计训练数据*****************/
    datablock traindatain(500);
    datablock traindataout(500);
    double *datain=traindatain.getData();
    double *dataout=traindataout.getData();
    for (int var = 0; var < 250; ++var) {
        int a=rand()%100;
        int b=rand()%100;
        int x=a+b;
        datain[var*2]=(double)(a)/100;
        datain[var*2+1]=(double)(b)/100;
        if(x>100){
            dataout[var*2]=0;
            dataout[var*2+1]=1;
        }else{
            dataout[var*2]=1;
            dataout[var*2+1]=0;
        }
    }
    /**************构建网络层*****************/
    inputlayer il(2,0.1);
    fclayer fc1(2,4,0.1);
    fclayer fc2(4,4,0.1);
    outputlayer ol(4,2,0.1);
    net bpnn(2,2,100000,4,0.1,0.01);
    /**************加载到网络*****************/
    bpnn.addlayer(&il);
    bpnn.addlayer(&fc1);
    bpnn.addlayer(&fc2);
    bpnn.addlayer(&ol);
    /**************网络训练*****************/
    bpnn.train(traindatain,traindataout);
    /**************测试网络*****************/
    datablock testdata(2);
    datablock testres(2);
    int count=0;
    for (int var = 0; var <= 100; ++var) {
        int a=rand()%100;
        int b=rand()%100;
        testdata.getData()[0]=(double)a/100;
        testdata.getData()[1]=(double)b/100;
        mytime timer;
        //timer.TimerStart();
        bpnn.run(testdata,testres);
        //std::cout<<timer.TimerFinish()<<std::endl;
        if((testres.getData()[0]<testres.getData()[1])==(a+b>100)){
            count++;
        }
    }
    std::cout<<"正确率:"<<count<<"%"<<std::endl;
    return a.exec();
}
