#include "flight.h"


Flight::Flight(string file):BasisFile<flightStruct>(file)
{
    strcpy_s(flight.id," ");
}


bool operator ==(flightStruct& a, flightStruct& b)
{
    if(strcmp(a.id,b.id)!=0||strcmp(a.airplane,b.airplane)!=0||strcmp(a.destination,b.destination)!=0||strcmp(a.week,b.week)!=0||strcmp(a.time,b.time)!=0||strcmp(a.date,b.date)!=0)
        return 0;
    else
        return 1;
}
flightStruct flightStruct::operator =(flightStruct& a)
{
    strcpy_s(id,a.id);
    strcpy_s(airplane,a.airplane);
    strcpy_s(destination,a.destination);
    strcpy_s(week,a.week);
    strcpy_s(time,a.time);
    strcpy_s(date,a.date);
    for(int i=0;i<3;i++)
    {
        capacity[i]=a.capacity[i];
        sum[i]=a.sum[i];
    }
    return a;
}

int Flight::find(char* id)
{
    int i=0;
    flightStruct flight;
    setPointer(0);
    while(getT(flight))
    {
        if(strcmp(flight.id,id)==0)
            return i;
        i++;
    }
    return -1;
}

int Flight::postFlight(flightStruct fight)
{
    if(find(fight.id)!=-1)
        return 0;
    return postT(fight);
}

flightStruct* Flight::getById(char* id, int& status)
{
    int address=find(id);
    flightStruct* flight=new flightStruct[1];
    if(address>=0)
    {
        setPointer(address);
        status=getT(*flight);
        return flight;
    }
    else
    {
        status=0;
        return flight;
    }
}

flightStruct* Flight::getByDestination(char* destination, int& sum, int& status)
{
    sum=0;//统计查到的记录
    flightStruct flight,*flightSum=new flightStruct[MAX_FLIGHT];
    setPointer(0);
    while(getT(flight))//遍历所有记录
    {
        if(strcmp(flight.destination,destination)==0)//每查到一条符合的记录储存空间加一
        {
            if(sum>=MAX_FLIGHT)//航班数量超出最大缓存数量
            {
                status=0;
                return flightSum;
            }
            flightSum[sum]=flight;
            sum++;
        }
    }
    flightStruct* flightP=new flightStruct[sum];
    for(int i=0;i<sum;i++)
    {
        flightP[i]=flightSum[i];
    }
    delete[] flightSum;
    status=1;
    return flightP;
}

int Flight::deleteFlight(char* id)
{
    flightStruct flight;
    int address=find(id);
    if(address<0)
        return address;
    setPointer(address);
    if(getT(flight)==-1)
        return -1;
    return deleteT(flight);
}

int Flight::putFlight(char *id, flightStruct flight)
{
    flightStruct *old;
    int status;
    old=getById(id,status);
    //cout<<"oldSum:"<<old->sum[0]<<" newSum:"<<flight.sum[0]<<endl;
    //cout<<"oldSum:"<<old->sum[1]<<" newSum:"<<flight.sum[1]<<endl;
    //cout<<"oldSum:"<<old->sum[2]<<" newSum:"<<flight.sum[2]<<endl;
    return putT(*old,flight);
}
