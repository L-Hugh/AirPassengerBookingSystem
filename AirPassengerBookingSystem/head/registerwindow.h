#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include<cstring>
#include<QMessageBox>
#include<configuration.h>
#include"user.h"


namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = 0);
    ~RegisterWindow();

public slots:
    void registerUser();

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
