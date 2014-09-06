#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    qDebug() << "send signal";
    emit sendXandY(ui->lineEdit_X->text(),ui->lineEdit_Y->text());
    ui->lineEdit_X->setText("");
    ui->lineEdit_Y->setText("");
}
