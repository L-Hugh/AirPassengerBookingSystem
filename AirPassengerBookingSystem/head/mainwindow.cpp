#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtCore/QObject>
#include <QWidget>
#include<iostream>
#include<QString>
#include<string>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),page(0)
{
    ui->setupUi(this);
    flightAll=new flightStruct[MAX_PAGE];
    for(sum=0;sum<MAX_PAGE;sum++) //读取航班信息
    {
        if(flight.getT(flightAll[sum])<=0)
            break;
    }
    showFlight(0);

    //翻页及搜索按钮的连接
    connect(ui->pushButton_nextPage,SIGNAL(clicked()),this,SLOT(nextPage()));
    connect(ui->pushButton_lastPage,SIGNAL(clicked()),this,SLOT(lastPage()));
    connect(ui->pushButton_find,SIGNAL(clicked()),this,SLOT(searchDestination()));
    connect(ui->pushButton_new,SIGNAL(clicked(bool)),this,SLOT(refreshFlight()));

    //订票的连接
    connect(ui->commandLinkButton_1,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_1()));
    connect(ui->commandLinkButton_2,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_2()));
    connect(ui->commandLinkButton_3,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_3()));
    connect(ui->commandLinkButton_4,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_4()));
    connect(this,SIGNAL(bookTurn(int)),this,SLOT(bookTicket(int)));

    //登录按钮的连接
    connect(ui->pushButton_user,SIGNAL(clicked(bool)),this,SLOT(logIn()));
    connect(&logInWindow,SIGNAL(successLogin(userStruct)),this,SLOT(logInSuccess(userStruct)));
}
int MainWindow::showFlight(int page)
{
    QString text;
    if(page>=(sum/4)&&(sum%4)<1)
        ui->commandLinkButton_1->hide();
    else
        ui->commandLinkButton_1->setVisible(1);
    text=QString::fromLocal8Bit("航班号：")+QString::fromLocal8Bit(flightAll[page*4].id)+QString::fromLocal8Bit("   飞机：")+QString::fromLocal8Bit(flightAll[page*4].airplane)+QString::fromLocal8Bit("    目的地：")+QString::fromLocal8Bit(flightAll[page*4].destination)+"\n"+
            QString::fromLocal8Bit("出发时间：")+flightAll[page*4].date+"    "+QString::fromLocal8Bit(flightAll[page*4].week)+"    "+flightAll[page*4].time+"\n"+
            QString::fromLocal8Bit("头等舱余票：")+QString::number(flightAll[page*4].capacity[0]-flightAll[page*4].sum[0])+QString::fromLocal8Bit("    商务舱余票：")+QString::number(flightAll[page*4].capacity[1]-flightAll[page*4].sum[1])+QString::fromLocal8Bit("    经济舱余票：")+QString::number(flightAll[page*4].capacity[2]-flightAll[page*4].sum[2]);
    ui->commandLinkButton_1->setText(text);


    if(page>=(sum/4)&&(sum%4)<2)
        ui->commandLinkButton_2->hide();
    else
        ui->commandLinkButton_2->setVisible(1);
    text=QString::fromLocal8Bit("航班号：")+QString::fromLocal8Bit(flightAll[page*4+1].id)+QString::fromLocal8Bit("   飞机：")+QString::fromLocal8Bit(flightAll[page*4+1].airplane)+QString::fromLocal8Bit("    目的地：")+QString::fromLocal8Bit(flightAll[page*4+1].destination)+"\n"+
            QString::fromLocal8Bit("出发时间：")+flightAll[page*4+1].date+"    "+QString::fromLocal8Bit(flightAll[page*4+1].week)+"    "+flightAll[page*4+1].time+"\n"+
            QString::fromLocal8Bit("头等舱余票：")+QString::number(flightAll[page*4+1].capacity[0]-flightAll[page*4+1].sum[0])+QString::fromLocal8Bit("    商务舱余票：")+QString::number(flightAll[page*4+1].capacity[1]-flightAll[page*4+1].sum[1])+QString::fromLocal8Bit("    经济舱余票：")+QString::number(flightAll[page*4+1].capacity[2]-flightAll[page*4+1].sum[2]);
    ui->commandLinkButton_2->setText(text);

    if(page>=(sum/4)&&(sum%4)<3)
        ui->commandLinkButton_3->hide();
    else
        ui->commandLinkButton_3->setVisible(1);
    text=QString::fromLocal8Bit("航班号：")+flightAll[page*4+2].id+QString::fromLocal8Bit("   飞机：")+flightAll[page*4+2].airplane+QString::fromLocal8Bit("    目的地：")+QString::fromLocal8Bit(flightAll[page*4+2].destination)+"\n"+
            QString::fromLocal8Bit("出发时间：")+flightAll[page*4+2].date+"    "+QString::fromLocal8Bit(flightAll[page*4+2].week)+"    "+flightAll[page*4+2].time+"\n"+
            QString::fromLocal8Bit("头等舱余票：")+QString::number(flightAll[page*4+2].capacity[0]-flightAll[page*4+2].sum[0])+QString::fromLocal8Bit("    商务舱余票：")+QString::number(flightAll[page*4+2].capacity[1]-flightAll[page*4+2].sum[1])+QString::fromLocal8Bit("    经济舱余票：")+QString::number(flightAll[page*4+2].capacity[2]-flightAll[page*4+2].sum[2]);
    ui->commandLinkButton_3->setText(text);

    if(page>=(sum/4)&&(sum%4)<4)
        ui->commandLinkButton_4->hide();
    else
        ui->commandLinkButton_4->setVisible(1);
    text=QString::fromLocal8Bit("航班号：")+flightAll[page*4+3].id+QString::fromLocal8Bit("   飞机：")+flightAll[page*4+3].airplane+QString::fromLocal8Bit("    目的地：")+QString::fromLocal8Bit(flightAll[page*4+3].destination)+"\n"+
            QString::fromLocal8Bit("出发时间：")+flightAll[page*4+3].date+"    "+QString::fromLocal8Bit(flightAll[page*4+3].week)+"    "+flightAll[page*4+3].time+"\n"+
            QString::fromLocal8Bit("头等舱余票：")+QString::number(flightAll[page*4+3].capacity[0]-flightAll[page*4+3].sum[0])+QString::fromLocal8Bit("    商务舱余票：")+QString::number(flightAll[page*4+3].capacity[1]-flightAll[page*4+3].sum[1])+QString::fromLocal8Bit("    经济舱余票：")+QString::number(flightAll[page*4+3].capacity[2]-flightAll[page*4+3].sum[2]);
    ui->commandLinkButton_4->setText(text);
    return 1;
}

int MainWindow::nextPage()
{
    if((sum/4+(sum%4>0?1:0))<=(page+1))//page从0开始所以加一
        return 0;
    page++;
    return showFlight(page);
}

int MainWindow::lastPage()
{
    if(page<=0)
        return 0;
    page--;
    return showFlight(page);
}

int MainWindow::searchDestination()
{
    int status,fsum;
    flightStruct* p;
    QString destination=ui->lineEdit_1->text();
    QByteArray cpath = destination.toLocal8Bit();
    char* destinationP = cpath.data();
    p=flight.getByDestination(destinationP,fsum,status);
    if(status)
    {
        delete flightAll;
        flightAll=p;
        sum=fsum;
        page=0;
        showFlight(0);
    }
    return status;
}

int MainWindow::bookTicket(int num)
{
    //cout<<"订票："<<num;
    BookTicketWindow bookWindow(user,flightAll[page*4+num-1]);
    bookWindow.setWindowTitle(QString::fromLocal8Bit("订票"));
    connect(&bookWindow,SIGNAL(haveBook()),this,SLOT(refreshFlight()));
    bookWindow.exec();
    return 1;
}

void MainWindow::sentByCommandLinkButton_1()
{
    emit bookTurn(1);
}
void MainWindow::sentByCommandLinkButton_2()
{
    emit bookTurn(2);
}
void MainWindow::sentByCommandLinkButton_3()
{
    emit bookTurn(3);
}
void MainWindow::sentByCommandLinkButton_4()
{
    emit bookTurn(4);
}

void MainWindow::logIn()//登录界面
{
    logInWindow.setWindowTitle(QString::fromLocal8Bit("登录"));
    logInWindow.exec();
}

void MainWindow::logInSuccess(userStruct u)
{
    user=u;
    //cout<<"登录成功"<<u.id<<u.name<<u.password<<endl;
    ui->pushButton_user->setText(QString::fromLocal8Bit("我的订票"));
    connect(ui->pushButton_user,SIGNAL(clicked(bool)),this,SLOT(userInformation()));
    disconnect(ui->pushButton_user,SIGNAL(clicked(bool)),this,SLOT(logIn()));
}

void MainWindow::userInformation()
{
    UserWindow userWindow(user);
    userWindow.setWindowTitle(QString::fromLocal8Bit("我的订票"));
    connect(&userWindow,SIGNAL(haveDis()),this,SLOT(refreshFlight()));
    userWindow.exec();
}

void MainWindow::refreshFlight()
{
    delete[] flightAll;
    flightAll=new flightStruct[MAX_FLIGHT];
    flight.setPointer(0);
    for(sum=0;sum<MAX_PAGE;sum++) //读取航班信息
    {
        if(flight.getT(flightAll[sum])<=0)
            break;
    }
    //cout<<"NewFlifhtSum:"<<sum<<endl;
    showFlight(page);
}

MainWindow::~MainWindow()
{
    delete ui;
}

