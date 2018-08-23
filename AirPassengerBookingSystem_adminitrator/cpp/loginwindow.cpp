#include "loginwindow.h"
#include "ui_loginwindow.h"

LogInWindow::LogInWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_login,SIGNAL(clicked(bool)),this,SLOT(logIn()));
}

int LogInWindow::logIn()
{
    QByteArray cpath;
    QString Qid=ui->lineEdit_id->text();
    QString Qpassword=ui->lineEdit_password->text();
    cpath=Qid.toLocal8Bit();  //QString to char*
    char* id=cpath.data();
    cpath=Qpassword.toLocal8Bit();
    char* password=cpath.data();
    if(administrartor.logIn(id,password)==1)
    {
        QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("��¼�ɹ�"));
        emit successLogin(administrartor.getAdministrator());
        hide();
    }
    else
    {
        QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("��¼ʧ��"));
        ui->lineEdit_password->clear();
    }
    return 1;
}

LogInWindow::~LogInWindow()
{
    delete ui;
}

administratorStruct LogInWindow::getAdminitrator()
{
    return administrartor.getAdministrator();
}


