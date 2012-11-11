#ifndef METHODS_H
#define METHODS_H

#include <math.h>
#include "point.h"
#include <QVector>

enum direction{MIN,MAX};

class Methods
{
    QVector<Point> standart; //эталоны классов
public:
    Methods();

    QVector<Point> GetStandarts();                                            //возвращает эталоны класслов
    void StandartsCalculation(QVector<Point> sample);                         //вычисление эталонов

    static double DirectionCosines(double x1,double y1,double x2,double y2);  //направляющие косинусы
    static double EuclideanDistance(double x1,double y1,double x2,double y2); //Евклидово расстояние
    static double TanimotoDistance(double x1,double y1,double x2,double y2);  //расстояние Танимото

    int Standarts(Point X,double (*metric)(double x1,double y1,double x2,double y2));                               //метод эталонов
    int K_Neighbors(Point X,int K,QVector<Point> sample,direction dir,double (*metric)(double x1,double y1,double x2,double y2));      //метод k-ближайших соседей
};

#endif // METHODS_H
