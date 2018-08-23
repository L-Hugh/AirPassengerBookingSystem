#include "changewindow.h"
#include "ui_changewindow.h"


ChangeWindow::ChangeWindow(flightStruct flightS, QWidget *parent) :
    QDialog(parent),flightS(flightS),
    ui(new Ui::ChangeWindow)
{
    ui->setupUi(this);
    ui->lineEdit_airplane->setText(QString::fromLocal8Bit(flightS.airplane));
    ui->lineEdit_date->setText(flightS.date);
    ui->lineEdit_destination->setText(QString::fromLocal8Bit(flightS.destination));
    ui->label_id->setText(QString::fromLocal8Bit(flightS.id));
    ui->lineEdit_time->setText(flightS.time);
    ui->lineEdit_week->setText(flightS.week);
    ui->spinBox_1->setValue(flightS.capacity[0]);
    ui->spinBox_2->setValue(flightS.capacity[1]);
    ui->spinBox_3->setValue(flightS.capacity[2]);

    connect(ui->pushButton_put,SIGNAL(clicked(bool)),this,SLOT(put()));
    connect(ui->pushButton_delete,SIGNAL(clicked(bool)),this,SLOT(deleteFlight()));
}

ChangeWindow::~ChangeWindow()
{
    delete ui;
}

void ChangeWindow::put()
{
    QByteArray cpath;
    QString Qairplane=ui->lineEdit_airplane->text();
    QString Qdestination=ui->lineEdit_destination->text();
    QString Qdate=ui->lineEdit_date->text();
    QString Qtime=ui->lineEdit_time->text();
    QString Qweek=ui->lineEdit_week->text();
    cpath=Qairplane.toLocal8Bit();
    strcpy_s(flightS.airplane,cpath.data());
    cpath=Qdestination.toLocal8Bit();
    strcpy_s(flightS.destination,cpath.data());
    cpath=Qdate.toLocal8Bit();
    strcpy_s(flightS.date,cpath.data());
    cpath=Qtime.toLocal8Bit();
    strcpy_s(flightS.time,cpath.data());
    cpath=Qweek.toLocal8Bit();
    strcpy_s(flightS.week,cpath.data());
    flightS.capacity[0]=ui->spinBox_1->value();
    flightS.capacity[1]=ui->spinBox_2->value();
    flightS.capacity[2]=ui->spinBox_3->value();
    Flight flight;
    if(flight.putFlight(flightS.id,flightS)==1)
    {
        flight.closeFile();
        QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("ÐÞ¸Ä³É¹¦"));
        emit havePut();
        hide();
    }
    else
    {
        QMessageBox::critical(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("ÐÞ¸ÄÊ§°Ü"));
    }
}


void ChangeWindow::deleteFlight()
{
    if(QMessageBox::No == QMessageBox::question(this,QString::fromLocal8Bit("ÍËÆ±"),QString::fromLocal8Bit("ÊÇ·ñÉ¾³ý£¿"),QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes))
        return;
    Flight flight;
    if(flight.deleteFlight(flightS.id)==1)
    {
        flight.closeFile();
        QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("É¾³ý³É¹¦"));
        emit havePut();
        hide();
    }
    else
    {
        QMessageBox::critical(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("É¾³ýÊ§°Ü"));
    }

}
