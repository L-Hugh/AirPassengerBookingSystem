#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtCore/QObject>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),page(0)
{
    ui->setupUi(this);
    strcpy_s(administrator.id,"");//未登录标记
    flightAll=new flightStruct[MAX_PAGE];
    for(sum=0;sum<MAX_PAGE;sum++) //读取航班信息
    {
        if(flight.getT(flightAll[sum])<=0)
            break;
    }
    showFlight(0);

    //翻页,刷新及搜索按钮的连接
    connect(ui->pushButton_nextPage,SIGNAL(clicked()),this,SLOT(nextPage()));
    connect(ui->pushButton_lastPage,SIGNAL(clicked()),this,SLOT(lastPage()));
    connect(ui->pushButton_find,SIGNAL(clicked()),this,SLOT(searchDestination()));
    connect(ui->pushButton_new,SIGNAL(clicked(bool)),this,SLOT(refreshFlight()));

    //连接
    connect(ui->commandLinkButton_1,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_1()));
    connect(ui->commandLinkButton_2,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_2()));
    connect(ui->commandLinkButton_3,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_3()));
    connect(ui->commandLinkButton_4,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_4()));
    connect(this,SIGNAL(putTurn(int)),this,SLOT(getTicket(int)));
    //connect(this,SIGNAL(putTurn(int)),this,SLOT(putFlight(int)));

    //登录按钮的连接
    connect(ui->pushButton_user,SIGNAL(clicked(bool)),this,SLOT(logIn()));
    connect(&logInWindow,SIGNAL(successLogin(administratorStruct)),this,SLOT(logInSuccess(administratorStruct)));
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
    p=flight.getByDestion(destinationP,fsum,status);
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

int MainWindow::getTicket(int num)
{
    if(strcmp(administrator.id,"")==0)
    {
        QMessageBox::critical(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("请先登录"));
        return 0;
    }
    GetTicketWindow getTicketWindow(flightAll[page*4+num-1]);
    //cout<<"oid fligt id:"<<flightAll[page*4+num-1].id<<endl;
    getTicketWindow.setWindowTitle(QString::fromLocal8Bit("订票信息"));
    connect(&getTicketWindow,SIGNAL(havePut()),this,SLOT(refreshFlight()));
    getTicketWindow.exec();
    return 1;
}

int MainWindow::putFlight(int num)
{
    if(strcmp(administrator.id,"")==0)
    {
        QMessageBox::critical(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("请先登录"));
        return 0;
    }
    ChangeWindow changeWindow(flightAll[page*4+num-1]);
    changeWindow.setWindowTitle(QString::fromLocal8Bit("修改航班"));
    connect(&changeWindow,SIGNAL(havePut()),this,SLOT(refreshFlight()));
    changeWindow.exec();
    return 1;
}


void MainWindow::sentByCommandLinkButton_1()
{
    emit putTurn(1);
}
void MainWindow::sentByCommandLinkButton_2()
{
    emit putTurn(2);
}
void MainWindow::sentByCommandLinkButton_3()
{
    emit putTurn(3);
}
void MainWindow::sentByCommandLinkButton_4()
{
    emit putTurn(4);
}

void MainWindow::logIn()//登录界面
{
    logInWindow.setWindowTitle(QString::fromLocal8Bit("登录"));
    logInWindow.exec();
}

void MainWindow::logInSuccess(administratorStruct a)
{
    administrator=a;
    //cout<<"登录成功"<<u.id<<u.name<<u.password<<endl;
    ui->pushButton_user->setText(QString::fromLocal8Bit("添加航班"));
    connect(ui->pushButton_user,SIGNAL(clicked(bool)),this,SLOT(addFlight()));
    disconnect(ui->pushButton_user,SIGNAL(clicked(bool)),this,SLOT(logIn()));
}

void MainWindow::addFlight()
{
    AddFlightWindow addFlightWindow;
    addFlightWindow.setWindowTitle(QString::fromLocal8Bit("添加航班"));
    connect(&addFlightWindow,SIGNAL(haveAdd()),this,SLOT(refreshFlight()));
    addFlightWindow.exec();
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
