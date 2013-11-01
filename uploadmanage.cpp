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
    QStringList studentSplitedList=studentList.split(",");
    foreach (QString student, studentSplitedList)
    {
       ui->lWAllStudents->addItem(student);
    }


    qDebug()<<command<<"command";
    qDebug()<<filePath<<"filePath";
    qDebug()<<studentList<<"studentList";
    //ayya code

    cliant = new ServerCliant;
    cliant->toExicuteTeacherCommand(command,filePath,studentList,"192.168.1.4");

    connect(cliant, SIGNAL(FileSent(QString)), this, SLOT(OnFileSent(QString)));

}

//ayya code
void UploadManage::OnFileSent(const QString & studentName)
{
    ui->lWRecivedStudents->addItem(studentName);

}
