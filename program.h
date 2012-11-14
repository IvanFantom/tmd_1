/*!
 * @author Denis Vashchuk
 * The main program class. Program start here.
*/

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
public slots:
    void processCalculating();
    void processLineDraw();

};

#endif // PROGRAM_H
