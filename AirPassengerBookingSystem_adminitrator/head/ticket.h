#ifndef TICKET_H
#define TICKET_H

#include<cstring>
#include"basisfile.h"
#include"configuration.h"

struct ticketStruct
{
    char id[16];
    char airplane[16];
    char destination[16];
    char week[16];
    char time[16];
    char date[16];
    char userId[32];
    char userName[32];
    char grade[16];
    int status;
    int number;

    friend bool operator ==(ticketStruct& a,ticketStruct& b);
    ticketStruct operator =(ticketStruct& a);
};

class Ticket :public BasisFile<ticketStruct>
{
protected:

public:
    Ticket(string file=TICKET_FILE);
    int addTicket(ticketStruct ticket);
    int deleteTicket(ticketStruct ticket,int fSum,int& remain);
    ticketStruct* getByDestination(char* destination,int& sum, int& status);
    ticketStruct* getByUser(char* userId,int& sum, int& status);
    ticketStruct* getById(char* id,char* date, int& sum,int& status);
    int changeStatus(ticketStruct ticket);//改变一个订单的排队状态
};

#endif // TICKET_H
