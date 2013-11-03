#include "selectpaperformark.h"
#include "ui_selectpaperformark.h"

SelectPaperForMark::SelectPaperForMark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectPaperForMark)
{
    ui->setupUi(this);
        filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
         basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
    setSubjectToTree();
}

SelectPaperForMark::~SelectPaperForMark()
{
    delete ui;
}


void SelectPaperForMark::setSubjectToTree()
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
                QTreeWidgetItem *grade= new QTreeWidgetItem(ui->tWSelectSubject);
                grade->setText(0,itemNode.toElement().attribute("GradeName"));

                QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");

                for(int j=0;j<classList.count();j++)
                {
                    QDomNode itemNodeClass = classList.at(j);
                    QTreeWidgetItem *classItem= new QTreeWidgetItem(grade);
                    classItem->setText(0,itemNodeClass.toElement().attribute("ClassName"));



                   QDomNodeList subjecList= itemNode.toElement().elementsByTagName("Subject");

                    for(int j=0;j<subjecList.count();j++)
                    {

                    QDomNode itemNodeSubject = subjecList.at(j);
                     // ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));
                     QTreeWidgetItem *subjectItem= new QTreeWidgetItem(classItem);
                    subjectItem->setText(0,itemNodeSubject.toElement().attribute("SubjectName"));
                    }

                }




//                QDomNodeList subjecList= itemNode.toElement().elementsByTagName("Subject");

//                    for(int j=0;j<subjecList.count();j++)
//                    {

//                        QDomNode itemNodeSubject = subjecList.at(j);
//                        // ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));
//                         QTreeWidgetItem *subjectItem= new QTreeWidgetItem(grade);
//                         subjectItem->setText(0,itemNodeSubject.toElement().attribute("SubjectName"));

//                         if(itemNodeSubject.isElement())
//                         {
//                             QDomNodeList homeWorkList= itemNodeSubject.toElement().elementsByTagName("HomeWork");
//                             QDomNodeList noteList= itemNodeSubject.toElement().elementsByTagName("Note");


//                             for(int k=0;k<homeWorkList.count();k++)
//                             {
//                                 QDomNode itemNodehomeWork = homeWorkList.at(k);
//                                 QTreeWidgetItem *homeWorkItem= new QTreeWidgetItem(subjectItem);
//                                 homeWorkItem->setText(0,itemNodehomeWork.toElement().attribute("HomeWorkName"));


//                             }


//                         }

//                    }




              ui->tWSelectSubject->addTopLevelItem(grade);


            }




       }


   }


}

void SelectPaperForMark::on_tWSelectSubject_clicked(const QModelIndex &index)
{
    int x=0;
    if(ui->tWSelectSubject->currentIndex().parent().parent().isValid())
    {
        ui->lWSelectPaper->clear();
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
                    if(itemNode.toElement().attribute("GradeName")==ui->tWSelectSubject->currentItem()->parent()->parent()->text(0))
                    {
                        QDomNodeList subjectList= itemNode.toElement().elementsByTagName("Subject");

                        for(int j=0;j<subjectList.count();j++)
                        {
                             QDomNode itemNodeSubject = subjectList.at(j);
                             if(itemNodeSubject.toElement().attribute("SubjectName")==ui->tWSelectSubject->currentItem()->text(0))
                             {
                                 QDomNodeList HomeWorkList=itemNodeSubject.toElement().elementsByTagName("HomeWork");

                                 for(int z=0;z<HomeWorkList.count();z++)
                                 {
                                     //qDebug()<<"ddddddddddddddddddddddddddddddddddddd";
                                     QDomNode itemNodeHomeWork= HomeWorkList.at(z);

                                     ui->lWSelectPaper->addItem(itemNodeHomeWork.toElement().attribute("HomeWorkName"));
                                    // qDebug()<<itemNodeHomeWork.toElement().attribute("HomeWorkName");


                                 }



                             }

                        }



                    }



                }




           }


       }
    }


}

void SelectPaperForMark::on_pBMarkPaper_clicked()
{
    int x=0;
    if(!ui->tWSelectSubject->currentIndex().parent().parent().isValid())
    {
         QMessageBox::information(this,"Error","Please select Subject");
         x=1;

    }
    if(!ui->lWSelectPaper->currentIndex().isValid())
    {
        QMessageBox::information(this,"Error","Please select Paper");
        x=1;

    }
    if(x==0)
    {
        QString creatingAnswerPapersPath=basicPath;
        creatingAnswerPapersPath.append("Answers/");
        creatingAnswerPapersPath.append(ui->tWSelectSubject->currentItem()->parent()->parent()->text(0));
        creatingAnswerPapersPath.append("/");
        creatingAnswerPapersPath.append(ui->tWSelectSubject->currentItem()->parent()->text(0));
        creatingAnswerPapersPath.append("/");
        creatingAnswerPapersPath.append(ui->tWSelectSubject->currentItem()->text(0));
        creatingAnswerPapersPath.append("/");
        creatingAnswerPapersPath.append(ui->lWSelectPaper->currentItem()->text());

        qDebug()<<creatingAnswerPapersPath<<"dsssssssssssssssssssssssss";

        papersummary= new Papersummary(0,creatingAnswerPapersPath);
        papersummary->setModal(false);
        papersummary->exec();

    }



}
