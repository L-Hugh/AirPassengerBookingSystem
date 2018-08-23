#include "loginwindow.h"
#include "ui_loginwindow.h"

LogInWindow::LogInWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_login,SIGNAL(clicked(bool)),this,SLOT(logIn()));
    connect(ui->pushButton_register,SIGNAL(clicked(bool)),this,SLOT(registerUser()));
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
    if(user.logIn(id,password)==1)
    {
        QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("µÇÂ¼³É¹¦"));
        emit successLogin(user.getUser());
        hide();
    }
    else
    {
        QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("µÇÂ¼Ê§°Ü"));
        ui->lineEdit_password->clear();
    }
    return 1;
}

LogInWindow::~LogInWindow()
{
    delete ui;
}

userStruct LogInWindow::getUser()
{
    return user.getUser();
}


void LogInWindow::registerUser()
{
    RegisterWindow rw;
    rw.setWindowTitle(QString::fromLocal8Bit("×¢²á"));
    rw.exec();
}
