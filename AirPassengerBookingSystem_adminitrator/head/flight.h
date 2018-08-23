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
    int find(char* id);//���Ҹ�Ԫ����ţ���0��ʼ
    flightStruct* getById(char* id, int& status);//ͨ������ŷ��غ�����Ϣ
    flightStruct* getByDestion(char* destination, int& sum, int& status);//ͨ��Ŀ�ĵط��غ�����Ϣ
    int deleteFlight(char* id);//ɾ������
    int putFlight(char* id, flightStruct flight);//�޸ĺ���
};

#endif // FLIGHT_H
