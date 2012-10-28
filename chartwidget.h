#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H


#include <QtGui/QWidget>
#include "point.h"

#define EDGE_OFFSET 20
#define POINT_SIZE 10
#define FONT_SIZE 10
#define AXIS_EDGE_OFFSET 20
#define DEVISION 10
#define DEVISION_HEIGHT 2

class ChartWidget: public QWidget
{
    Q_OBJECT
public:
    ChartWidget(QWidget *parrent = 0x0);
private:
    int edgeOffset;
    int pointSize;
    int fontSize;
    int axisEdgeOffset;
    int devision;
    int xScale;
    int yScale;
    int maxX;
    int maxY;
protected:
    void paintEvent ( QPaintEvent * event );
    void drawBackground(QPainter& painter);
    void drawAxis(QPainter& painter);
    void drawPoint(QPainter& painter, const Point& point, QColor color);
};

#endif // CHARTWIDGET_H
