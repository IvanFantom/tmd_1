#ifndef METHODS_H
#define METHODS_H

#include <math.h>
#include "point.h"
#include <QVector>

class Methods
{
public:
    QVector<Point> standart; //������� �������

    Methods();

    static double DirectionCosines(double x1,double y1,double x2,double y2);  //������������ ��������
    static double EuclideanDistance(double x1,double y1,double x2,double y2); //��������� ����������
    static double TanimotoDistance(double x1,double y1,double x2,double y2);  //���������� ��������

    QVector< QVector<double> > Standarts(QVector<Point> sample, double (*metric)(double x1,double y1,double x2,double y2)); //����� ��������
    QVector< QVector<double> > K_Neighbors(QVector<Point> sample);  //����� k-��������� �������
};

#endif // METHODS_H
