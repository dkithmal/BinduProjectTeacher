#include "newnote.h"
#include "ui_newnote.h"

NewNote::NewNote(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::NewNote)
{
    ui->setupUi(this);
    filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
    basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
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


void NewNote::on_pBCreateNote_clicked()
{
    int x=0;
    if(!ui->tWSelectSubject->currentIndex().isValid()||!ui->tWSelectSubject->currentIndex().parent().isValid())
    {
        QMessageBox::information(this,"Error","Select Subject");
        x=1;

    }

    if(ui->lENoteName->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Enter Note Name");
        x=1;

    }

    if(x==0)
   {
        //QString filepath ="D:/dk work/Motarola/project/assinment/";
       // filepath.append(ui->fileName->text());
       // filepath.append(".xml");
        QString newNoteSavefilepath=basicPath;
        newNoteSavefilepath.append("Note/");
        newNoteSavefilepath.append(ui->tWSelectSubject->currentItem()->parent()->text(0));
        newNoteSavefilepath.append("/");
        newNoteSavefilepath.append(ui->tWSelectSubject->currentItem()->text(0));
        newNoteSavefilepath.append("/");
        newNoteSavefilepath.append(ui->lENoteName->text());
        newNoteSavefilepath.append(".txt");

        QFile newPaperFile(newNoteSavefilepath);
        if(!newPaperFile.open(QFile::Append| QFile::Text))
        {

        }
        else
        {
            newPaperFile.close();

        }

        //to Note tag create
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
                                     QDomElement noteElement=document.createElement(QString("Note"));
                                     noteElement.setAttribute("NoteName",ui->lENoteName->text());
                                     itemNodeClass.appendChild(noteElement);



                                     break;

                                 }


                            }


                     }
                            //break;

                  }



                }


            openConfigFile.close();

            if(!openConfigFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
            {
                qDebug()<<"error";

            }
            else
            {
                QTextStream stream(&openConfigFile);
                stream <<document.toString();
                //qDebug() <<document.toString();
                openConfigFile.close();
            //  QMessageBox::information(this,"Success","Mcq Qustion Added");

           }

           }

        newNoteCreating= new NewNoteCreating(0,newNoteSavefilepath);
        newNoteCreating->setModal(false);
        this->close();
        newNoteCreating->exec();
    }


}
