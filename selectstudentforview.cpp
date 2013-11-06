#include "selectstudentforview.h"
#include "ui_selectstudentforview.h"

SelectStudentForView::SelectStudentForView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectStudentForView)
{
    ui->setupUi(this);
    filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
    basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
    setClassList();
}

SelectStudentForView::~SelectStudentForView()
{
    delete ui;
}

void SelectStudentForView::setClassList()
{
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
                QTreeWidgetItem *grade= new QTreeWidgetItem(ui->tWSelectClass);
                grade->setText(0,itemNode.toElement().attribute("GradeName"));


                QDomNodeList classeList= itemNode.toElement().elementsByTagName("Class");

                    for(int j=0;j<classeList.count();j++)
                    {
                        QDomNode itemNodeClass = classeList.at(j);
                        QTreeWidgetItem *classItem= new QTreeWidgetItem(grade);
                        classItem->setText(0,itemNodeClass.toElement().attribute("ClassName"));



                    }




              ui->tWSelectClass->addTopLevelItem(grade);


            }




       }


   }

}



void SelectStudentForView::on_tWSelectClass_clicked(const QModelIndex &index)
{
    ui->lWStudent->clear();

    if(ui->tWSelectClass->currentIndex().parent().isValid())
    {

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
                    if(itemNode.toElement().attribute("GradeName")==ui->tWSelectClass->currentItem()->parent()->text(0))
                    {
                        QDomNodeList classeList= itemNode.toElement().elementsByTagName("Class");

                            for(int j=0;j<classeList.count();j++)
                            {
                                QDomNode itemNodeClass = classeList.at(j);
                                if(itemNodeClass.toElement().attribute("ClassName")==ui->tWSelectClass->currentItem()->text(0))
                                {
                                    QDomNodeList studentList=itemNodeClass.toElement().elementsByTagName("students");
                                    QDomNode students=studentList.at(0);
                                    QString studentNameList=students.firstChild().nodeValue();
                                    //qDebug()<<studentNameList<<"student NameList";
                                    QStringList studentNameSplitedList=studentNameList.split(",");
                                    foreach (QString studentName, studentNameSplitedList)
                                    {
                                        //QListWidgetItem
                                       ui->lWStudent->addItem(studentName);

                                    }



                                    break;

                                }




                            }
                            break;

                    }


                  //ui->tWSelectClass->addTopLevelItem(grade);


                }




           }


       }
}
}

void SelectStudentForView::on_pBViewStudent_clicked()
{
    int x=0 ;
    if(!ui->lWStudent->currentIndex().isValid())
    {
        QMessageBox::information(this,"Error","Please slect student");
        x=1;

    }
    if(!ui->tWSelectClass->currentIndex().parent().isValid())
    {
        QMessageBox::information(this,"Error","Please slect class");
        x=1;

    }

    if(x==0)
    {
        QString creatingStudentInfoPath=basicPath;
        creatingStudentInfoPath.append("StudentInformation");
        creatingStudentInfoPath.append("/").append(ui->tWSelectClass->currentItem()->parent()->text(0));
        creatingStudentInfoPath.append("/").append(ui->tWSelectClass->currentItem()->text(0));
         creatingStudentInfoPath.append("/").append(ui->lWStudent->currentItem()->text()).append(".xml");

         studentInformation = new StudentInformation(0,ui->lWStudent->currentItem()->text(),ui->tWSelectClass->currentItem()->parent()->text(0),ui->tWSelectClass->currentItem()->text(0),creatingStudentInfoPath);
         studentInformation->setModal(false);
         studentInformation->exec();
    }

}
