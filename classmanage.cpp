#include "classmanage.h"
#include "ui_classmanage.h"

ClassManage::ClassManage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassManage)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
      //this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
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
