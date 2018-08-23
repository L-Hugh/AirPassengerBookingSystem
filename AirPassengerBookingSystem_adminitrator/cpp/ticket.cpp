#include "ticket.h"

bool operator ==(ticketStruct& a,ticketStruct& b)
{
    if(strcmp(a.id,b.id)!=0||strcmp(a.date,b.date)!=0||strcmp(a.userId,b.userId)!=0||strcmp(a.userName,b.userName)!=0||strcmp(a.grade,b.grade)!=0||a.number!=b.number||a.status!=b.status)
        return 0;
    else
        return 1;
}
ticketStruct ticketStruct::operator =(ticketStruct& a)
{
    strcpy_s(id,a.id);
    strcpy_s(airplane,a.airplane);
    strcpy_s(destination,a.destination);
    strcpy_s(week,a.week);
    strcpy_s(time,a.time);
    strcpy_s(date,a.date);
    strcpy_s(userId,a.userId);
    strcpy_s(userName,a.userName);
    strcpy_s(grade,a.grade);
    status=a.status;
    number=a.number;
    return a;
}

Ticket::Ticket(string fileName) :BasisFile<ticketStruct>(fileName)
{
}

int Ticket::addTicket(ticketStruct ticket)
{
    setPointer(getSum());//ָ��ָ�����
    return postT(ticket);//flight�ĸı䲻���������
}

ticketStruct* Ticket::getByDestination(char* destination, int& sum, int& status)
{
    sum=0;
    ticketStruct* ticketSum=new ticketStruct[MAX_PASSENGER];
    ticketStruct* ticketP;
    ticketStruct ticket;
    setPointer(0);
    while(getT(ticket))  //�ȰѲ鵽����Ϣ����һ���㹻��Ŀռ䣬��ѯ�������ٰ���Щ��Ϣ�����ʺϵĿռ�
    {
        if(strcmp(ticket.destination,destination)==0)
        {
            if(sum>=MAX_USER_TICKET)//����ռ伴�����
            {
                status=0;
                return ticketSum;
            }
            ticketSum[sum]=ticket;
            sum++;
        }
    }
    ticketP=new ticketStruct[sum];
    for(int i=0;i<sum;i++)
    {
        ticketP[i]=ticketSum[i];
    }
    delete[] ticketSum;
    status=1;
    return ticketP;

}

ticketStruct* Ticket::getByUser(char* userId, int& sum, int& status)
{
    sum=0;
    ticketStruct* ticketSum=new ticketStruct[MAX_PASSENGER];
    ticketStruct* ticketP;
    ticketStruct ticket;
    setPointer(0);
    while(getT(ticket))  //�ȰѲ鵽����Ϣ����һ���㹻��Ŀռ䣬��ѯ�������ٰ���Щ��Ϣ�����ʺϵĿռ�
    {
        if(strcmp(ticket.userId,userId)==0)
        {
            if(sum>=MAX_USER_TICKET)//����ռ伴�����
            {
                status=0;
                return ticketSum;
            }
            ticketSum[sum]=ticket;
            sum++;
        }
    }
    ticketP=new ticketStruct[sum];
    for(int i=0;i<sum;i++)
    {
        ticketP[i]=ticketSum[i];
    }
    delete[] ticketSum;
    status=1;
    return ticketP;

}

ticketStruct* Ticket::getById(char* id, char* date,int& sum,int& status)
{
    sum=0;
    ticketStruct* ticketSum=new ticketStruct[MAX_PASSENGER];
    ticketStruct* ticketP;
    ticketStruct ticket;
    setPointer(0);
    while(getT(ticket))  //�ȰѲ鵽����Ϣ����һ���㹻��Ŀռ䣬��ѯ�������ٰ���Щ��Ϣ�����ʺϵĿռ�
    {
        //cout<<"��ѯһ��"<<sum<<"num:"<<ticket.number<<endl;
        if(strcmp(ticket.id,id)==0&&strcmp(ticket.date,date)==0)
        {
            if(sum>=MAX_PASSENGER)//����ռ伴�����
            {
                status=0;
                return ticketSum;
            }
            ticketSum[sum]=ticket;
            sum++;
        }
    }
    ticketP=new ticketStruct[sum];
    for(int i=0;i<sum;i++)
    {
        ticketP[i]=ticketSum[i];
    }
    delete[] ticketSum;
    status=1;
    //cout<<"fin sum:"<<sum<<endl;
    return ticketP;

}

int Ticket::changeStatus(ticketStruct oldTicket)
{
    ticketStruct newTicket=oldTicket;
    newTicket.status=1;
    return putT(oldTicket,newTicket);
}

int Ticket::deleteTicket(ticketStruct ticket,int fNum,int& remain)
{
    int sum;
    int status;
    //cout<<"ɾ��,status:"<<ticket.status<<endl;
    if(ticket.status==0)
    {
        remain=fNum;
        return deleteT(ticket);
    }
    remain=ticket.number+fNum;
    ticketStruct* ticketAll=getById(ticket.id,ticket.date,sum,status);
    if(status==0)
        return 0;
    for(int i=0;i<sum;i++)
    {
        if(ticketAll[i].status==0&&strcmp(ticketAll[i].grade,ticket.grade)==0&&ticketAll[i].number<=remain)
        {
            if(changeStatus(ticketAll[i])==1)
            {
                remain-=ticketAll[i].number;
            }
            else
                return 0;
        }
        if(remain<=0)
            break;
    }
    return deleteT(ticket);
}
