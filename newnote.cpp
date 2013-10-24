#include "newnote.h"
#include "ui_newnote.h"

NewNote::NewNote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewNote)
{
    ui->setupUi(this);
    filepath ="D:/dk work/Motarola/Bindu/Administration/GradesAndClassManage/GradesAndClassManage.xml";
    setSubjetToTree();
}

NewNote::~NewNote()
{
    delete ui;
}


void NewNote::setSubjetToTree()
{

    //QTreeWidgetItem *item= new QTreeWidgetItem(ui->tWSelectSubject);
    //item->setText(0,"dfdfdfdfdf");
    //ui->tWSelectSubject->addTopLevelItem(item);




    QFile openConfigFile(filepath);
    if(!openConfigFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }
    else
    {
        QDomDocument document;

        document.setContent(&openConfigFile);
        QDomElement root= document.firstChildElement();

        QDomNodeList grades = root.elementsByTagName("Grade");


        for(int i=0;i<grades.count();i++)
        {

            QDomNode itemNode = grades.at(i);

            if(itemNode.isElement())
            {

                QTreeWidgetItem *grade= new QTreeWidgetItem(ui->tWSelectSubject);
                grade->setText(0,itemNode.toElement().attribute("GradeName"));


                QDomNodeList classList= itemNode.toElement().elementsByTagName("Subject");

                    for(int j=0;j<classList.count();j++)
                    {

                        QDomNode itemNodeClass = classList.at(j);
                        // ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));
                         QTreeWidgetItem *subjectItem= new QTreeWidgetItem(grade);
                         subjectItem->setText(0,itemNodeClass.toElement().attribute("SubjectName"));

                    }




              ui->tWSelectSubject->addTopLevelItem(grade);


            }




       }


   }


}

