#include "mainwindow.h"
#include "userwindow.h"
#include "loginwindow.h"
#include "registerwindow.h"
#include "ui_mainwindow.h"
#include "ui_userwindow.h"
#include "ui_loginwindow.h"
#include "ui_registerwindow.h"
#include <QApplication>
#include <QPushButton>

#include<iostream>
#include<cstring>
#include"basisfile.h"
#include"user.h"
#include"flight.h"
#include"administrator.h"
#include"ticket.h"

using namespace std;


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString::fromLocal8Bit("∫Ωø’øÕ‘À∂©∆±œµÕ≥"));
    w.show();
    //UserWindow u;
    //u.show();
    //LogInWindow l;
    //l.show();
    //RegisterWindow r;
    //r.show();



    return a.exec();




    /*
    //ticket≤‚ ‘
    Ticket t("testticket.dat");
    ticketStruct t1,t2,t3,*t4;
    strcpy_s(t1.id,"M2");
    strcpy_s(t1.airplane,"∫‰-66");
    strcpy_s(t1.destination,"ƒ⁄√…π≈2");
    strcpy_s(t1.week,"Monday");
    strcpy_s(t1.time,"23:00");
    strcpy_s(t1.date,"2018-06-25");
    strcpy_s(t1.userId,"5");
    strcpy_s(t1.userName,"»ÙπÈ2");
    strcpy_s(t1.grade,"…ÃŒÒ≤’");
    t1.status=0;
    t1.number=3;
    cout<<"add:"<<t.addTicket(t1)<<endl;
    //int remain;
    //t.setPointer(6);
    //cout<<"getTToDelete:"<<t.getT(t3)<<endl;
    //cout<<"delete:"<<t.deleteTicket(t3,remain);
    //cout<<" remain:"<<remain<<endl;
    //cout<<"change:"<<t.changeStatus(t1)<<endl;
    for(int u=0;u<t.getSum();u++)
    {
        t.setPointer(u);
        cout<<"getT:"<<t.getT(t2)<<endl;
        cout<<t2.id<<" "<<t2.airplane<<" "<<t2.destination<<" "<<t2.week<<" "<<t2.time<<" "<<t2.date<<" "<<t2.userId<<" "<<t2.userName<<" "<<t2.grade<<" "<<t2.status<<" "<<t2.number<<endl;
    }
    cout<<"-----------------find:----------"<<endl;
    int sum=0,status=0;
    t4=t.getByDestination("ƒ⁄√…π≈",sum,status);
    cout<<"sum:"<<sum<<" status"<<status<<endl;
    for(int u=0;u<sum;u++)
    {
        //t.setPointer(u);
        //cout<<"getT:"<<t.getT(t2)<<endl;
        t2=t4[u];
        cout<<t2.id<<" "<<t2.airplane<<" "<<t2.destination<<" "<<t2.week<<" "<<t2.time<<" "<<t2.date<<" "<<t2.userId<<" "<<t2.userName<<" "<<t2.grade<<" "<<t2.status<<" "<<t2.number<<endl;
    }
    */





    /*
    //flight≤‚ ‘
    Flight f("flight.dat");
    flightStruct f1,f2;
    strcpy_s(f1.id,"CZ4845");
    strcpy_s(f1.airplane,"B-1621");
    strcpy_s(f1.destination,"ƒ⁄√…π≈");
    strcpy_s(f1.week,"Sunday");
    strcpy_s(f1.time,"23:00");
    strcpy_s(f1.date,"2018-07-8");
    f1.capacity[0]=50;
    f1.capacity[1]=50;
    f1.capacity[2]=50;
    f1.sum[0]=0;
    f1.sum[1]=0;
    f1.sum[2]=0;
    cout<<"post:"<<f.postFlight(f1)<<endl;
    f.setPointer(0);
    cout<<"getT:"<<f.getT(f2)<<endl;
    cout<<f2.id<<" "<<f2.airplane<<" "<<f2.destination<<" "<<f2.week<<" "<<f2.time<<" "<<f2.date<<" "<<endl;
    cout<<"find:"<<f.find("MA1-6")<<endl;
    flightStruct* f3;
    int status;
    f3=f.getById("MA1-6",status);
    cout<<"f3:"<<f3->id<<" "<<status<<endl;
    int num;
    f3=f.getByDestion("ƒ⁄√…π≈",num,status);
    cout<<"f3ƒ⁄√…π≈:"<<f3[0].id<<" "<<status<<"num:"<<num<<endl;
    cout<<"f3ƒ⁄√…π≈:"<<f3[1].id<<" "<<status<<endl;
    cout<<"f3ƒ⁄√…π≈:"<<f3[2].id<<" "<<status<<endl;
    cout<<"delete:"<<f.deleteFlight("MA1-3")<<endl;
    cout<<"getSum:"<<f.getSum()<<endl;
    //f.file->close();
    //f.file->open("testflight");
    f.file->seekg(0,ios::end);
    cout<<"end:"<<f.file->tellg()<<endl;
    f.setPointer(0);
    cout<<"getT:"<<f.getT(f2)<<endl;
    cout<<f2.id<<" "<<f2.airplane<<" "<<f2.destination<<" "<<f2.week<<" "<<f2.time<<" "<<f2.date<<" "<<endl;
    f.setPointer(1);
    cout<<"getT:"<<f.getT(f2)<<endl;
    cout<<f2.id<<" "<<f2.airplane<<" "<<f2.destination<<" "<<f2.week<<" "<<f2.time<<" "<<f2.date<<" "<<endl;
    cout<<"put:"<<f.putFlight("MA1-1",f1)<<endl;
    f.setPointer(0);
    cout<<"getT:"<<f.getT(f2)<<endl;
    cout<<f2.id<<" "<<f2.airplane<<" "<<f2.destination<<" "<<f2.week<<" "<<f2.time<<" "<<f2.date<<" "<<endl;
    */



    //administrator≤‚ ‘
    /*
    Administrator obj("testad.dat");
    administratorStruct a1,a2;
    strcpy_s(a1.id,"6");
    strcpy_s(a1.password,"123456");
    strcpy_s(a1.name,"em");
    a1.authority=2;
    cout<<"add:"<<obj.addAministrator(a1)<<endl;
    obj.setPointer(4);
    cout<<"getT:"<<obj.getT(a2)<<endl;
    cout<<a2.id<<" "<<a2.name<<" "<<a2.password<<" "<<a2.authority<<endl;
    cout<<"login:"<<obj.logIn("1","123456")<<endl;
    a2=obj.getAdministrator();
    cout<<a2.id<<" "<<a2.name<<" "<<a2.password<<" "<<a2.authority<<endl;
    //cout<<"logout:"<<obj.logOut()<<endl;
    cout<<"delete:"<<obj.deleteAministrator("30")<<endl;
    obj.setPointer(1);
    cout<<"getT1:"<<obj.getT(a2)<<endl;
    cout<<a2.id<<" "<<a2.name<<" "<<a2.password<<" "<<a2.authority<<endl;
    obj.setPointer(4);
    cout<<"getT2:"<<obj.getT(a2)<<endl;
    cout<<a2.id<<" "<<a2.name<<" "<<a2.password<<" "<<a2.authority<<endl;
    */




    /*
    //user≤‚ ‘
    User user;
    userStruct u1,u2;
    strcpy_s(u1.id,"1");
    strcpy_s(u1.name,"»ÙπÈ");
    strcpy_s(u1.password,"999999");
    cout<<"postT:"<<user.addUser(u1)<<endl;
    u2=user.find("4");
    cout<<"login:"<<user.logIn("5","999999")<<endl;
    //u2=user.getUser();
    //user.setPointer(5);
    //int stutes=user.getT(u2);
    //cout<<"getT:"<<stutes<<endl;
    //cout<<u2.id<<" "<<u2.name<<" "<<u2.password<<endl;
    //cout<<user.user.id<<" "<<user.user.name<<" "<<user.user.password<<endl;
    //cout<<"logout:"<<user.logOut()<<endl;
    */



    //BasisFile≤‚ ‘
    //int a123;
    //BasisFile<int> file("test.dat");
    //file.postT(400);
    //cout<<file.putT(200,201);
    //file.deleteT(200);
    //file.setPointer(0);
    //file.getT(a123);
    //cout<<"a:"<<a123<<endl;
    //file.file->seekg(0,ios::end);
    //cout<<file.file->tellg();


}
