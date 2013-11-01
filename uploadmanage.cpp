#include "uploadmanage.h"
#include "ui_uploadmanage.h"

UploadManage::UploadManage(QWidget *parent,QString command ,QString filePath,QString studentList) :
    QWidget(parent),
    ui(new Ui::UploadManage)
{
    ui->setupUi(this);
    uploadingfiles(command,filePath,studentList);
}

UploadManage::~UploadManage()
{
    delete ui;
}





void UploadManage::uploadingfiles(QString command ,QString filePath,QString studentList)
{
    qDebug()<<command<<"command";
    qDebug()<<filePath<<"filePath";
    qDebug()<<studentList<<"studentList";
    cliant = new ServerCliant;
    //QString uploadCommand="Upload ";
    //uploadCommand.append(ui->lineEdit_2->text());
    //uploadCommand.append("Maths/Other/aaaa.xml");
    cliant->test(command,filePath,studentList,"192.168.1.4");

}
