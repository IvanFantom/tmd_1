#ifndef PROGRAM_H
#define PROGRAM_H

#include <QtCore/QObject>

class MainWindow;

class Program: public QObject
{
    Q_OBJECT
public:
    Program();
    void init();
    void showGUI();
private:
    MainWindow *window;
};

#endif // PROGRAM_H
