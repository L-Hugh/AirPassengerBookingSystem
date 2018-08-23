#include "bookticketwindow.h"
#include "ui_bookticketwindow.h"

BookTicketWindow::BookTicketWindow(userStruct userS,flightStruct flight,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookTicketWindow),userS(userS),flight(flight)
{
    ui->setupUi(this);

    ui->label_1->setText(QString::number(flight.capacity[0]-flight.sum[0]));
    ui->label_2->setText(QString::number(flight.capacity[1]-flight.sum[1]));
    ui->label_3->setText(QString::number(flight.capacity[2]-flight.sum[2]));
    connect(ui->pushButton_book,SIGNAL(clicked(bool)),this,SLOT(book()));
}

BookTicketWindow::~BookTicketWindow()
{
    delete ui;
}

void BookTicketWindow::book()
{
    userStruct temU;
    temU=user.find(userS.id);
    //cout<<userS.id<<"��Ʊ"<<endl;
    if(strcmp(temU.id," ")==0)
    {
        QMessageBox::critical(this,QString::fromLocal8Bit("δ��¼"),QString::fromLocal8Bit("���ȵ�¼"));
        hide();
    }
    else
    {
        int num,grade;
        //QByteArray cpath;
        ticketStruct ticketS;
        num=ui->spinBox->value();
        if(ui->radioButton_1->isChecked())
        {
            grade=0;
            strcpy_s(ticketS.grade,"ͷ�Ȳ�");
            if(flight.capacity[0]-flight.sum[0]<num)
                ticketS.status=0;
            else
                ticketS.status=1;
        }
        else
        if(ui->radioButton_2->isChecked())
        {
            grade=1;
            strcpy_s(ticketS.grade,"�����");
            if(flight.capacity[1]-flight.sum[1]<num)
                ticketS.status=0;
            else
                ticketS.status=1;
        }
        else
        if(ui->radioButton_3->isChecked())
        {
            grade=2;
            strcpy_s(ticketS.grade,"���ò�");
            if(flight.capacity[2]-flight.sum[2]<num)
                ticketS.status=0;
            else
                ticketS.status=1;
        }
        else
        {
            QMessageBox::critical(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("��ѡ����λ����"));
            return;
        }

        ticketS.number=num;
        strcpy_s(ticketS.airplane,flight.airplane);
        strcpy_s(ticketS.date,flight.date);
        strcpy_s(ticketS.destination,flight.destination);
        strcpy_s(ticketS.id,flight.id);
        strcpy_s(ticketS.time,flight.time);
        strcpy_s(ticketS.week,flight.week);
        strcpy_s(ticketS.userId,userS.id);
        strcpy_s(ticketS.userName,userS.name);
        if(ticket.addTicket(ticketS)==1)
        {
            ticket.closeFile();
            if(ticketS.status==1)
            {
                flight.sum[grade]+=num;  //���º�����Ϣ
                Flight flightObj;
                //cout<<"ticketSum:"<<flight.sum[grade]<<endl;
                flightObj.putFlight(flight.id,flight);
                flightObj.closeFile();
                QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("��Ʊ�ɹ�"));
                emit haveBook();
                hide();
            }
            else
            {
                QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("��Ʊ�ɹ�,�����Ŷ�"));
                hide();
            }
        }
        else
        {
            QMessageBox::critical(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("��Ʊʧ��"));
        }
    }
}
