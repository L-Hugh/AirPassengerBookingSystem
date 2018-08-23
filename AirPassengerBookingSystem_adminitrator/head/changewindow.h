#ifndef CHANGEWINDOW_H
#define CHANGEWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "flight.h"

namespace Ui {
class ChangeWindow;
}

class ChangeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeWindow(flightStruct flightS,QWidget *parent = 0);
    ~ChangeWindow();
public slots:
    void put();
    void deleteFlight();
public:
signals:
    void havePut();
    void haveDelete();

private:
    Ui::ChangeWindow *ui;
    flightStruct flightS;
};

#endif // CHANGEWINDOW_H
