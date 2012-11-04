#include <QApplication>
#include "mainwindow.h"
#include "program.h"

#include "methods.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    Methods m;
    QVector<Point> sample;
    QVector< QVector<double> > result;
    double (*metric)(double x1,double y1,double x2,double y2);

    Point  P;
    double X[10]={4,1,5,1,3,6,8,6,9,4};
    double Y[10]={3,2,6,5,5,7,4,6,6,7};
    char   C[10]={0,0,0,0,0,1,1,1,1,1};

    for(int i=0;i<10;i++)
    {
        P.clas=C[i];
        P.x=X[i];
        P.y=Y[i];
        sample.append(P);
    }

    metric = Methods::DirectionCosines;
    result = m.Standarts(sample,metric);

    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            printf("%lf\n",result[i].at(j));
        }
        printf("\n\n");
    }

    return 0;

    /*QApplication a(argc, argv);
    Program program;
    program.init();
    program.showGUI();

    return a.exec();*/
}
