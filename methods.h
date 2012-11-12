#ifndef METHODS_H
#define METHODS_H

#include <math.h>
#include "point.h"
#include <QVector>

enum direction{MIN,MAX};

class Methods
{
    QVector<Point> standart; //������� �������
public:
    Methods();

    QVector<Point> GetStandarts();                                            //���������� ������� ��������
    void StandartsCalculation(QVector<Point> sample);                         //���������� ��������

    static int DirectionCosines(int x1,int y1,int x2,int y2);  //������������ ��������
    static int EuclideanDistance(int x1,int y1,int x2,int y2); //��������� ����������
    static int TanimotoDistance(int x1,int y1,int x2,int y2);  //���������� ��������

    int Standarts(Point X,direction dir,int (*metric)(int x1,int y1,int x2,int y2));                               //����� ��������
    int K_Neighbors(Point X,int K,QVector<Point> sample,direction dir,int (*metric)(int x1,int y1,int x2,int y2)); //����� k-��������� �������

    QVector<Point> DiscriminantLine(QVector<Point> sample,direction dir,int (*metric)(int, int, int, int));
};

#endif // METHODS_H
