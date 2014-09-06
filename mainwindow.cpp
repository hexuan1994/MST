#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog = new Dialog;
    connect(dialog,SIGNAL(sendXandY(QString,QString)),this,SLOT(addvertexslot(QString,QString)));

    myView = new ShowView(this);
    myView->move(15,30);
    myView->resize(300,300);
    scene = new ShowScene(myView);
    myView->setScene(scene);
    myView->setSceneRect(scene->sceneRect());
    myView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputPushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), "",  tr("txt(*.txt*);;cpp(*.cpp)"));
    if (fileName != NULL)
        scene->baseCalculate->openfile(fileName.toStdString());
    ui->lineEdit->setText(fileName);
}

void MainWindow::on_runButton_clicked()
{
    if(ui->SimpleAlgorithm->isChecked())
    {
        //waiting
    }
    if(ui->DelaunayAlgorithm->isChecked())
    {
        scene->paintline();
        scene->paintitem();

    }
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionRun_triggered()
{
    ui->runButton->click();
}

void MainWindow::on_actionAddPoint_triggered()
{
    dialog->show();
}

void MainWindow::addvertexslot(QString X, QString Y)
{
    vertex* pV = new vertex;
    pV->SetX(X.toFloat());
    pV->SetY(Y.toFloat());
    addvertex(*pV);
    qDebug() << "addvertex successfully";
}

void MainWindow::addvertex(vertex pV0)
{
    scene->baseCalculate->addvertex(pV0);
    QGraphicsItemPoint *item = new QGraphicsItemPoint();
    item->setPos(pV0.GetX(),pV0.GetY());
    scene->addItem(item);
    update();

}

