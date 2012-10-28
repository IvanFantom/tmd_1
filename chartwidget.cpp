#include "chartwidget.h"
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <QtGui/QBrush>

ChartWidget::ChartWidget(QWidget* parrent):QWidget(parrent)
{
    edgeOffset = EDGE_OFFSET;
    pointSize = POINT_SIZE;
    fontSize = FONT_SIZE;
    axisEdgeOffset = AXIS_EDGE_OFFSET;
    devision = DEVISION;

    maxX = 20;
    maxY = 20;
}

void ChartWidget::paintEvent(QPaintEvent *event)
{
    xScale = width() / maxX;
    yScale = height() / maxY;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBackground(painter);
    drawAxis(painter);

    Point p;
    p.x=10;
    p.y=10;

    drawPoint(painter, p, Qt::green);
}

void ChartWidget::drawBackground(QPainter &painter)
{
    painter.setPen(Qt::SolidLine);
    painter.setBrush(Qt::SolidPattern);
    painter.fillRect(edgeOffset, edgeOffset,
                     this->width()-2*edgeOffset, this->height()-2*edgeOffset,
                     Qt::white);
}

void ChartWidget::drawPoint(QPainter &painter, const Point &point, QColor color)
{
    QBrush brush;
    brush.setColor(color);
    painter.setBrush(brush);
    painter.drawEllipse( ( (point.x)*xScale ) + edgeOffset + axisEdgeOffset,
                        height() - ( point.y )*yScale - edgeOffset - axisEdgeOffset,
                        pointSize, pointSize );
}


void ChartWidget::drawAxis(QPainter &painter)
{
    int dx = 10;
    int dy = 10;

    int yx = axisEdgeOffset + edgeOffset;
    int yy = height() - yx;
    int yheight = edgeOffset + axisEdgeOffset;
    int ywidth = yx;
    painter.drawLine(yx, yy, ywidth, yheight);
    int y_count = (height() - 2*edgeOffset - 2*axisEdgeOffset) / devision;
    for( int i = 0; i<y_count; i++ ) {
        painter.drawLine(yx-DEVISION_HEIGHT, yy-devision*i, yx+DEVISION_HEIGHT, yy-devision*i);
    }


    int xx = axisEdgeOffset + edgeOffset;
    int xy = height() - xx;
    int xheight = xy;
    int xwidth = width() - xx;
    painter.drawLine(xx, xy, xwidth, xheight);
    int x_count = (width() - 2*edgeOffset - 2*axisEdgeOffset) / devision;
    for( int i = 1; i<x_count; i++) {
        painter.drawLine(xx+devision*i, xy+DEVISION_HEIGHT, xx+devision*i, xheight-DEVISION_HEIGHT);
    }
}
