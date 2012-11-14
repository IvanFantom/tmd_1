#-------------------------------------------------
#
# Project created by QtCreator 2012-10-21T13:09:38
#
#-------------------------------------------------

QT       += core gui

SOURCES += 	main.cpp\
		mainwindow.cpp \
		chartwidget.cpp \
		program.cpp \
		exception.cpp\
		methods.cpp \
    pointadddialog.cpp \
    chartline.cpp

HEADERS  += mainwindow.h \
	   chartwidget.h \
	   program.h \
	   point.h \
           exception.h \
           methods.h \
    classcolor.h \
    pointadddialog.h \
    enums.h \
    chartline.h
		
FORMS    += mainwindow.ui \
    pointadddialog.ui

RESOURCES += \
    resources/resources.qrc
