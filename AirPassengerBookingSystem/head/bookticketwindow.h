#ifndef BOOKTICKETWINDOW_H
#define BOOKTICKETWINDOW_H

#include <QDialog>
#include<cstring>
#include<QMessageBox>
#include"user.h"
#include"flight.h"
#include"ticket.h"

namespace Ui {
class BookTicketWindow;
}

class BookTicketWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BookTicketWindow(userStruct userS,flightStruct flight,QWidget *parent = 0);
    ~BookTicketWindow();

public slots:
    void book();
public:
signals:
    void haveBook();

private:
    Ui::BookTicketWindow *ui;
    userStruct userS;
    flightStruct flight;
    User user;
    Ticket ticket;
};

#endif // BOOKTICKETWINDOW_H
