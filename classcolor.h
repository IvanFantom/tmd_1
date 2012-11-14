/*!
 * @author Denis Vashchuk
*/


#ifndef CLASSCOLOR_H
#define CLASSCOLOR_H

#include <QtGui/QColor>

class ClassColor {
public:

    static QColor colorTable[];



    static QColor classToColor(int classNumber)
    {
        return (classNumber < 14 && classNumber != -1 )?(colorTable[classNumber]):(Qt::gray);
    }
};

QColor ClassColor::colorTable[] = { Qt::black,
                                    Qt::darkRed,
                                    Qt::darkGreen,
                                    Qt::blue,
                                    Qt::darkBlue,
                                    Qt::cyan,
                                    Qt::red,
                                    Qt::darkCyan,
                                    Qt::magenta,
                                    Qt::darkMagenta,
                                    Qt::yellow,
                                    Qt::darkYellow,
                                    Qt::darkGray,
                                    QColor(255,200,200)
                                  };

#endif
