#include <QApplication>
#include "mainwindow.h"
#include "program.h"

#include "methods.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    /*Methods m;

    Point P;
    QVector<Point>  points,newp;
    int X[10]={4,1,5,1,3,6,8,6,9,4};
    int Y[10]={3,2,6,5,5,7,4,6,6,7};
    int C[10]={0,0,0,0,0,1,1,1,1,1};

    for(int i=0;i<10;i++)
    {
        P.clas=C[i];
        P.x=X[i];
        P.y=Y[i];

        P.classType=DEFINED;
        points.append(P);

        P.clas = -1;
        P.classType=UNDEFINED;
        points.append(P);
    }

    newp = m.ReadFile("points.txt");*/

    QApplication a(argc, argv);
    Program program;
    program.init();
    program.showGUI();

    return a.exec();
}
