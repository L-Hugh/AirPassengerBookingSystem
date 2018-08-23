#ifndef FLIGHT_H
#define FLIGHT_H

#include<cstring>
#include"basisfile.h"
#include"configuration.h"

struct flightStruct
{
    char id[16];
    char airplane[16];
    char destination[16];
    char week[16];
    char time[16];
    char date[16];
    int capacity[3];
    int sum[3];

    friend bool operator ==(flightStruct& a, flightStruct& b);
    flightStruct operator =(flightStruct& a);
};
class Flight :public BasisFile<flightStruct>
{
protected:
    flightStruct flight;
public:
    Flight(string file=FLIGHT_FILE);
    int postFlight(flightStruct fight);
    int find(char* id);//查找该元素序号，从0开始
    flightStruct* getById(char* id, int& status);//通过航班号返回航班信息
    flightStruct* getByDestination(char* destination, int& sum, int& status);//通过目的地返回航班信息
    int deleteFlight(char* id);//删除航班
    int putFlight(char* id, flightStruct flight);//修改航班
};

#endif // FLIGHT_H
