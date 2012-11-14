#include <QtCore/QDebug>

#include "program.h"
#include "mainwindow.h"
#include "chartwidget.h"
#include "methods.h"

Program::Program()
{
    init();
}

void Program::init()
{
    window = new MainWindow(0x0);
    connect( window, SIGNAL(calculateButtonClicked()), this, SLOT(processCalculating()) );
    connect( window, SIGNAL(drawButtonClicked()), this, SLOT(processLineDraw()) );
}


void Program::showGUI()
{
    int classCount = 2;

    (window->getChartWidget())->setMaxX(200);
    (window->getChartWidget())->setMaxY(200);

    for(int i=0; i<10; i++)
    {
        Point point;
        point.x = qrand()%200;
        point.y = qrand()%200;
        point.clas = qrand()%classCount;

        (window->getChartWidget())->addPoint(point);
    }

    window->show();
}

void Program::processCalculating()
{
    qDebug() << "Finding undefined class point class.";
    Methods alg;
    QVector<Point> points = alg.calculateClass(window->getChartWidget()->getPoints(),
                                              window->getCalculateMethod(),
                                              window->getCalculateMetrix() );
    //seting up points
    window->getChartWidget()->setPoints(points);
}

void Program::processLineDraw()
{
    qDebug() << "Finding all spit lines...";
    Methods alg;
    ChartLine lines = alg.findSplitLines(window->getChartWidget()->getPoints());
    window->getChartWidget()->chartLines() = lines;
    window->getChartWidget()->repaint();
}

