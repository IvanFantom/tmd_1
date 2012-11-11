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

    static double DirectionCosines(double x1,double y1,double x2,double y2);  //������������ ��������
    static double EuclideanDistance(double x1,double y1,double x2,double y2); //��������� ����������
    static double TanimotoDistance(double x1,double y1,double x2,double y2);  //���������� ��������

    int Standarts(Point X,double (*metric)(double x1,double y1,double x2,double y2));                               //����� ��������
    int K_Neighbors(Point X,int K,QVector<Point> sample,direction dir,double (*metric)(double x1,double y1,double x2,double y2));      //����� k-��������� �������
};

#endif // METHODS_H
