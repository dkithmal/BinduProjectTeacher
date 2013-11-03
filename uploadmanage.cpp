#include "uploadmanage.h"
#include "ui_uploadmanage.h"

UploadManage::UploadManage(QDialog *parent,QString command ,QString filePath,QString studentList) :
    QDialog(parent),
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
    int i=0;
    ui->tWUplodingState->setRowCount(studentSplitedList.size());
    foreach (QString student, studentSplitedList)
    {      
        ui->tWUplodingState->setItem(i,0,new QTableWidgetItem(student));
        ui->tWUplodingState->setItem(i,1,new QTableWidgetItem("Pending"));

        i++;
    }


    qDebug()<<command<<"command";
    qDebug()<<filePath<<"filePath";
    qDebug()<<studentList<<"studentList";
    //ayya code

    cliant = new ServerCliant;
    cliant->toExicuteTeacherCommand(command,filePath,studentList,"192.168.1.5");

    connect(cliant, SIGNAL(FileSent(QString)), this, SLOT(OnFileSent(QString)));

}

//ayya code
void UploadManage::OnFileSent(const QString & studentName)
{
    for(int i=0;i<ui->tWUplodingState->rowCount();i++)
    {
        if(ui->tWUplodingState->item(i,0)->text()==studentName)
        {
            ui->tWUplodingState->setItem(i,0,new QTableWidgetItem(studentName));
            ui->tWUplodingState->setItem(i,1,new QTableWidgetItem("Done"));
        }
    }
    //ui->lWRecivedStudents->addItem(studentName);

}



void UploadManage::on_pBUpdateClose_clicked()
{
    this->close();

}
