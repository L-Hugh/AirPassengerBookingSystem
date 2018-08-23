#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(userStruct userS, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserWindow),userS(userS),sum(0),page(0)
{
    ui->setupUi(this);


    int statusL;
    ticketAll=ticket.getByUser(userS.id,sum,statusL);
    showFlight(0);

    connect(ui->pushButton_nextPage,SIGNAL(clicked()),this,SLOT(nextPage()));
    connect(ui->pushButton_lastPage,SIGNAL(clicked()),this,SLOT(lastPage()));

    connect(ui->commandLinkButton_1,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_1()));
    connect(ui->commandLinkButton_2,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_2()));
    connect(ui->commandLinkButton_3,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_3()));
    connect(ui->commandLinkButton_4,SIGNAL(clicked()),this,SLOT(sentByCommandLinkButton_4()));
    connect(this,SIGNAL(bookTurn(int)),this,SLOT(bookTicket(int)));
}

UserWindow::~UserWindow()
{
    delete ui;
}
int UserWindow::showFlight(int page)
{
    QString text,status;

    if(page>=(sum/4)&&(sum%4)<1)
        ui->commandLinkButton_1->hide();
    else
        ui->commandLinkButton_1->setVisible(1);
    if(ticketAll[page*4].status==0)
        status=QString::fromLocal8Bit("排队中");
    else
        status=QString::fromLocal8Bit("已订票");
    text=QString::fromLocal8Bit("航班号：")+QString::fromLocal8Bit(ticketAll[page*4].id)+QString::fromLocal8Bit("   飞机：")+QString::fromLocal8Bit(ticketAll[page*4].airplane)+QString::fromLocal8Bit("    目的地：")+QString::fromLocal8Bit(ticketAll[page*4].destination)+"\n"+
            QString::fromLocal8Bit("出发时间：")+ticketAll[page*4].date+"    "+QString::fromLocal8Bit(ticketAll[page*4].week)+"    "+ticketAll[page*4].time+"\n"+
            QString::fromLocal8Bit("座位：")+QString::fromLocal8Bit(ticketAll[page*4].grade)+QString::fromLocal8Bit("    订票数：")+QString::number(ticketAll[page*4].number)+"            "+status;
    ui->commandLinkButton_1->setText(text);


    if(page>=(sum/4)&&(sum%4)<2)
        ui->commandLinkButton_2->hide();
    else
        ui->commandLinkButton_2->setVisible(1);
    if(ticketAll[page*4+1].status==0)
        status=QString::fromLocal8Bit("排队中");
    else
        status=QString::fromLocal8Bit("已订票");
    text=QString::fromLocal8Bit("航班号：")+QString::fromLocal8Bit(ticketAll[page*4+1].id)+QString::fromLocal8Bit("   飞机：")+QString::fromLocal8Bit(ticketAll[page*4+1].airplane)+QString::fromLocal8Bit("    目的地：")+QString::fromLocal8Bit(ticketAll[page*4+1].destination)+"\n"+
            QString::fromLocal8Bit("出发时间：")+ticketAll[page*4+1].date+"    "+QString::fromLocal8Bit(ticketAll[page*4+1].week)+"    "+ticketAll[page*4+1].time+"\n"+
            QString::fromLocal8Bit("座位：")+QString::fromLocal8Bit(ticketAll[page*4+1].grade)+QString::fromLocal8Bit("    订票数：")+QString::number(ticketAll[page*4+1].number)+"            "+status;
    ui->commandLinkButton_2->setText(text);

    if(page>=(sum/4)&&(sum%4)<3)
        ui->commandLinkButton_3->hide();
    else
        ui->commandLinkButton_3->setVisible(1);
    if(ticketAll[page*4+2].status==0)
        status=QString::fromLocal8Bit("排队中");
    else
        status=QString::fromLocal8Bit("已订票");
    text=QString::fromLocal8Bit("航班号：")+ticketAll[page*4+2].id+QString::fromLocal8Bit("   飞机：")+ticketAll[page*4+2].airplane+QString::fromLocal8Bit("    目的地：")+QString::fromLocal8Bit(ticketAll[page*4+2].destination)+"\n"+
            QString::fromLocal8Bit("出发时间：")+ticketAll[page*4+2].date+"    "+QString::fromLocal8Bit(ticketAll[page*4+2].week)+"    "+ticketAll[page*4+2].time+"\n"+
            QString::fromLocal8Bit("座位：")+QString::fromLocal8Bit(ticketAll[page*4+2].grade)+QString::fromLocal8Bit("    订票数：")+QString::number(ticketAll[page*4+2].number)+"            "+status;
    ui->commandLinkButton_3->setText(text);

    if(page>=(sum/4)&&(sum%4)<4)
        ui->commandLinkButton_4->hide();
    else
        ui->commandLinkButton_4->setVisible(1);
    if(ticketAll[page*4+3].status==0)
        status=QString::fromLocal8Bit("排队中");
    else
        status=QString::fromLocal8Bit("已订票");
    text=QString::fromLocal8Bit("航班号：")+ticketAll[page*4+3].id+QString::fromLocal8Bit("   飞机：")+ticketAll[page*4+3].airplane+QString::fromLocal8Bit("    目的地：")+QString::fromLocal8Bit(ticketAll[page*4+3].destination)+"\n"+
            QString::fromLocal8Bit("出发时间：")+ticketAll[page*4+3].date+"    "+QString::fromLocal8Bit(ticketAll[page*4+3].week)+"    "+ticketAll[page*4+3].time+"\n"+
            QString::fromLocal8Bit("座位：")+QString::fromLocal8Bit(ticketAll[page*4+3].grade)+QString::fromLocal8Bit("    订票数：")+QString::number(ticketAll[page*4+3].number)+"            "+status;
    ui->commandLinkButton_4->setText(text);
    return 1;
}

int UserWindow::nextPage()
{
    if((sum/4+(sum%4>0?1:0))<=(page+1))//page从0开始所以加一
        return 0;
    page++;
    return showFlight(page);
}

int UserWindow::lastPage()
{
    if(page<=0)
        return 0;
    page--;
    return showFlight(page);
}

int UserWindow::bookTicket(int num)
{
    //cout<<"退票："<<num<<endl;
    //BookTicketWindow bookWindow(user,flightAll[page*4+num-1]);
    //bookWindow.setWindowTitle(QString::fromLocal8Bit("订票"));
    //bookWindow.exec();
    if (QMessageBox::Yes == QMessageBox::question(this,QString::fromLocal8Bit("退票"),QString::fromLocal8Bit("是否退票？"),QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes))
    {
        int remain;
        int status;
        int grade;
        flightStruct* flightP;
        if(strcmp(ticketAll[page*4+num-1].grade,"头等舱")==0)
            grade=0;
        else if(strcmp(ticketAll[page*4+num-1].grade,"商务舱")==0)
            grade=1;
        else if(strcmp(ticketAll[page*4+num-1].grade,"经济舱")==0)
            grade=2;
        else
        {
            cout<<"it is no a suit grade"<<endl;
            grade=3;
        }
        Flight flight;
        flightP=flight.getById(ticketAll[page*4+num-1].id,status);
        int fSum=flightP->capacity[grade]-flightP->sum[grade];
        if(ticket.deleteTicket(ticketAll[page*4+num-1],fSum,remain)==1)
        {
            flightP->sum[grade]=flightP->capacity[grade]-remain;
            //cout<<"remain:"<<remain<<" sum:"<<flightP->sum[grade]<<endl;
            flight.putFlight(ticketAll[page*4+num-1].id,*flightP);
            flight.closeFile();

            QMessageBox::about(this,QString::fromLocal8Bit(""),QString::fromLocal8Bit("退票成功"));

            emit haveDis();
        }
        else
        {
            QMessageBox::about(this,QString::fromLocal8Bit(""),QString::fromLocal8Bit("退票失败"));
        }
        ticketAll=ticket.getByUser(userS.id,sum,status);
        showFlight(page);
    }
    return 1;
}

void UserWindow::sentByCommandLinkButton_1()
{
    emit bookTurn(1);
}
void UserWindow::sentByCommandLinkButton_2()
{
    emit bookTurn(2);
}
void UserWindow::sentByCommandLinkButton_3()
{
    emit bookTurn(3);
}
void UserWindow::sentByCommandLinkButton_4()
{
    emit bookTurn(4);
}

