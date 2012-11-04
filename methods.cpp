#include "methods.h"

Methods::Methods()
{

}
double Methods::DirectionCosines(double x1, double y1, double x2, double y2)
{
    return (x1*x2+y1*y2)/(sqrt((x1*x1+y1*y1)*(x2*x2+y2*y2)));
}
double Methods::EuclideanDistance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double Methods::TanimotoDistance(double x1, double y1, double x2, double y2)
{
    return (x1*x2+y1*y2)/((x1*x1+y1*y1)+(x2*x2+y2*y2)-(x1*x2+y1*y2));
}
QVector< QVector<double> > Methods::Standarts(QVector<Point> sample,double (*metric)(double x1, double y1, double x2, double y2))
{
    QVector< QVector<double> > result;  //расстояния между каждым эталоном и точками исходной выборки
    QVector<char> cl;                   //классы

    //выделение классов из выборки
    cl.append(sample.at(0).clas);
    for(int i=0;i<sample.size();i++)
    {
        if(!cl.contains(sample.at(i).clas))
            cl.append(sample.at(i).clas);
    }

    //рассчет эталона для каждого класса
    Point p;
    for(int i=0;i<cl.size();i++)
    {
        double sx=0,sy=0;
        for(int j=0;j<sample.size();j++)
        {
            if(sample.at(j).clas==cl.at(i))
            {
                sx+=sample.at(j).x;
                sy+=sample.at(j).y;
            }
        }
        p.x=sx/cl.size();
        p.y=sy/cl.size();
        p.clas=cl.at(i);
        standart.append(p);
    }

    //рассчет расстояний между каждым эталоном и точками выборки
    for(int i=0;i<standart.size();i++)
    {
        result.append(QVector<double>());
        for(int j=0;j<sample.size();j++)
        {
            result[i].append(metric(sample.at(j).x,sample.at(j).y,standart.at(i).x,standart.at(i).y));
        }
    }

    return result;
}
