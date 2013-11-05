#include "papersummary.h"
#include "ui_papersummary.h"

Papersummary::Papersummary(QWidget *parent,QString filepath) :
    QDialog(parent),
    ui(new Ui::Papersummary)
{
    ui->setupUi(this);
    paperFilepath=filepath;
    createPaperSummary();

}

Papersummary::~Papersummary()
{
    delete ui;
}


void Papersummary::createPaperSummary()
{
    QString paperXmlFilePath=paperFilepath;
    paperXmlFilePath.append("/");
    paperXmlFilePath.append("paper.xml");

    //qDebug()<<paperXmlFilePath<<"fddfdfdfdfd";



    QFile openPaperXml(paperXmlFilePath);
    if(!openPaperXml.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";
        QMessageBox::information(this,"Error","Student Answer Papers Not Available");
        //this->close();

    }
    else
    {
        if(openPaperXml.size()==0)
        {
            QMessageBox::information(this,"Error","Student Answer Papers Not Available");
            this->close();

        }
        else
        {
            QDomDocument document;

            document.setContent(&openPaperXml);
            QDomElement root= document.firstChildElement();

            QDomNodeList header = root.elementsByTagName("Header");


            //set peper name
            ui->lPaperName->setText( header.at(0).toElement().attribute("PaperName"));

            //set paper type
            ui->lPaperType->setText( header.at(0).toElement().attribute("type"));

            //
            ui->lGrade->setText( header.at(0).toElement().attribute("Grade"));

            //
            ui->lClass->setText( header.at(0).toElement().attribute("class"));

            QDomNodeList studentList= root.elementsByTagName("student");

            for(int i=0;i<studentList.count();i++)
            {
                ui->tWStudentPaperSummery->setRowCount(studentList.count());
                QDomNode itemNodestudent = studentList.at(i);

                //QTableWidgetItem* item= new QTableWidgetItem(itemNodestudent.toElement().attribute("StudentName"));

                 ui->tWStudentPaperSummery->setItem(i,0,new QTableWidgetItem(itemNodestudent.toElement().attribute("StudentName")));
                 ui->tWStudentPaperSummery->setItem(i,1,new QTableWidgetItem(itemNodestudent.toElement().attribute("MarkState")));
                 ui->tWStudentPaperSummery->setItem(i,2,new QTableWidgetItem(itemNodestudent.toElement().attribute("Marks")));
                 qDebug()<<itemNodestudent.toElement().attribute("StudentName")<<"fddfdfdfdfd";

            }





        }


   }



}

void Papersummary::on_tWStudentPaperSummery_doubleClicked(const QModelIndex &index)
{
    if( ui->tWStudentPaperSummery->currentItem()->text()=="NotMark"||"Marked")
    {
        QString createStudentAnswerPath=paperFilepath;
        createStudentAnswerPath.append("/");
        createStudentAnswerPath.append(ui->lPaperName->text());
        createStudentAnswerPath.append("-");
        QString studentName=ui->tWStudentPaperSummery->item(ui->tWStudentPaperSummery->currentRow(),0)->text();
        createStudentAnswerPath.append(studentName);
        createStudentAnswerPath.append(".xml");

        markingPapers= new MarkingPapers(0,createStudentAnswerPath);
        markingPapers->setModal(false);
        markingPapers->exec();

        createPaperSummary();

       // qDebug()<<createStudentAnswerPath<<"fdffffffffffffffffffff";

       // QMessageBox::information(this,"Error","Student Answer Papers Not Available");

    }


}
