#include "newessaypaper.h"
#include "ui_newessaypaper.h"

NewEssayPaper::NewEssayPaper(QWidget *parent,QString filePath) :
    QWidget(parent),
    ui(new Ui::NewEssayPaper)
{
    ui->setupUi(this);
    paperCrationPath=filePath;


    ui->tWPaperCreation->setCurrentIndex(0);
    ui->pBPrivious->setEnabled(false);
    ui->pBEPrivious->setEnabled(false);



    qustionNo = 0;
    mcqNo=0;
    essayNO=0;
    totalNoOfQuestions=0;
    indexofTabWidget=0;

    setQuestionNo();

    paperHeaderLayout=0;
    paperQuestionsLayout=0;
    questionLayout[0]=0;
    questionLayout[1]=0;
    questionLayout[2]=0;
    questionLayout[3]=0;
    questionLayout[4]=0;
}

NewEssayPaper::~NewEssayPaper()
{
    delete ui;
}

void NewEssayPaper::setQuestionNo()
{

        QFile newPaperFile(paperCrationPath);
        if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
        {
            qDebug()<<"error";

        }
        else
        {
            QDomDocument document;

            document.setContent(&newPaperFile);

            QDomElement root= document.firstChildElement();

            QDomNodeList activityItems = root.elementsByTagName("Activity");
            paperQuestionsLayout = new QVBoxLayout;

            qustionNo=activityItems.count();

        }


}

void NewEssayPaper::on_pBAddEssayQuestion_clicked()
{
    if(ui->lEEssayQuestion->text().isEmpty())
    {
       QMessageBox::information(this,"Error","Please Enter Question");
    }
    else
    {


        //crateing new qustion on xml
        QFile newPaperFile(paperCrationPath);
        if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
        {
            qDebug()<<"error";

        }

        QDomDocument document;

        document.setContent(&newPaperFile);

        QDomElement root= document.firstChildElement();

          QDomElement Activity= document.createElement("Activity");
          Activity.setAttribute("Type","Essay");
          qustionNo++;
          Activity.setAttribute("QusetionNo",qustionNo);
          essayNO++;
          Activity.setAttribute("EssayNo",essayNO);


          QDomElement Question= document.createElement("Question");
          Question.appendChild(document.createTextNode(ui->lEEssayQuestion->text()));
          Activity.appendChild(Question);


          root.appendChild(Activity);
          document.appendChild(root);

          newPaperFile.close();

          if(!newPaperFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
          {
              qDebug()<<"error";

          }
          else
          {
              QTextStream stream(&newPaperFile);
              stream <<document.toString();
              //qDebug() <<document.toString();
              newPaperFile.close();
              QMessageBox::information(this,"Success","Eassy Qustion Added");

              ui->lEEssayQuestion->clear();

          }

    }
}

void NewEssayPaper::on_tWPaperCreation_currentChanged(int index)
{
    if(index==1)
    {

    if(indexofTabWidget==2)
        saveEditedQuestions();

    toCreatePaperLayout();
    indexofTabWidget=1;
    }

    if (index==0)
    {
        if(indexofTabWidget==1)
            saveAnswers();
        if(indexofTabWidget==2)
            saveEditedQuestions();

        indexofTabWidget=0;



    }

    if(index==2)
    {
        if(indexofTabWidget==1)
        saveAnswers();
        toCreatePaperLayout();
        indexofTabWidget=2;

    }
}



void NewEssayPaper::toCreatePaperLayout()
{

    QFile newPaperFile(paperCrationPath);
    if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }
    else
    {
        QDomDocument document;

        document.setContent(&newPaperFile);
        //qDebug()<<document.toString();

        QDomElement root= document.firstChildElement();

        if(paperQuestionsLayout!=NULL)
        {
            QLayoutItem * item;
            QLayout * sublayout;
            QWidget * widget;

            while ((item = paperQuestionsLayout->takeAt(0))) {
                if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                else {delete item;}
            }

            // then finally
            delete paperQuestionsLayout;
            paperQuestionsLayout=0;

            if(questionLayout[0]!=NULL)
            {
                while ((item = questionLayout[0]->takeAt(0))) {
                    if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                    else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                    else {delete item;}
                }

                delete questionLayout[0];
                questionLayout[0]=0;
            }
            if(questionLayout[1]!=NULL)
            {
                while ((item = questionLayout[1]->takeAt(0))) {
                    if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                    else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                    else {delete item;}
                }

                delete questionLayout[1];
                questionLayout[1]=0;
            }
            if(questionLayout[2]!=NULL)
            {
                while ((item = questionLayout[2]->takeAt(0))) {
                    if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                    else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                    else {delete item;}
                }

                delete questionLayout[2];
                questionLayout[2]=0;
            }
            if(questionLayout[3]!=NULL)
            {
                while ((item = questionLayout[3]->takeAt(0))) {
                    if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                    else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                    else {delete item;}
                }

                delete questionLayout[3];
                questionLayout[3]=0;
            }
            if(questionLayout[4]!=NULL)
            {
                while ((item = questionLayout[4]->takeAt(0))) {
                    if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                    else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                    else {delete item;}
                }

                delete questionLayout[4];
                questionLayout[4]=0;
            }



            if(ui->tWPaperCreation->currentIndex()==1)
            {
                if(ui->gBHeader->layout()==NULL)
                {
                    drowHeader(root);

                }
              drowQuestions(root);

            }

             if(ui->tWPaperCreation->currentIndex()==2)
             {
                 if(ui->gBEHeader->layout()==NULL)
                 {
                     drowHeader(root);

                 }
                 drowEditQuestions(root);

             }

        }
        else
        {
            if(ui->tWPaperCreation->currentIndex()==1)
            {
                drowHeader(root);
                drowQuestions(root);

            }
            if(ui->tWPaperCreation->currentIndex()==2)
            {
                drowHeader(root);
                drowEditQuestions(root);

            }


        }








    }

}

void NewEssayPaper::drowHeader(QDomElement root)
{
    QDomNodeList items = root.elementsByTagName("Header");

      QDomNode itemNode = items.at(0);
      QDomElement itemElement=itemNode.toElement();

      QDomNode title=itemElement.elementsByTagName("Title").at(0);
      QDomNode subject=itemElement.elementsByTagName("Subject").at(0);
      QDomNode duration=itemElement.elementsByTagName("Duration").at(0);

      QLabel *lTitle=new QLabel("<h5>"+title.firstChild().nodeValue()+"</h5>");
      QLabel *lSubject=new QLabel("Subject :"+subject.firstChild().nodeValue());
      QLabel *lDuration=new QLabel("Duration :"+duration.firstChild().nodeValue());

      paperHeaderLayout = new QVBoxLayout;

      paperHeaderLayout->addWidget(lTitle,0,Qt::AlignCenter);
      paperHeaderLayout->addWidget(lSubject);
      paperHeaderLayout->addWidget(lDuration);

      if(ui->tWPaperCreation->currentIndex()==1)
      {
       ui->gBHeader->setLayout(paperHeaderLayout);
      }
      if(ui->tWPaperCreation->currentIndex()==2)
      {
          ui->gBEHeader->setLayout(paperHeaderLayout);
      }



}

void NewEssayPaper::drowQuestions(QDomElement root)
{
    int qNoInPage=1;

    QDomNodeList activityItems = root.elementsByTagName("Activity");
    paperQuestionsLayout = new QVBoxLayout;

    totalNoOfQuestions=activityItems.count();
    if(totalNoOfQuestions<=5)
    {
        ui->pBNext->setEnabled(false);
    }
    else if(ui->lPageNo->text().toInt()==1)
    {
      ui->pBNext->setEnabled(true);
    }


    int i=0;
    int j=0;
    if(ui->lPageNo->text().toInt()==1)
    {
        j=5;

    }
    else
    {
        i=(ui->lPageNo->text().toInt()-1)*5;
        j=i+5;
    }
    for (i;i<j;i++)
    {
        QDomNode itemNode = activityItems.at(i);
         questionLayout[qNoInPage-1] = new QGridLayout;


        if(itemNode.isElement())
        {


            if(itemNode.toElement().attribute("Type")=="Essay")
            {
                 int questionNo=itemNode.toElement().attribute("QusetionNo").toInt();
                 int EssayQusrionNo=itemNode.toElement().attribute("EssayNo").toInt();

                 QDomElement itemElement=itemNode.toElement();
                 QDomNode question=itemElement.elementsByTagName("Question").at(0);
                 qusestionLables[questionNo]=new QLabel(QString::number(questionNo)+")"+question.firstChild().nodeValue());

                 questionLayout[qNoInPage-1]->addWidget(qusestionLables[questionNo]);

                 essayAnswers[EssayQusrionNo-1] = new QTextEdit;
                 questionLayout[qNoInPage-1]->addWidget(essayAnswers[EssayQusrionNo-1]);

                 if(qNoInPage==1)
                 ui->fQuestion1->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==2)
                     ui->fQuestion2->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==3)
                     ui->fQuestion3->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==4)
                     ui->fQuestion4->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==5)
                     ui->fQuestion5->setLayout(questionLayout[qNoInPage-1]);


                 qNoInPage++;

                 QDomNode teacherAnswer=itemElement.elementsByTagName("TeacherAnswer").at(0);

                 QString essayQusrionAnswer=teacherAnswer.firstChild().nodeValue();
                 essayAnswers[EssayQusrionNo-1]->setText(essayQusrionAnswer);

            }
        }



    }


    ui->gBQuestions->setLayout(paperQuestionsLayout);


}



void NewEssayPaper::on_pBPrivious_clicked()
{
    saveAnswers();
       ui->lPageNo->setText(QString::number(ui->lPageNo->text().toInt()-1));
       if(ui->lPageNo->text().toInt()==1)
       {
           ui->pBPrivious->setEnabled(false);
       }

       ui->pBNext->setEnabled(true);


       toCreatePaperLayout();
}

void NewEssayPaper::on_pBNext_clicked()
{
    saveAnswers();
       ui->lPageNo->setText(QString::number(ui->lPageNo->text().toInt()+1));
       if(totalNoOfQuestions/5==ui->lPageNo->text().toInt())
       {
           if(totalNoOfQuestions%5>0)
           {
           }
           else
           {
               ui->pBNext->setEnabled(false);

           }

       }
       else if(totalNoOfQuestions/5<ui->lPageNo->text().toInt())
       {
           ui->pBNext->setEnabled(false);

       }
       ui->pBPrivious->setEnabled(true);

       toCreatePaperLayout();
}

void NewEssayPaper::saveAnswers()
{
    QFile newPaperFile(paperCrationPath);
    if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }
    else
    {
        QDomDocument document;

        document.setContent(&newPaperFile);

        QDomElement root= document.firstChildElement();

        QDomNodeList activityItems = root.elementsByTagName("Activity");

        int i=0;
        int j=0;
        if(ui->lPageNo->text().toInt()==1)
        {
            j=5;

        }
        else
        {
            i=(ui->lPageNo->text().toInt()-1)*5;
            j=i+5;
        }

        for (i;i<j;i++)
        {

            QDomNode itemNode = activityItems.at(i);
             if(itemNode.isElement())
             {

                if(itemNode.toElement().attribute("Type")=="Essay")
                  {
                    QDomElement itemElement=itemNode.toElement();
                    QDomNode teacherAnswer=itemElement.elementsByTagName("TeacherAnswer").at(0);

                    if(!teacherAnswer.isNull())
                    {
                        QDomElement newTeacherAnswer = document.createElement(QString("TeacherAnswer"));
                         int essayQusrionNo=itemNode.toElement().attribute("EssayNo").toInt();
                         QString answer=essayAnswers[essayQusrionNo-1]->document()->toPlainText();
                        newTeacherAnswer.appendChild(document.createTextNode(answer));

                        itemNode.replaceChild(newTeacherAnswer,teacherAnswer);


                    }
                    else
                    {
                        QDomElement newTeacherAnswer = document.createElement(QString("TeacherAnswer"));
                        int essayQusrionNo=itemNode.toElement().attribute("EssayNo").toInt();
                        QString answer=essayAnswers[essayQusrionNo-1]->document()->toPlainText();
                        newTeacherAnswer.appendChild(document.createTextNode(answer));

                        itemNode.appendChild(newTeacherAnswer);


                    }

                  }


             }

             }

        newPaperFile.close();

        if(!newPaperFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
        {
            qDebug()<<"error";

        }
        else
        {
            QTextStream stream(&newPaperFile);
            stream <<document.toString();
            //qDebug() <<document.toString();
            newPaperFile.close();
        //  QMessageBox::information(this,"Success","Mcq Qustion Added");

       }

        }


}




void NewEssayPaper::drowEditQuestions(QDomElement root)
{
    int qNoInPage=1;

    QDomNodeList activityItems = root.elementsByTagName("Activity");
    paperQuestionsLayout = new QVBoxLayout;

    totalNoOfQuestions=activityItems.count();
    if(totalNoOfQuestions<=5)
    {
        ui->pBENext->setEnabled(false);
    }
    else if(ui->lEPageNo->text().toInt()==1)
    {
      ui->pBENext->setEnabled(true);
    }


    int i=0;
    int j=0;
    if(ui->lEPageNo->text().toInt()==1)
    {
        j=5;

    }
    else
    {
        i=(ui->lEPageNo->text().toInt()-1)*5;
        j=i+5;
    }
    for (i;i<j;i++)
    {
        QDomNode itemNode = activityItems.at(i);
         questionLayout[qNoInPage-1] = new QGridLayout;


        if(itemNode.isElement())
        {


            if(itemNode.toElement().attribute("Type")=="Essay")
            {
                 int questionNo=itemNode.toElement().attribute("QusetionNo").toInt();
                 int EssayQusrionNo=itemNode.toElement().attribute("EssayNo").toInt();

                 QDomElement itemElement=itemNode.toElement();
                 QDomNode question=itemElement.elementsByTagName("Question").at(0);
                 //qusestionLables[questionNo]=new QLabel(QString::number(questionNo)+")"+question.firstChild().nodeValue());
                 qusestionEdit[questionNo]=new QTextEdit;
                 qusestionEdit[questionNo]->setText(question.firstChild().nodeValue());
                 questionLayout[qNoInPage-1]->addWidget(new QLabel(QString::number(questionNo)+")", this),0,0);

                 questionLayout[qNoInPage-1]->addWidget(qusestionEdit[questionNo],0,1,1,40,0);

                // essayAnswers[EssayQusrionNo-1] = new QTextEdit;
                // questionLayout[qNoInPage-1]->addWidget(essayAnswers[EssayQusrionNo-1]);

                 if(qNoInPage==1)
                 ui->fEQuestion1->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==2)
                     ui->fEQuestion2->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==3)
                     ui->fEQuestion3->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==4)
                     ui->fEQuestion4->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==5)
                     ui->fEQuestion5->setLayout(questionLayout[qNoInPage-1]);


                 qNoInPage++;



            }
        }



    }


    ui->gBEQuestions->setLayout(paperQuestionsLayout);

}

void NewEssayPaper::saveEditedQuestions()
{
    QFile newPaperFile(paperCrationPath);
    if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }
    else
    {
        QDomDocument document;

        document.setContent(&newPaperFile);

        QDomElement root= document.firstChildElement();

        QDomNodeList activityItems = root.elementsByTagName("Activity");

        int i=0;
        int j=0;
        if(ui->lEPageNo->text().toInt()==1)
        {
            j=5;

        }
        else
        {
            i=(ui->lEPageNo->text().toInt()-1)*5;
            j=i+5;
        }

        for (i;i<j;i++)
        {

            QDomNode itemNode = activityItems.at(i);
             if(itemNode.isElement())
             {



                if(itemNode.toElement().attribute("Type")=="Essay")
                {

                    int questionNo=itemNode.toElement().attribute("QusetionNo").toInt();

                    QDomElement itemElement=itemNode.toElement();
                    QDomNode question=itemElement.elementsByTagName("Question").at(0);


                    QDomElement newQuesion = document.createElement(QString("Question"));
                    newQuesion.appendChild(document.createTextNode(qusestionEdit[questionNo]->document()->toPlainText()));

                   itemNode.replaceChild(newQuesion,question);



                }


             }

        }



        newPaperFile.close();

        if(!newPaperFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
        {
            qDebug()<<"error";

        }
        else
        {
            QTextStream stream(&newPaperFile);
            stream <<document.toString();
            //qDebug() <<document.toString();
            newPaperFile.close();
        //  QMessageBox::information(this,"Success","Mcq Qustion Added");

       }
    }

 }







void NewEssayPaper::on_pBEPrivious_clicked()
{
    saveEditedQuestions();
    ui->lEPageNo->setText(QString::number(ui->lEPageNo->text().toInt()-1));
    if(ui->lEPageNo->text().toInt()==1)
    {
        ui->pBEPrivious->setEnabled(false);
    }

    ui->pBENext->setEnabled(true);


    toCreatePaperLayout();
}

void NewEssayPaper::on_pBENext_clicked()
{
    saveEditedQuestions();
     ui->lEPageNo->setText(QString::number(ui->lEPageNo->text().toInt()+1));
     if(totalNoOfQuestions/5==ui->lEPageNo->text().toInt())
     {
         if(totalNoOfQuestions%5>0)
         {
         }
         else
         {
             ui->pBENext->setEnabled(false);

         }

     }
     else if(totalNoOfQuestions/5<ui->lEPageNo->text().toInt())
     {
         ui->pBENext->setEnabled(false);

     }
     ui->pBEPrivious->setEnabled(true);

     toCreatePaperLayout();
}