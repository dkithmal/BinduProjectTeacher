#include "homeworktool.h"
#include "ui_homeworktool.h"

HomeWorkTool::HomeWorkTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWorkTool)
{
    ui->setupUi(this);
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
            newHomeWork->show();
            this->close();

        }
        else
        {
            newNote = new NewNote;
            newNote->show();

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
            openHomeWork->show();
            this->close();

        }
        else
        {
            openNote = new OpenNote;
            openNote->show();

        }
    }

}
