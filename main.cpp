#include "mainwindow.h"
#include <QApplication>
#include<stdio.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(405,656);
    w.setWindowFlags(Qt::WindowCloseButtonHint);
    w.show();
    return a.exec();
}
