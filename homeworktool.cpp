#include "homeworktool.h"
#include "ui_homeworktool.h"

HomeWorkTool::HomeWorkTool(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::HomeWorkTool)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

HomeWorkTool::~HomeWorkTool()
{
    delete ui;
}

void HomeWorkTool::on_pBNewHomeWork_clicked()
{
    if(!(ui->rBNewHomeWrok->isChecked()||ui->rBNewShotNote->isChecked()))
    {
         QMessageBox::information(this,"Error","Plese Select Note or Home Work");
    }
    else
    {
        if(ui->rBNewHomeWrok->isChecked())
        {
            newHomeWork = new NewHomeWork;
            newHomeWork->setModal(false);
            this->close();
            newHomeWork->exec();


        }
        else
        {

            newNote = new NewNote;
            newNote->setModal(false);
            this->close();
            newNote->exec();


        }
    }


}

void HomeWorkTool::on_pBOpenExistingHw_clicked()
{
    if(!(ui->rBOpenHomeWork->isChecked()||ui->rBOpenNote->isChecked()))
    {
         QMessageBox::information(this,"Error","Plese Select Note or Home Work");
    }
    else
    {
        if(ui->rBOpenHomeWork->isChecked())
        {
            openHomeWork = new OpenHomeWork;
            openHomeWork->setModal(false);
            this->close();
            openHomeWork->exec();


        }
        else
        {
            openNote = new OpenNote;
            openNote->setModal(false);
            this->close();
            openNote->exec();


        }
    }

}
