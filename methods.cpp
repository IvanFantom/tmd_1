#include "methods.h"

Methods::Methods()
{

}
int Methods::DirectionCosines(int x1, int y1, int x2, int y2)
{
    return (x1*x2+y1*y2)/(sqrt((x1*x1+y1*y1)*(x2*x2+y2*y2)));
}
int Methods::EuclideanDistance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int Methods::TanimotoDistance(int x1, int y1, int x2, int y2)
{
    return (x1*x2+y1*y2)/((x1*x1+y1*y1)+(x2*x2+y2*y2)-(x1*x2+y1*y2));
}
void Methods::StandartsCalculation(QVector<Point> sample)
{
    if(!standart.isEmpty())
        standart.clear();

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
        int sx=0,sy=0;
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
int Methods::Standarts(Point X,direction dir, int (*metric)(int, int, int, int))
{
    if(standart.isEmpty())
        return -1;

    QVector<int> dest;
    int value;
    int result;

    //рассчет расстояний между каждым эталоном и анализируемой точкой
    dest.append(metric(X.x,X.y,standart.at(0).x,standart.at(0).y));
    value=dest.at(0);result=standart.at(0).clas;
    for(int i=1;i<standart.size();i++)
    {
        dest.append(metric(X.x,X.y,standart.at(i).x,standart.at(i).y));
        if( (value<dest.at(i) && dir==MAX) || (value>dest.at(i) && dir==MIN) )
        {
            value = dest.at(i);
            result = standart.at(i).clas;
        }else if(value==dest.at(i))
            return -2;
    }

    return standart.at(result).clas;
}
int Methods::K_Neighbors(Point X,int K,QVector<Point> sample,direction dir, int (*metric)(int, int, int, int))
{
    if(K>sample.size() || !sample.size() || !K)
        return -1;

    QVector<int> dest,analiz;
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

    //рассчет расстояний между анализируемой точкой и точками выборки
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
        }else if(value==ccount[i])
            return -2;
    }

    return result=cl[valuei];
}
QVector<Point> Methods::DiscriminantLine(QVector<Point> sample,direction dir,int (*metric)(int, int, int, int))
{
    QVector<Point> line;
    Point P;

    StandartsCalculation(sample); //вычисление эталонов
    for(int y=0;y<21;y+=1)
    {
        P.y=y;
        for(int x=0;x<21;x+=1)
        {
            P.x=x;
            if(Standarts(P,dir,metric)==-2)//if(m.K_Neighbors(P,5,sample,dir,metric)==-2)
                line.append(P);
        }
    }
    return line;
}
