#ifndef USER_H
#define USER_H

#include<cstring>
#include"basisfile.h"
#include"configuration.h"

/*struct ticketStruct
{
    string flightId;//����id
    string date;//����ʱ��
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
    userStruct user;//�����¼���û�
public:
    User(string fileName=USER_FILE);
    userStruct find(char* id);//���Ҳ����ظ�id���û�
    int logIn(char* id, char* password);//��¼
    int logOut();//�˳���¼
    int addUser(userStruct user);//ע��
    userStruct getUser();//��������user�ṹ��
    void setUserStruct(userStruct);//��������user�ṹ��
};

#endif // USER_H
