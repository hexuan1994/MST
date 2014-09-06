#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "dialog.h"
#include "basecalculate.h"
#include "QGraphicsItemPoint.h"
#include "ShowScene.h"
#include "ShowView.h"
#include <QMainWindow>
#include <QFileDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void addvertex(vertex);

    ~MainWindow();
    void paint();

private slots:

    void on_inputPushButton_clicked();

    void on_runButton_clicked();

    void on_actionExit_triggered();

    void on_actionRun_triggered();

    void on_actionAddPoint_triggered();

    void addvertexslot(QString,QString);

private:
    Dialog *dialog;
    Ui::MainWindow *ui;
    ShowView *myView;
    ShowScene* scene;

};


#endif // MAINWINDOW_H
