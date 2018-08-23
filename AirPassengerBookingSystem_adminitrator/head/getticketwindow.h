#ifndef GETTICKETWINDOW_H
#define GETTICKETWINDOW_H

#include <QDialog>
#include<QMessageBox>
#include<iostream>
#include<cstring>
#include"flight.h"
#include"ticket.h"
#include"user.h"
#include"changewindow.h"

namespace Ui {
class GetTicketWindow;
}

class GetTicketWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GetTicketWindow(flightStruct flightS, QWidget *parent = 0);
    ~GetTicketWindow();
    int showTicket(int page);

public slots:
    int nextPage();
    int lastPage();
    int putFlight();
    void turnPut();//��ת��MainWindow��


public:
signals:
    void havePut();//������ҳ��ʾ�ĺ�����Ϣ

private:
    Ui::GetTicketWindow *ui;
    ticketStruct* ticketAll;
    Ticket ticket;
    flightStruct flightS;
    int page;
    int sum;
};

#endif // GETTICKETWINDOW_H
