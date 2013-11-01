#include "newnotecreating.h"
#include "ui_newnotecreating.h"

NewNoteCreating::NewNoteCreating(QWidget *parent,QString filePath) :
    QWidget(parent),
    ui(new Ui::NewNoteCreating)
{
    ui->setupUi(this);
     noteCrationPath=filePath;
}

NewNoteCreating::~NewNoteCreating()
{
    delete ui;
}

void NewNoteCreating::on_pBSaveAndClose_clicked()
{
    QFile file(noteCrationPath);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {

    }
    else
    {

     QTextStream out(&file);
     out << ui->tEText->toPlainText();
    }
    this->close();

}