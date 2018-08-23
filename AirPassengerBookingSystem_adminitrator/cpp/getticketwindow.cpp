#include "getticketwindow.h"
#include "ui_getticketwindow.h"

GetTicketWindow::GetTicketWindow(flightStruct flightS, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetTicketWindow),flightS(flightS),page(0)
{
    ui->setupUi(this);

    cout<<"flight:id"<<flightS.id<<flightS.airplane<<flightS.destination<<endl;
    int statusL;
    ticketAll=ticket.getById(flightS.id,flightS.date,sum,statusL);
    cout<<"���Ҷ�����Ϣ��id:"<<flightS.id<<" date:"<<flightS.date<<" sum:"<<flightS.sum<<endl;
    showTicket(0);

    connect(ui->pushButton_nextPage,SIGNAL(clicked()),this,SLOT(nextPage()));
    connect(ui->pushButton_lastPage,SIGNAL(clicked()),this,SLOT(lastPage()));
    connect(ui->pushButton_change,SIGNAL(clicked(bool)),this,SLOT(putFlight()));

}

GetTicketWindow::~GetTicketWindow()
{
    delete ui;
}

int GetTicketWindow::showTicket(int page)
{
    QString text,status;

    if(page>=(sum/5)&&(sum%5)<1)
        ui->commandLinkButton_1->hide();
    else
        ui->commandLinkButton_1->setVisible(1);
    if(ticketAll[page*5].status==0)
        status=QString::fromLocal8Bit("�Ŷ���");
    else
        status=QString::fromLocal8Bit("�Ѷ�Ʊ");
    text=QString::fromLocal8Bit("������")+QString::fromLocal8Bit(ticketAll[page*5].userName)+QString::fromLocal8Bit("   ���֤�ţ�")+QString::fromLocal8Bit(ticketAll[page*5].userId)+"\n"+
            QString::fromLocal8Bit("��λ��")+QString::fromLocal8Bit(ticketAll[page*5].grade)+QString::fromLocal8Bit("    ��Ʊ����")+QString::number(ticketAll[page*5].number)+"            "+status;
    ui->commandLinkButton_1->setText(text);



    if(page>=(sum/5)&&(sum%5)<2)
        ui->commandLinkButton_2->hide();
    else
        ui->commandLinkButton_2->setVisible(1);
    if(ticketAll[page*5].status==0)
        status=QString::fromLocal8Bit("�Ŷ���");
    else
        status=QString::fromLocal8Bit("�Ѷ�Ʊ");
    text=QString::fromLocal8Bit("������")+QString::fromLocal8Bit(ticketAll[page*5+1].userName)+QString::fromLocal8Bit("   ���֤�ţ�")+QString::fromLocal8Bit(ticketAll[page*5+1].userId)+"\n"+
            QString::fromLocal8Bit("��λ��")+QString::fromLocal8Bit(ticketAll[page*5+1].grade)+QString::fromLocal8Bit("    ��Ʊ����")+QString::number(ticketAll[page*5+1].number)+"            "+status;
    ui->commandLinkButton_2->setText(text);



    if(page>=(sum/5)&&(sum%5)<3)
        ui->commandLinkButton_3->hide();
    else
        ui->commandLinkButton_3->setVisible(1);
    if(ticketAll[page*5+3].status==0)
        status=QString::fromLocal8Bit("�Ŷ���");
    else
        status=QString::fromLocal8Bit("�Ѷ�Ʊ");
    text=QString::fromLocal8Bit("������")+QString::fromLocal8Bit(ticketAll[page*5+2].userName)+QString::fromLocal8Bit("   ���֤�ţ�")+QString::fromLocal8Bit(ticketAll[page*5+2].userId)+"\n"+
            QString::fromLocal8Bit("��λ��")+QString::fromLocal8Bit(ticketAll[page*5+2].grade)+QString::fromLocal8Bit("    ��Ʊ����")+QString::number(ticketAll[page*5+2].number)+"            "+status;
    ui->commandLinkButton_3->setText(text);



    if(page>=(sum/5)&&(sum%5)<4)
        ui->commandLinkButton_4->hide();
    else
        ui->commandLinkButton_4->setVisible(1);
    if(ticketAll[page*5].status==0)
        status=QString::fromLocal8Bit("�Ŷ���");
    else
        status=QString::fromLocal8Bit("�Ѷ�Ʊ");
    text=QString::fromLocal8Bit("������")+QString::fromLocal8Bit(ticketAll[page*5+3].userName)+QString::fromLocal8Bit("   ���֤�ţ�")+QString::fromLocal8Bit(ticketAll[page*5+3].userId)+"\n"+
            QString::fromLocal8Bit("��λ��")+QString::fromLocal8Bit(ticketAll[page*5+3].grade)+QString::fromLocal8Bit("    ��Ʊ����")+QString::number(ticketAll[page*5+3].number)+"            "+status;
    ui->commandLinkButton_4->setText(text);



    if(page>=(sum/5)&&(sum%5)<5)
        ui->commandLinkButton_5->hide();
    else
        ui->commandLinkButton_5->setVisible(1);
    if(ticketAll[page*5+5].status==0)
        status=QString::fromLocal8Bit("�Ŷ���");
    else
        status=QString::fromLocal8Bit("�Ѷ�Ʊ");
    text=QString::fromLocal8Bit("������")+QString::fromLocal8Bit(ticketAll[page*5+4].userName)+QString::fromLocal8Bit("   ���֤�ţ�")+QString::fromLocal8Bit(ticketAll[page*5+4].userId)+"\n"+
            QString::fromLocal8Bit("��λ��")+QString::fromLocal8Bit(ticketAll[page*5+4].grade)+QString::fromLocal8Bit("    ��Ʊ����")+QString::number(ticketAll[page*5+4].number)+"            "+status;
    ui->commandLinkButton_5->setText(text);

    return 1;
}

int GetTicketWindow::nextPage()
{
    if((sum/5+(sum%5>0?1:0))<=(page+1))//page��0��ʼ���Լ�һ
        return 0;
    page++;
    return showTicket(page);
}

int GetTicketWindow::lastPage()
{
    if(page<=0)
        return 0;
    page--;
    return showTicket(page);
}

int GetTicketWindow::putFlight()
{
    ChangeWindow changeWindow(flightS);
    changeWindow.setWindowTitle(QString::fromLocal8Bit("�޸ĺ���"));
    connect(&changeWindow,SIGNAL(havePut()),this,SLOT(turnPut()));
    changeWindow.exec();
    return 1;
}

void GetTicketWindow::turnPut()
{
    emit havePut();
}
