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
void Methods::StandartsCalculation(QVector<Point> sample)
{
    QVector<int> cl;                   //классы

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
        int k=0;
        for(int j=0;j<sample.size();j++)
        {
            if(sample.at(j).clas==cl.at(i))
            {
                sx+=sample.at(j).x;
                sy+=sample.at(j).y;
                k++;
            }
        }
        p.x=sx/k;
        p.y=sy/k;
        p.clas=cl.at(i);
        standart.append(p);
    }
}
int Methods::Standarts(Point X, double (*metric)(double, double, double, double))
{
    if(standart.isEmpty())
        return -1;

    QVector<double> dest;
    double max = 0;
    int result;

    //рассчет расстояний между каждым эталоном и анализируемой точкой
    for(int i=0;i<standart.size();i++)
    {
        dest.append(metric(X.x,X.y,standart.at(i).x,standart.at(i).y));
        if(max<dest.at(i))
        {
            max = dest.at(i);
            result = i;
        }
    }

    return standart.at(result).clas;
}
int Methods::K_Neighbors(Point X,int K,QVector<Point> sample,direction dir, double (*metric)(double, double, double, double))
{
    if(K>sample.size() || !sample.size() || !K)
        return -1;

    QVector<double> dest,analiz;
    QVector<int> cl;                   //классы
    int result;

    //выделение классов из выборки
    cl.append(sample.at(0).clas);
    for(int i=0;i<sample.size();i++)
    {
        if(!cl.contains(sample.at(i).clas))
            cl.append(sample.at(i).clas);
    }

    //счетчики членов классов
    QVector<int> ccount;
    for(int i=0;i<cl.size();i++)
        ccount.append(0);

    //рассчет расстояний между точкой и точками выборки
    for(int i=0;i<sample.size();i++)
    {
        dest.append(metric(X.x,X.y,sample.at(i).x,sample.at(i).y));
        analiz.append(dest.at(i));
    }
    //упорядочивание расстояний для простоты поиска K мин./макс. расстояний
    qSort(analiz);

    int j;
    if(dir==MAX)j=sample.size()-1;
    else j=0;

    //подсчет количества членов классов
    while( (j-K>=0 && dir==MAX) || (j<=K-1 && dir==MIN) )
    {
        ccount[cl.indexOf(sample[dest.indexOf(analiz.at(j))].clas)]+=1;

        if(dir==MAX)j--;
        else j++;
    }

    int value=0,valuei;

    //у какого класса больше членов?
    for(int i=0;i<ccount.size();i++)
    {
        if( (value<ccount[i] && dir==MAX) || (value>ccount[i] && dir==MIN) )
        {
            value=ccount[i];
            valuei=i;
        }
    }

    return result=cl[valuei];
}

/*QVector< QVector<double> > Methods::Standarts(QVector<Point> sample,double (*metric)(double x1, double y1, double x2, double y2))
{
    QVector< QVector<double> > result;  //расстояния между каждым эталоном и точками исходной выборки

    StandartsCalculation(sample);       //вычисление эталонов

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
}*/
