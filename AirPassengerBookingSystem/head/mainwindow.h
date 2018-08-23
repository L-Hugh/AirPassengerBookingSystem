#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "userwindow.h"
#include "loginwindow.h"
#include "registerwindow.h"
#include"bookticketwindow.h"

#include "ui_userwindow.h"
#include "ui_loginwindow.h"
#include "ui_registerwindow.h"
#include "ui_bookticketwindow.h"

#include <QMainWindow>
#include<iostream>
#include"flight.h"
#include"user.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int showFlight(int page);

public slots:
    int nextPage();
    int lastPage();
    int searchDestination();
    int bookTicket(int num);
    void sentByCommandLinkButton_1();
    void sentByCommandLinkButton_2();
    void sentByCommandLinkButton_3();
    void sentByCommandLinkButton_4();
    void logIn();
    void logInSuccess(userStruct u);
    void userInformation();
    void refreshFlight();

public:
signals:
    void bookTurn(int);//转发信号以识别是那个commandLinkButton

private:
    Ui::MainWindow *ui;
    Flight flight;
    flightStruct* flightAll;
    int page;
    int sum;
    userStruct user;
    LogInWindow logInWindow;
};


#endif // MAINWINDOW_H
