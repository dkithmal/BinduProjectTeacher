#include "classmanage.h"
#include "ui_classmanage.h"

ClassManage::ClassManage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassManage)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
      //this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);



    //set icons to buttons
    QPixmap markStudentPapers(":/binduTeacher/new/imgs/markPapers.jpg");
    QIcon markStudentPapersIcon(markStudentPapers);
    ui->pBMarkPapers->setIcon(markStudentPapersIcon);
    QSize pBMarkPapersSize=markStudentPapers.rect().size();
    pBMarkPapersSize.setHeight(pBMarkPapersSize.height()-50);
    pBMarkPapersSize.setWidth(pBMarkPapersSize.width()-50);
    ui->pBMarkPapers->setIconSize(pBMarkPapersSize);

    QPixmap viewStudentProgress(":/binduTeacher/new/imgs/studentProgress.jpg");
    QIcon studentProgressIcon(viewStudentProgress);
    ui->pBStudentProgress->setIcon(studentProgressIcon);
    QSize pBviewStudentSize=viewStudentProgress.rect().size();
    pBviewStudentSize.setHeight(pBviewStudentSize.height()-455);
    pBviewStudentSize.setWidth(pBviewStudentSize.width()-120);
    ui->pBStudentProgress->setIconSize(pBviewStudentSize);

    //set icons to buttons
    QPixmap editStudent(":/binduTeacher/new/imgs/editStudent.jpg");
    QIcon editStudentIcon(editStudent);
    ui->pBEditStudent->setIcon(editStudentIcon);
    QSize pBEditStudentSize=editStudent.rect().size();
    pBEditStudentSize.setHeight(pBEditStudentSize.height()-50);
    pBEditStudentSize.setWidth(pBEditStudentSize.width()-50);
    ui->pBEditStudent->setIconSize(pBEditStudentSize);
}

ClassManage::~ClassManage()
{
    delete ui;
}

void ClassManage::on_pBMarkPapers_clicked()
{
    selectPaperForMark = new SelectPaperForMark;
    selectPaperForMark->setModal(false);
    this->close();
    selectPaperForMark->exec();

}

void ClassManage::on_pBEditStudent_clicked()
{
    selectStuForAddDetails = new SelectStuForAddDetails;
    selectStuForAddDetails->setModal(false);
    this->close();
    selectStuForAddDetails->exec();
}

void ClassManage::on_pBStudentProgress_clicked()
{
    selectStudentForView = new SelectStudentForView;
    selectStudentForView->setModal(false);
    this->close();
    selectStudentForView->exec();
}
