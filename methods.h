#ifndef METHODS_H
#define METHODS_H

#include <math.h>
#include "point.h"
#include <QVector>

class Methods
{
public:
    QVector<Point> standart; //эталоны классов

    Methods();

    static double DirectionCosines(double x1,double y1,double x2,double y2);  //направляющие косинусы
    static double EuclideanDistance(double x1,double y1,double x2,double y2); //Евклидово расстояние
    static double TanimotoDistance(double x1,double y1,double x2,double y2);  //расстояние Танимото

    QVector< QVector<double> > Standarts(QVector<Point> sample, double (*metric)(double x1,double y1,double x2,double y2)); //метод эталонов
    QVector< QVector<double> > K_Neighbors(QVector<Point> sample);  //метод k-ближайших соседей
};

#endif // METHODS_H
