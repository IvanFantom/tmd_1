#include "methods.h"

/*
<sup>2</sup> -- ������� ������
<sub>2</sub> -- ������ ������

*/

Methods::Methods()
{

}

QVector<Point> Methods::GetStandarts()
{
    return standart;
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

    QVector<int> cl;                   //������

    //��������� ������� �� �������
    cl.append(sample.value(0).clas);
    for(int i=1;i<sample.size();i++)
    {
        if(!cl.contains(sample.value(i).clas))
            cl.append(sample.value(i).clas);
    }

    //������� ������� ��� ������� ������
    Point p;
    for(int i=0;i<cl.size();i++)
    {
        int sx=0,sy=0;
        int k=0;
        for(int j=0;j<sample.size();j++)
        {
            if(sample.value(j).clas==cl.value(i))
            {
                sx+=sample.value(j).x;
                sy+=sample.value(j).y;
                k++;
            }
        }
        p.x=sx/k;
        p.y=sy/k;
        p.clas=cl.value(i);
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

    //������� ���������� ����� ������ �������� � ������������� ������
    dest.append(metric(X.x,X.y,standart.value(0).x,standart.value(0).y));
    value=dest.value(0);result=standart.value(0).clas;
    for(int i=1;i<standart.size();i++)
    {
        dest.append(metric(X.x,X.y,standart.value(i).x,standart.value(i).y));
        if( (value<dest.value(i) && dir==MAX) || (value>dest.value(i) && dir==MIN) )
        {
            value = dest.value(i);
            result = standart.value(i).clas;
        }else if(value==dest.value(i))
            return -2;
    }

    return standart.value(result).clas;
}

int Methods::K_Neighbors(Point X,int K,QVector<Point> sample,direction dir, int (*metric)(int, int, int, int))
{
    if(K>sample.size() || !sample.size() || !K)
        return -1;

    QVector<int> dest,analiz;
    QVector<int> cl;                   //������
    int result;

    //��������� ������� �� �������
    cl.append(sample.value(0).clas);
    for(int i=0;i<sample.size();i++)
    {
        if(!cl.contains(sample.value(i).clas))
            cl.append(sample.value(i).clas);
    }

    //�������� ������ �������
    QVector<int> ccount;
    for(int i=0;i<cl.size();i++)
        ccount.append(0);

    //������� ���������� ����� ������������� ������ � ������� �������
    for(int i=0;i<sample.size();i++)
    {
        dest.append(metric(X.x,X.y,sample.value(i).x,sample.value(i).y));
        analiz.append(dest.value(i));
    }
    //�������������� ���������� ��� �������� ������ K ���./����. ����������
    qSort(analiz);

    int j;
    if(dir==MAX)j=sample.size()-1;
    else j=0;

    //������� ���������� ������ �������
    while( (j-K>=0 && dir==MAX) || (j<=K-1 && dir==MIN) )
    {
        ccount[cl.indexOf(sample[dest.indexOf(analiz.value(j))].clas)]+=1;

        if(dir==MAX)j--;
        else j++;
    }

    int value=ccount[0],valuei=0;

    //� ������ ������ ������ ������?
    for(int i=1;i<ccount.size();i++)
    {
        if( value<ccount[i] )
        {
            value=ccount[i];
            valuei=i;
        }
        //else if(value==ccount[i])
        //    return -2;
    }

    return result=cl.value(valuei);
}

QVector<Point> Methods::findSplitLine(QVector<Point> srcpoints,int dx, int clas0, int clas1)
{
    QVector<Point> line,sample;
    int (*_metrix_)(int x1,int y1,int x2,int y2);
    Point P;
    int minX,minY,maxX,maxY;

    _metrix_ = Methods::EuclideanDistance;


    //��������� �� ��������� ����� ��������� �������
    for(int i=0;i<srcpoints.size();i++)
    {
        if(srcpoints.value(i).classType==DEFINED && (srcpoints.value(i).clas==clas0 || srcpoints.value(i).clas==clas1))
            sample.append(srcpoints.value(i));
    }

    minX = maxX = sample.value(0).x;
    minY = maxY = sample.value(0).y;

    //���������� ������ ������� � ������� ��������� ���� 2 ������
    for(int i=1;i<sample.size();i++)
    {
        if(minX>sample.value(i).x)
            minX=sample.value(i).x;
        else if(maxX<sample.value(i).x)
            maxX=sample.value(i).x;

        if(minY>sample.value(i).y)
            minY=sample.value(i).y;
        else if(maxY<sample.value(i).y)
            maxY=sample.value(i).y;
    }

    StandartsCalculation(sample); //���������� ��������

    for(int y=minY-1;y<maxY+1;y+=1)
    {
        P.y=y;
        P.clas = -1;
        P.classType = UNDEFINED;

        for(int x=minX-1;x<maxX+1;x+=1)
        {
            P.x=x;
            if(Standarts(P,MIN,_metrix_)==-2)//if(m.K_Neighbors(P,5,sample,dir,metric)==-2)
                line.append(P);
        }
    }

    for(int i=1,k=0;i<line.size()-1;i++)
    {
        if(k!=dx)
        {
            line.remove(i--);
            k++;
        }
        if(k==dx)
            k=0;
    }

    return line;
}

ChartLine Methods::findSplitLines(QVector<Point> srcpoints, int dx)
{
    ChartLine lines;
    QVector<Point> defined;
    QVector<int> cl;

    for(int i=0;i<srcpoints.size();i++)
    {
        if(srcpoints.value(i).classType==DEFINED)
            defined.append(srcpoints.value(i));
    }
    //��������� �������
    cl.append(defined.value(0).clas);
    for(int i=1;i<defined.size();i++)
    {
        if(!cl.contains(defined.value(i).clas))
            cl.append(defined.value(i).clas);
    }

    //���������� �������� ����� ����������� ����� ����� ����� ��������
    for(int i=0;i<cl.size();i++)
    {
        for(int j=i+1;j<cl.size();j++)
            lines.addLine(findSplitLine(defined,dx,cl.value(i),cl.value(j)),cl.value(i),cl.value(j));
    }

    return lines;
}

QVector<Point> Methods::calculateClass(QVector<Point> points, CalculateMethod method, CalculateMetrix metrix)
{
    QVector<Point> sample;
    QVector<Point> Xpoints;
    int (*_metrix_)(int x1,int y1,int x2,int y2);
    direction dir;

    //��������� �� ��������� ����� ��������� ������� � �����, ��� ����� ����������
    for(int i=0;i<points.size();i++)
    {
        if(points.value(i).classType==DEFINED)
            sample.append(points.value(i));
        else Xpoints.append(points.value(i));
    }

    //����������� ������� �������� ����������
    switch(metrix)
    {
        case CALCULATE_METRIX_EUCLIDEAN:
        {
            _metrix_ = Methods::EuclideanDistance;
            dir = MIN;
            break;
        }
        case CALCULATE_METRIX_DIRCOS:
        {
            _metrix_ = Methods::DirectionCosines;
            dir = MAX;
            break;
        }
        case CALCULATE_METRIX_TINIMOTO:
        {
            _metrix_ = Methods::TanimotoDistance;
            dir = MAX;
            break;
        }
    }

    //����� ������ ����������� �������������� ����������� ����� � ���� ����������� ��������������
    switch(method)
    {
        case CALCULATE_METHOD_STANTARD:
        {
            StandartsCalculation(sample);
            for(int i=0;i<Xpoints.size();i++)
            {
                Xpoints[i].clas=Standarts(Xpoints.value(i),dir,_metrix_);
                //! don't do it Xpoints[i].classType=DEFINED;
            }
            break;
        }
        case CALCULATE_METHOD_K_NEIGBORDS:
        {
            int K;
            for(int i=0;(sample.size()+i)%2==0;i++)
                K = (sample.size()+i)/2;

            for(int i=0;i<Xpoints.size();i++)
            {
                Xpoints[i].clas=K_Neighbors(Xpoints.value(i),K,sample,dir,_metrix_);/////////////////////////////////////////////����� �� ����� �������?
                //! don't do it Xpoints[i].classType=DEFINED;
            }
            break;
        }
    }

    foreach(Point p, sample)
        Xpoints.append(p);

    return Xpoints;
}

void Methods::WriteFile(QVector<Point> points,QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        cerr << "Cannot open file for writting: "
             << qPrintable(file.errorString()) << endl;
        return;
    }

    QTextStream out(&file);
    foreach(Point P,points)
    {
        out<<P.x<<" "<<P.y<<" "<<P.clas<<" ";
        if(P.classType == DEFINED)
            out<<"DEFINED";
        else if(P.classType == UNDEFINED)
            out<<"UNDEFINED";
        if(P != points.last())
            out<<"\r\n";
    }
}

QVector<Point> Methods::ReadFile(QString filename)
{
    QVector<Point> points;
    Point P;

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        cerr << "Cannot open file for reading: "
             << qPrintable(file.errorString()) << endl;
        return points;
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(' ');

        P.x = fields.takeFirst().toInt();
        P.y = fields.takeFirst().toInt();
        P.clas = fields.takeFirst().toInt();

        QString str = fields.takeFirst();
        if(str == "DEFINED")
            P.classType=DEFINED;
        else if(str == "UNDEFINED")
            P.classType=UNDEFINED;
        points.append(P);
    }

    return points;
}
