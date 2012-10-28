#include "program.h"
#include "mainwindow.h"
#include "chartwidget.h"

Program::Program()
{
    window = new MainWindow(0x0);
}

void Program::init()
{

}


void Program::showGUI()
{
    ChartWidget* chart = new ChartWidget();
    chart->show();
    //window->show();
}
