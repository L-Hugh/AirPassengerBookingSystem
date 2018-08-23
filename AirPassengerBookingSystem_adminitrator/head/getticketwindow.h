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
    void turnPut();//中转到MainWindow类


public:
signals:
    void havePut();//更新主页显示的航班信息

private:
    Ui::GetTicketWindow *ui;
    ticketStruct* ticketAll;
    Ticket ticket;
    flightStruct flightS;
    int page;
    int sum;
};

#endif // GETTICKETWINDOW_H
