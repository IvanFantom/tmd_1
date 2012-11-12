#include <QApplication>
#include "mainwindow.h"
#include "program.h"

#include "methods.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    Methods m;
    QVector<Point> sample;
    int (*metric)(int x1,int y1,int x2,int y2);

    Point  P;
    int X[10]={4,1,5,1,3,6,8,6,9,4};
    int Y[10]={3,2,6,5,5,7,4,6,6,7};
    int C[10]={0,0,0,0,0,1,1,1,1,1};

    for(int i=0;i<10;i++)
    {
        P.clas=C[i];
        P.x=X[i];
        P.y=Y[i];
        sample.append(P);
    }

    metric = Methods::EuclideanDistance;

    //нахождение общих точек 2-х классов для построения по ним линии дискриминантности
    QVector<Point> line;
    line=m.DiscriminantLine(sample,MIN,metric);

    for(int i=0;i<line.size();i++)
        printf("x = %d, y = %d\n",line.at(i).x,line.at(i).y);

    //определение принадлежности точки к одному из классов разными способами
    //printf("\nStandarts: class %d",m.Standarts(P,MAX,metric));
    //printf("\nK_Neighbors: class %d\n",m.K_Neighbors(P,5,sample,MAX,metric));

    return 0;

    /*QApplication a(argc, argv);
    Program program;
    program.init();
    program.showGUI();

    return a.exec();*/
}
