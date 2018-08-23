#include "addflightwindow.h"
#include "ui_addflightwindow.h"

AddFlightWindow::AddFlightWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFlightWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_add,SIGNAL(clicked(bool)),this,SLOT(add()));
}

AddFlightWindow::~AddFlightWindow()
{
    delete ui;
}

void AddFlightWindow::add()
{
    flightStruct flightS;
    QByteArray cpath;
    QString Qid=ui->lineEdit_id->text();
    QString Qairplane=ui->lineEdit_airplane->text();
    QString Qdestination=ui->lineEdit_destination->text();
    QString Qdate=ui->lineEdit_date->text();
    QString Qtime=ui->lineEdit_time->text();
    QString Qweek=ui->lineEdit_week->text();
    cpath=Qid.toLocal8Bit();
    strcpy_s(flightS.id,cpath.data());
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
    flightS.sum[0]=0;
    flightS.sum[1]=0;
    flightS.sum[2]=0;
    Flight flight;
    if(flight.postFlight(flightS)==1)
    {
        flight.closeFile();
        QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("添加成功"));
        emit haveAdd();
        hide();
    }
    else
    {
        QMessageBox::critical(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("添加失败,航班号可能已经存在"));
    }

}
