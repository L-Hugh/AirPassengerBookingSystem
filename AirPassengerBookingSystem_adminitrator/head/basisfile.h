#ifndef BASISFILE_H
#define BASISFILE_H
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

template<typename T>
class BasisFile
{
public:
    string fileName;
    fstream* file;
    long pointer;
public:
    BasisFile(string fileName);
    ~BasisFile();
    int postT(T t);//在末尾增加一条记录
    int setPointer(long pointer);//设置记录序号，从0开始
    int getT(T &t); //读取第pointer条记录，从0开始
    long getAddress(T t);//获取该条记录序号，从0开始
    int putT(T oldT, T newT);//修改一条记录
    int deleteT(T t);//删除记录t
    long getSum();//返回总记录数
    void closeFile();//关闭文件流
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
    //cout<<"注册中:"<<fileName<<file->tellg()<<endl;
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
long BasisFile<T>::getAddress(T t)  //获取该记录的序号，不存在则返回-1
{
    T tem;
    long sum=getSum();
    long i;//for循环计数标记
    file->seekg(0);
    for(i=0;i<sum;i++)  //逐个比较
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
    long i;//for循环计数标记
    T *allT;//!!!!!!!!!!!!!!!!!!!!!!!!
    size=getSum()-1; //删除一个T后的数量
    address=this->getAddress(t);
    if(address==-1)
        return 0;     //不存在则返回0
    else
    {
        allT=new T[size];//:::::::::::::::::;
        file->seekg(0);
        for(i=0;i<address;i++)
        {
            file->read((char*)(allT+i),sizeT);
        }
        file->seekg((address+1)*sizeT); //跳过被删除的T
        for(;i<size;i++)
        {
            file->read((char*)(allT+i),sizeT);
        }
        file->close();
        //for(i=0;i<size;i++)
        //    cout<<allT[i]<<endl;
        file->open(fileName,ios::out|ios::binary); //以覆盖原文件的方式重新打开
        file->write((char*)allT,sizeT*size);
        file->close();
        file->open(fileName,ios::in|ios::out|ios::binary);//以普通形式打开
        return 1;
    }
}

template<typename T>
void BasisFile<T>::closeFile()
{
    file->close();
}

#endif // BAISFILE_H
