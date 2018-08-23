#ifndef USER_H
#define USER_H

#include<cstring>
#include"basisfile.h"
#include"configuration.h"

/*struct ticketStruct
{
    string flightId;//航班id
    string date;//航班时间
    bool status;

};
*/
struct userStruct
{
    char id[32];
    char password[32];
    char name[32];
    friend bool operator ==(const userStruct& a, const userStruct& b);
    userStruct operator =(const userStruct& a);
};

class User:public BasisFile<userStruct>
{
protected:
    userStruct user;//保存登录的用户
public:
    User(string fileName=USER_FILE);
    userStruct find(char* id);//查找并返回该id的用户
    int logIn(char* id, char* password);//登录
    int logOut();//退出登录
    int addUser(userStruct user);//注册
    userStruct getUser();//返回属性user结构体
    void setUserStruct(userStruct);//设置属性user结构体
};

#endif // USER_H
