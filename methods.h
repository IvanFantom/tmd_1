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

    static int DirectionCosines(int x1,int y1,int x2,int y2);  //направляющие косинусы
    static int EuclideanDistance(int x1,int y1,int x2,int y2); //Евклидово расстояние
    static int TanimotoDistance(int x1,int y1,int x2,int y2);  //расстояние Танимото

    int Standarts(Point X,direction dir,int (*metric)(int x1,int y1,int x2,int y2));                               //метод эталонов
    int K_Neighbors(Point X,int K,QVector<Point> sample,direction dir,int (*metric)(int x1,int y1,int x2,int y2)); //метод k-ближайших соседей

    QVector<Point> DiscriminantLine(QVector<Point> sample,direction dir,int (*metric)(int, int, int, int));
};

#endif // METHODS_H
