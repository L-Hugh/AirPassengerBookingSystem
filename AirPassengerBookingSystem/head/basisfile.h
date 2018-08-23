#ifndef BASISFILE_H
#define BASISFILE_H
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

template<typename T>
class BasisFile
{
protected:
    string fileName;
    fstream* file;
    long pointer;
public:
    BasisFile(string fileName);
    ~BasisFile();
    int postT(T t);//��ĩβ����һ����¼
    int setPointer(long pointer);//���ü�¼��ţ���0��ʼ
    int getT(T &t); //��ȡ��pointer����¼����0��ʼ
    long getAddress(T t);//��ȡ������¼��ţ���0��ʼ
    int putT(T oldT, T newT);//�޸�һ����¼
    int deleteT(T t);//ɾ����¼t
    long getSum();//�����ܼ�¼��
    void closeFile();//�ر��ļ���
};


template<typename T>
BasisFile<T>::BasisFile(string file):fileName(file),pointer(0)
{
    fstream testFile(fileName,ios::in);
    if(!testFile)
        testFile.open(fileName,ios::out);
    testFile.close();
    this->file=new fstream(file,ios::in|ios::out|ios::binary);
}

template<typename T>
BasisFile<T>::~BasisFile()
{
    //delete[] file;
}

template<typename T>
int BasisFile<T>::postT(T t)
{
    file->seekp(0,ios::end);
    file->write((char*)&t,sizeof(T));
    //cout<<"ע����:"<<fileName<<file->tellg()<<endl;
    return 1;
}

template<typename T>
int BasisFile<T>::setPointer(long pointer)
{
    if(pointer>=getSum())
        return 0;
    this->pointer=pointer;
    return 1;
}

template<typename T>
long BasisFile<T>::getSum()
{
    file->seekg(0,ios::end);
    return file->tellg()/sizeof(T);
}

template<typename T>
int BasisFile<T>::getT(T &t)
{
    if(pointer>=getSum())
        return 0;
    file->seekg(pointer*sizeof(T));
    file->read((char*)&t,sizeof(T));
    pointer++;
    return 1;
}

template<typename T>
long BasisFile<T>::getAddress(T t)  //��ȡ�ü�¼����ţ��������򷵻�-1
{
    T tem;
    long sum=getSum();
    long i;//forѭ���������
    file->seekg(0);
    for(i=0;i<sum;i++)  //����Ƚ�
    {
        file->read((char*)&tem,sizeof(T));
        if(t==tem)
            break;
    }
    if(i>=sum)
        return -1;
    else
        return i;
}

template<typename T>
int BasisFile<T>::putT(T oldT, T newT)
{
    long address;
    address=this->getAddress(oldT);
    if(address==-1)
        return 0;
    else
    {
        file->seekp(address*sizeof(T));
        file->write((char*)&newT,sizeof(T));
        return 1;
    }
}


template<typename T>
int BasisFile<T>::deleteT(T t)
{
    int sizeT=sizeof(T);
    long address,size;
    long i;//forѭ���������
    T *allT;//!!!!!!!!!!!!!!!!!!!!!!!!
    size=getSum()-1; //ɾ��һ��T�������
    address=this->getAddress(t);
    if(address==-1)
        return 0;     //�������򷵻�0
    else
    {
        allT=new T[size];//:::::::::::::::::;
        file->seekg(0);
        for(i=0;i<address;i++)
        {
            file->read((char*)(allT+i),sizeT);
        }
        file->seekg((address+1)*sizeT); //������ɾ����T
        for(;i<size;i++)
        {
            file->read((char*)(allT+i),sizeT);
        }
        file->close();
        //for(i=0;i<size;i++)
        //    cout<<allT[i]<<endl;
        file->open(fileName,ios::out|ios::binary); //�Ը���ԭ�ļ��ķ�ʽ���´�
        file->write((char*)allT,sizeT*size);
        file->close();
        file->open(fileName,ios::in|ios::out|ios::binary);//����ͨ��ʽ��
        return 1;
    }
}

template<typename T>
void BasisFile<T>::closeFile()
{
    file->close();
}

#endif // BAISFILE_H
