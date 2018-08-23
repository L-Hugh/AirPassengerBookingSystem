#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include<cstring>
#include<string>
#include"basisfile.h"
#include"configuration.h"

struct administratorStruct
{
    char id[32];
    char password[32];
    char name[32];
    int authority;//权限等级
    friend bool operator ==(const administratorStruct& a,const administratorStruct& b);
    administratorStruct operator =(const administratorStruct& a);
};

class Administrator: public BasisFile<administratorStruct>
{
protected:
    administratorStruct administrator;
public:
    Administrator(string fileName=ADMINISTRATOR_FILE);
    administratorStruct find(char* id);
    int logIn(char* id, char* password);
    int logOut();
    int addAministrator(administratorStruct administrator);
    int deleteAministrator(char* id);
    administratorStruct getAdministrator();
};

#endif // ADMINISTRATOR_H
