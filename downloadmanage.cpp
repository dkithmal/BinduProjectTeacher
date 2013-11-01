#include "downloadmanage.h"
#include "ui_downloadmanage.h"

DownloadManage::DownloadManage(QWidget *parent,QString command ,QString filePath,QString studentList) :
    QWidget(parent),
    ui(new Ui::DownloadManage)
{
    ui->setupUi(this);
    downloadingfiles(command,filePath,studentList);
}

DownloadManage::~DownloadManage()
{
    delete ui;
}


void DownloadManage::downloadingfiles(QString command ,QString filePath,QString studentList)
{
    qDebug()<<command<<"command";
    qDebug()<<filePath<<"filePath";
    qDebug()<<studentList<<"studentList";
    cliant = new ServerCliant;
    cliant->test(command,filePath,studentList,"192.168.1.4");

}

