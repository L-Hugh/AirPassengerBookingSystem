#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QDialog>
#include<QMessageBox>
#include<iostream>
#include<cstring>
#include"flight.h"
#include"ticket.h"
#include"user.h"

using namespace std;

namespace Ui {
class UserWindow;
}

class UserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserWindow(userStruct userS, QWidget *parent = 0);
    ~UserWindow();
    int showFlight(int page);

public slots:
    int nextPage();
    int lastPage();
    int bookTicket(int num);
    void sentByCommandLinkButton_1();
    void sentByCommandLinkButton_2();
    void sentByCommandLinkButton_3();
    void sentByCommandLinkButton_4();

public:
signals:
    void bookTurn(int);//ת���ź���ʶ�����Ǹ�commandLinkButton
    void haveDis();//��Ʊ�������ҳ��ʾ�ĺ�����Ϣ

private:
    Ui::UserWindow *ui;
    ticketStruct* ticketAll;
    Ticket ticket;
    userStruct userS;
    int page;
    int sum;
};

#endif // USERWINDOW_H

