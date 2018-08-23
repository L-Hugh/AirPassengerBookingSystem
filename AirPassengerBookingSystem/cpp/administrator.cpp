#include "administrator.h"

Administrator::Administrator(string fileName):BasisFile<administratorStruct>(fileName)
{
    strcpy_s(administrator.id," ");
    strcpy_s(administrator.password," ");
    strcpy_s(administrator.name," ");
    administrator.authority=0;
}

bool operator ==(const administratorStruct& a, const administratorStruct& b)
{
    if(strcmp(a.id,b.id)!=0||strcmp(a.name,b.name)!=0||a.authority!=b.authority||strcmp(a.password,b.password)!=0)
        return 0;
    else
        return 1;
}

administratorStruct administratorStruct::operator =(const administratorStruct& a)
{
    strcpy_s(id,a.id);
    strcpy_s(password,a.password);
    strcpy_s(name,a.name);
    authority=a.authority;
    return a;
}

administratorStruct Administrator::find(char* id)
{
    administratorStruct tem;
    long sum=getSum();
    long i; //forѭ������
    setPointer(0);
    for(i=0;i<sum;i++)  //����Ƚ�
    {
        getT(tem);
        if(strcmp(id,tem.id)==0)
            break;
    }
    if(i>=sum)
    {
        strcpy_s(tem.id," ");   //��id���ڿո�������Ƿ���ҳɹ�
        return tem;
    }
    else
        return tem;
}


int Administrator::logIn(char* id, char* password)
{
    administratorStruct tem;
    tem=find(id);
    if(strcmp(password,tem.password)==0)
    {
        strcpy_s(tem.password," ");
        administrator=tem;
        return 1;
    }
    else
        return 0;
}

int Administrator::logOut()
{
    if(strcmp(administrator.id," ")==0)
        return 0;
    else
    {
        strcpy_s(administrator.id," ");
        return 1;
    }
}

int Administrator::addAministrator(administratorStruct administrator)
{
    //if(!strcmp(this->administrator.id," "))
    //    return 0;
    //if(this->administrator.authority!=1)  //û��Ȩ����ӹ���Ա
    //    return -1;

    if(strcmp(find(administrator.id).id," ")!=0)
        return 0;
    else
        return postT(administrator);
}

int Administrator::deleteAministrator(char* id)
{
    administratorStruct administrator;
    administrator=find(id);
    if(strcmp(administrator.id," ")==0)//����Ա������
        return 0;
    if(strcmp(this->administrator.id," ")==0)//û�е�¼
        return -2;
    if(this->administrator.authority!=1)  //û��Ȩ��ɾ������Ա
        return -1;
    return deleteT(administrator);
}

administratorStruct Administrator::getAdministrator()
{
    return administrator;
}
