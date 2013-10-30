#include "editnote.h"
#include "ui_editnote.h"

EditNote::EditNote(QWidget *parent,QString filePath) :
    QWidget(parent),
    ui(new Ui::EditNote)
{
    ui->setupUi(this);
    noteFilePath=filePath;
    showExistingContent();
}

EditNote::~EditNote()
{
    delete ui;
}

void EditNote::showExistingContent()
{

    QFile openConfigFile(noteFilePath);
    if(!openConfigFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }
    else
    {
    QTextStream in(&openConfigFile);
    ui->tEText->setPlainText(in.readAll());



    }




}

void EditNote::on_pBSaveAndClose_clicked()
{
    QFile file(noteFilePath);
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
