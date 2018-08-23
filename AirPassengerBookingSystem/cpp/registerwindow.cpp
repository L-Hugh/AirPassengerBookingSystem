#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_register,SIGNAL(clicked(bool)),this,SLOT(registerUser()));
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::registerUser()
{
    User user;
    QByteArray cpath;
    QString Qid=ui->lineEdit_id->text();
    QString Qpassword=ui->lineEdit_password->text();
    QString Qname=ui->lineEdit_name->text();
    cpath=Qid.toLocal8Bit();  //QString to char*
    char* id=cpath.data();
    cpath=Qpassword.toLocal8Bit();
    char* password=cpath.data();
    cpath=Qname.toLocal8Bit();
    char* name=cpath.data();
    userStruct u;
    strcpy_s(u.id,id);
    strcpy_s(u.name,name);
    strcpy_s(u.password,password);
    int status=user.addUser(u);
    user.closeFile();//���������ִ���
    if(status==1)
    {
        QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("ע��ɹ�"));
        hide();
    }
    else if(status==-1)
        QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("�����֤�Ѿ�ע��"));
    else
        QMessageBox::about(this,QString::fromLocal8Bit(" "),QString::fromLocal8Bit("ע��ʧ��,����ϵ����Ա"));

}
