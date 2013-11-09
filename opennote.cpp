#include "opennote.h"
#include "ui_opennote.h"

OpenNote::OpenNote(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::OpenNote)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    filepath ="D:/dk work/Motarola/Project Location/Teacher Path/Administration/Admin.xml";
    basicPath="D:/dk work/Motarola/Project Location/Teacher Path/Teacher/";
    setSubjetToTree();
}

OpenNote::~OpenNote()
{
    delete ui;
}



void OpenNote::setSubjetToTree()
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
                grade->setIcon(0,QIcon(":/binduTeacher/new/imgs/grade.png"));


                QDomNodeList classList= itemNode.toElement().elementsByTagName("Subject");

                    for(int j=0;j<classList.count();j++)
                    {

                        QDomNode itemNodeClass = classList.at(j);
                        // ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));
                         QTreeWidgetItem *subjectItem= new QTreeWidgetItem(grade);
                         subjectItem->setText(0,itemNodeClass.toElement().attribute("SubjectName"));
                         subjectItem->setIcon(0,QIcon(":/binduTeacher/new/imgs/subject.png"));

                    }




              ui->tWSelectSubject->addTopLevelItem(grade);


            }




       }


   }


}



void OpenNote::on_tWSelectSubject_clicked(const QModelIndex &index)
{
    ui->lWHomeWorks->clear();
   // int x=0;
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
                                         QDomNodeList paperNameList=itemNodeClass.toElement().elementsByTagName("Note");
                                         for(int z=0;z<paperNameList.size();z++)
                                         {
                                             QDomNode paper=paperNameList.at(z);
                                           // ui->lWHomeWorks->addItem( paper.toElement().attribute("NoteName"));
                                            ui->lWHomeWorks->addItem(new QListWidgetItem(QIcon(":/binduTeacher/new/imgs/note.png"), paper.toElement().attribute("NoteName")));

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



void OpenNote::on_pBOpen_clicked()
{
    int x=0;
    if(!ui->tWSelectSubject->currentIndex().isValid()||!ui->tWSelectSubject->currentIndex().parent().isValid())
    {
        QMessageBox::information(this,"Error","Select Subject");
       x=1;

    }
    if(!ui->lWHomeWorks->currentIndex().isValid())
    {
        QMessageBox::information(this,"Error","Select Note");
       x=1;

    }

    if(x==0)
    {
        QString newNoteFilePath=basicPath;
        newNoteFilePath.append("Note/");
        newNoteFilePath.append(ui->tWSelectSubject->currentItem()->parent()->text(0));
        newNoteFilePath.append("/");
        newNoteFilePath.append(ui->tWSelectSubject->currentItem()->text(0));
        newNoteFilePath.append("/");
        newNoteFilePath.append(ui->lWHomeWorks->currentItem()->text());
        newNoteFilePath.append(".txt");



        editNote= new EditNote(0,newNoteFilePath);
        editNote->setModal(false);
        this->close();
        editNote->exec();
    }

}

void OpenNote::on_pBDeleteNote_clicked()
{
    int x=0;
    if(!ui->tWSelectSubject->currentIndex().isValid()||!ui->tWSelectSubject->currentIndex().parent().isValid())
    {
        QMessageBox::information(this,"Error","Select Subject");
       x=1;

    }
    if(!ui->lWHomeWorks->currentIndex().isValid())
    {
        QMessageBox::information(this,"Error","Select Note");
       x=1;

    }

    if(x==0)
    {QString creatingNotePath=basicPath;
        creatingNotePath.append("Note/");
        creatingNotePath.append(ui->tWSelectSubject->currentItem()->parent()->text(0));
        creatingNotePath.append("/");
        creatingNotePath.append(ui->tWSelectSubject->currentItem()->text(0));
        creatingNotePath.append("/");
        creatingNotePath.append(ui->lWHomeWorks->currentItem()->text());
        creatingNotePath.append(".txt");




        QFile notefile(creatingNotePath);
        if(notefile.exists())
        {

            notefile.remove();
        }



        //delete in admin.xml
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
                        QDomNodeList subjectList= itemNode.toElement().elementsByTagName("Subject");

                        for(int j=0;j<subjectList.count();j++)
                        {
                             QDomNode itemNodeSubject = subjectList.at(j);
                             if(itemNodeSubject.toElement().attribute("SubjectName")==ui->tWSelectSubject->currentItem()->text(0))
                             {
                                 QDomNodeList HomeWorkList=itemNodeSubject.toElement().elementsByTagName("Note");

                                 for(int z=0;z<HomeWorkList.count();z++)
                                 {

                                     QDomNode itemNodeHomeWork= HomeWorkList.at(z);

                                     if(itemNodeHomeWork.toElement().attribute("NoteName")==ui->lWHomeWorks->currentItem()->text())
                                     {
                                         itemNodeSubject.toElement().removeChild(HomeWorkList.at(z));
                                         QMessageBox::warning(this,"Error","Home Work removed");

                                     }



                                 }



                             }

                        }



                    }



                }




           }


            //root.appendChild(Activity);
            document.appendChild(root);

            openConfigFile.close();

            if(!openConfigFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
            {
                qDebug()<<"error";

            }
            else
            {
                QTextStream stream(&openConfigFile);
                stream <<document.toString();
                openConfigFile.close();



            }

            ui->tWSelectSubject->clear();
            ui->lWHomeWorks->clear();
            setSubjetToTree();



       }
    }

}
