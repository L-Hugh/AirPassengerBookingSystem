#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include<QWidget>
#include<QMessageBox>
#include"user.h"
#include"registerwindow.h"


namespace Ui {
class LogInWindow;
}


class LogInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogInWindow(QWidget *parent = 0);
    ~LogInWindow();
    userStruct getUser();

public slots:
    int logIn();
    void registerUser();

public:
signals:
    void successLogin(userStruct);

private:
    Ui::LogInWindow *ui;
    User user;
};

#endif // LOGINWINDOW_H
