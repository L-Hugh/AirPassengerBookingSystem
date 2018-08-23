#include "user.h"
#include<string>

User::User(string fileName):BasisFile<userStruct>(fileName)
{
    strcpy_s(user.id," ");
    strcpy_s(user.name," ");
    strcpy_s(user.password," ");
}

bool operator ==(const userStruct& a, const userStruct& b)
{
    if(strcmp(a.id,b.id)!=0||strcmp(a.name,b.name)!=0||strcmp(a.password,b.password)!=0)
        return 0;
    else
        return 1;
}

userStruct userStruct::operator =(const userStruct &a)
{
    strcpy_s(id,a.id);
    strcpy_s(password,a.password);
    strcpy_s(name,a.name);
    return a;
}

userStruct User::find(char* id)
{
    userStruct tem;
    long sum=getSum();
    long i; //for循环计数
    setPointer(0);
    for(i=0;i<sum;i++)  //逐个比较
    {
        getT(tem);
        if(strcmp(id,tem.id)==0)
            break;
    }
    if(i>=sum)
    {
        strcpy_s(tem.id," ");   //用id等于空格来标记是否查找成功
        strcpy_s(tem.password,"");
        return tem;
    }
    else
        return tem;
}

int User::logIn(char* id, char* password)
{
    userStruct tem;
    tem=find(id);
    if(strcmp(password,"")==0)
        return 0;
    if(strcmp(tem.password,password)==0)
    {
        strcpy_s(tem.password," ");
        user=tem;
        return 1;
    }
    else
        return 0;
}

int User::logOut()
{
    if(strcmp(user.id," ")==0)
        return 0;
    else
    {
        strcpy_s(user.id," ");
        return 1;
    }
}

int User::addUser(userStruct user)
{
    if(strcmp(find(user.id).id," ")!=0)
        return -1;
    else
        return postT(user);
}

userStruct User::getUser()
{
    return user;
}

void User::setUserStruct(userStruct u)
{
    user=u;
}
