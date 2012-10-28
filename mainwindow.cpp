#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chartwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setSizeIncrement(1,1);
    chart = new ChartWidget(this);
    chart->setSizeIncrement(3, 1);
    //ui->layoutData->addWidget(chart);
}

MainWindow::~MainWindow()
{
    delete ui;
}
