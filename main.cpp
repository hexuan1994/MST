#include "mainwindow.h"
#include "Delaunay.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    Dialog d;
//    d.show();

    return a.exec();
}
