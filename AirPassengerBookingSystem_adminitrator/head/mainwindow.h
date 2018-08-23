#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginwindow.h"
#include "addflightwindow.h"
#include "changewindow.h"
#include "getticketwindow.h"

#include "ui_loginwindow.h"
#include "ui_addflightwindow.h"
#include "ui_changewindow.h"
#include "ui_getticketwindow.h"

#include <QMainWindow>
#include <QString>
#include <string>
#include <iostream>
#include "flight.h"
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
    int putFlight(int num);
    int getTicket(int num);
    void sentByCommandLinkButton_1();
    void sentByCommandLinkButton_2();
    void sentByCommandLinkButton_3();
    void sentByCommandLinkButton_4();
    void logIn();
    void logInSuccess(administratorStruct a);
    void addFlight();
    void refreshFlight();

public:
signals:
    void putTurn(int);//转发信号以识别是那个commandLinkButton

private:
    Ui::MainWindow *ui;
    Flight flight;
    flightStruct* flightAll;
    int page;
    int sum;
    administratorStruct administrator;
    LogInWindow logInWindow;
};


#endif // MAINWINDOW_H
