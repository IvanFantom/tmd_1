#include <QApplication>
#include "mainwindow.h"
#include "program.h"

#include "methods.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    Methods m;
    QVector<Point> sample;
    double (*metric)(double x1,double y1,double x2,double y2);

    Point  P;
    double X[10]={4,1,5,1,3,6,8,6,9,4};
    double Y[10]={3,2,6,5,5,7,4,6,6,7};
    int    C[10]={0,0,0,0,0,1,1,1,1,1};

    for(int i=0;i<10;i++)
    {
        P.clas=C[i];
        P.x=X[i];
        P.y=Y[i];
        sample.append(P);
    }
    P.x=4;
    P.y=3;
    P.clas=-1;

    m.StandartsCalculation(sample);
    metric = Methods::TanimotoDistance;

    printf("\nStandarts: class %d",m.Standarts(P,metric));
    printf("\nK_Neighbors: class %d\n",m.K_Neighbors(P,5,sample,MAX,metric));

    return 0;

    /*QApplication a(argc, argv);
    Program program;
    program.init();
    program.showGUI();

    return a.exec();*/
}
