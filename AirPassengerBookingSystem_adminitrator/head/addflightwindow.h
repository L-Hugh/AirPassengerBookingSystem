#ifndef ADDFLIGHTWINDOW_H
#define ADDFLIGHTWINDOW_H

#include <QDialog>
#include<QMessageBox>
#include<cstring>
#include"flight.h"


namespace Ui {
class AddFlightWindow;
}

class AddFlightWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddFlightWindow(QWidget *parent = 0);
    ~AddFlightWindow();

public slots:
    void add();
public:
signals:
    void haveAdd();

private:
    Ui::AddFlightWindow *ui;
};

#endif // ADDFLIGHTWINDOW_H
