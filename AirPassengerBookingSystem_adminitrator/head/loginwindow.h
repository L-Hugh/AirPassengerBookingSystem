#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include<QWidget>
#include<QMessageBox>
#include"administrator.h"


namespace Ui {
class LogInWindow;
}


class LogInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogInWindow(QWidget *parent = 0);
    ~LogInWindow();
    administratorStruct getAdminitrator();

public slots:
    int logIn();

public:
signals:
    void successLogin(administratorStruct);

private:
    Ui::LogInWindow *ui;
    Administrator administrartor;
};

#endif // LOGINWINDOW_H
