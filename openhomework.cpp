#include "openhomework.h"
#include "ui_openhomework.h"

OpenHomeWork::OpenHomeWork(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::OpenHomeWork)
{
    ui->setupUi(this);
    filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
    basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
    setSubjetToTree();
}

OpenHomeWork::~OpenHomeWork()
{
    delete ui;
}


void OpenHomeWork::setSubjetToTree()
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

void OpenHomeWork::on_tWSelectSubject_clicked(const QModelIndex &index)
{
    ui->lWHomeWorks->clear();
    //int x=0;
//    if(!ui->tWSelectSubject->currentIndex().isValid()||!ui->tWSelectSubject->currentIndex().parent().isValid())
//    {
//        QMessageBox::information(this,"Error","Select Subject");
//        x=1;

//    }
    if(ui->tWSelectSubject->currentIndex().parent().isValid())
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
                    if(itemNode.toElement().attribute("GradeName")==ui->tWSelectSubject->currentItem()->parent()->text(0))
                    {
                        QDomNodeList classList= itemNode.toElement().elementsByTagName("Subject");

                            for(int j=0;j<classList.count();j++)
                            {

                                QDomNode itemNodeClass = classList.at(j);

                                 if(itemNodeClass.toElement().attribute("SubjectName")==ui->tWSelectSubject->currentItem()->text(0))
                                 {
                                     if(itemNodeClass.isElement())
                                     {
                                         QDomNodeList paperNameList=itemNodeClass.toElement().elementsByTagName("HomeWork");
                                         for(int z=0;z<paperNameList.size();z++)
                                         {
                                             QDomNode paper=paperNameList.at(z);
                                            ui->lWHomeWorks->addItem( paper.toElement().attribute("HomeWorkName"));

                                         }

                                     }


                                 }


                            }
                            //break;

                    }



                }




           }


       }

    }




}

void OpenHomeWork::on_pBOpen_clicked()
{
    int x=0;
    if(!ui->tWSelectSubject->currentIndex().isValid()||!ui->tWSelectSubject->currentIndex().parent().isValid())
    {
        QMessageBox::information(this,"Error","Select Subject");
       x=1;

    }
    if(!ui->lWHomeWorks->currentIndex().isValid())
    {
        QMessageBox::information(this,"Error","Select Paper");
       x=1;

    }
    if(ui->tWSelectSubject->currentIndex().parent().isValid()&&(ui->lWHomeWorks->currentIndex().isValid()))
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
                    if(itemNode.toElement().attribute("GradeName")==ui->tWSelectSubject->currentItem()->parent()->text(0))
                    {
                        QDomNodeList classList= itemNode.toElement().elementsByTagName("Subject");

                            for(int j=0;j<classList.count();j++)
                            {

                                QDomNode itemNodeClass = classList.at(j);

                                 if(itemNodeClass.toElement().attribute("SubjectName")==ui->tWSelectSubject->currentItem()->text(0))
                                 {
                                     if(itemNodeClass.isElement())
                                     {
                                         QDomNodeList paperNameList=itemNodeClass.toElement().elementsByTagName("HomeWork");
                                         for(int z=0;z<paperNameList.size();z++)
                                         {
                                             QDomNode paper=paperNameList.at(z);
                                             if(paper.toElement().attribute("HomeWorkName")==ui->lWHomeWorks->currentItem()->text())
                                             {
                                                 QString newfilepath=basicPath;
                                                 newfilepath.append("HomeWork/");
                                                 newfilepath.append(ui->tWSelectSubject->currentItem()->parent()->text(0));
                                                // QString newfilepath=qPaperSavefilepath.append(ui->tWSelectSubject->currentItem()->parent()->text(0));
                                                 newfilepath.append("/");
                                                 newfilepath.append(ui->tWSelectSubject->currentItem()->text(0));
                                                 newfilepath.append("/");
                                                 newfilepath.append(ui->lWHomeWorks->currentItem()->text());
                                                 newfilepath.append(".xml");

                                                 if(paper.toElement().attribute("Type")=="Mcq")
                                                 {
                                                     mewMcqPaper= new NewMcqPaper(0,newfilepath);
                                                     mewMcqPaper->setModal(false);
                                                     this->close();
                                                     mewMcqPaper->exec();


                                                 }
                                                 if(paper.toElement().attribute("Type")=="Essay")
                                                 {
                                                     newEssayPaper= new NewEssayPaper(0,newfilepath);
                                                     newEssayPaper->setModal(false);
                                                     this->close();
                                                     newEssayPaper->exec();

                                                 }
                                                 if(paper.toElement().attribute("Type")=="EssayMcq")
                                                 {
                                                     newMixPaper = new NewMixPaper(0,newfilepath);
                                                     newMixPaper->setModal(false);
                                                     this->close();
                                                     newMixPaper->exec();

                                                 }
                                                 break;

                                             }
                                            //ui->lWHomeWorks->addItem( paper.toElement().attribute("HomeWorkName"));

                                         }

                                     }


                                 }


                            }
                            //break;

                    }



                }




           }


       }

    }

}
