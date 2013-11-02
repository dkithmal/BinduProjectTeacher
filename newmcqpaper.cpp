#include "newmcqpaper.h"
#include "ui_newmcqpaper.h"

NewMcqPaper::NewMcqPaper(QDialog *parent,QString filePath) :
    QDialog(parent),
    ui(new Ui::NewMcqPaper)
{
    ui->setupUi(this);
    paperCrationPath=filePath;

    ui->cBNoOfChoises->setCurrentIndex(0);
    ui->tWPaperCreation->setCurrentIndex(0);
    ui->pBPrivious->setEnabled(false);
    ui->pBEPrivious->setEnabled(false);
    on_cBNoOfChoises_currentIndexChanged(0);


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

NewMcqPaper::~NewMcqPaper()
{
    delete ui;
}

void NewMcqPaper::setQuestionNo()
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

void NewMcqPaper::on_cBNoOfChoises_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->lAnswer1->setEnabled(true);
        ui->lAnswer2->setEnabled(true);
        ui->lAnswer3->setEnabled(false);
        ui->lAnswer4->setEnabled(false);

        ui->lEAnswer1->setEnabled(true);
        ui->lEAnswer2->setEnabled(true);
        ui->lEAnswer3->setEnabled(false);
        ui->lEAnswer4->setEnabled(false);
    }
    if(index==1)
    {
        ui->lAnswer1->setEnabled(true);
        ui->lAnswer2->setEnabled(true);
        ui->lAnswer3->setEnabled(true);
        ui->lAnswer4->setEnabled(false);

        ui->lEAnswer1->setEnabled(true);
        ui->lEAnswer2->setEnabled(true);
        ui->lEAnswer3->setEnabled(true);
        ui->lEAnswer4->setEnabled(false);

    }
    if(index==2)
    {
        ui->lAnswer1->setEnabled(true);
        ui->lAnswer2->setEnabled(true);
        ui->lAnswer3->setEnabled(true);
        ui->lAnswer4->setEnabled(true);

        ui->lEAnswer1->setEnabled(true);
        ui->lEAnswer2->setEnabled(true);
        ui->lEAnswer3->setEnabled(true);
        ui->lEAnswer4->setEnabled(true);

    }
}

void NewMcqPaper::on_pBAddMcq_clicked()
{
    int x=0;

    if(ui->cBNoOfChoises->currentText().toInt()==2)
    {
        if(ui->lEAnswer1->text().isEmpty()||ui->lEAnswer2->text().isEmpty())
        {
            QMessageBox::information(this,"Error","Please Enter All answers");
            x=1;

        }


    }
    if(ui->cBNoOfChoises->currentText().toInt()==3)
    {
        if(ui->lEAnswer1->text().isEmpty()||ui->lEAnswer2->text().isEmpty()||ui->lEAnswer3->text().isEmpty())
        {
            QMessageBox::information(this,"Error","Please Enter All answers");
            x=1;

        }


    }
    if(ui->cBNoOfChoises->currentText().toInt()==4)
    {
        if(ui->lEAnswer1->text().isEmpty()||ui->lEAnswer2->text().isEmpty()||ui->lEAnswer3->text().isEmpty()||ui->lEAnswer4->text().isEmpty())
        {
            QMessageBox::information(this,"Error","Please Enter All answers");
            x=1;

        }


    }



    if(ui->lEMcqQuestion->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Enter Question");
        x=1;

    }







// start create paper xml
    if(x==0)
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

              QDomElement Activity= document.createElement("Activity");
              Activity.setAttribute("Type","Mcq");
              qustionNo++;
              Activity.setAttribute("QusetionNo",qustionNo);
              mcqNo++;
              Activity.setAttribute("McqNo",mcqNo);
              Activity.setAttribute("NoOfChoises",ui->cBNoOfChoises->currentText().toInt());

               QDomElement Question= document.createElement("Question");
               Question.appendChild(document.createTextNode(ui->lEMcqQuestion->text()));
               Activity.appendChild(Question);

               for(int x=1;x<=ui->cBNoOfChoises->currentText().toInt();x++)
               {
                   QDomElement choice= document.createElement("Choice");
                   if(x==1)
                   choice.appendChild(document.createTextNode(ui->lEAnswer1->text()));
                   if(x==2)
                       choice.appendChild(document.createTextNode(ui->lEAnswer2->text()));
                   if(x==3)
                       choice.appendChild(document.createTextNode(ui->lEAnswer3->text()));
                   if(x==4)
                      choice.appendChild(document.createTextNode(ui->lEAnswer4->text()));

                   Activity.appendChild(choice);
               }



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
                  QMessageBox::information(this,"Success","Mcq Qustion Added");

                  ui->lEAnswer1->clear();
                  ui->lEAnswer2->clear();
                  ui->lEAnswer3->clear();
                  ui->lEAnswer4->clear();

                  ui->lEMcqQuestion->clear();


                }

        }

    }
}

void NewMcqPaper::on_tWPaperCreation_currentChanged(int index)
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

void NewMcqPaper::toCreatePaperLayout()
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

void NewMcqPaper::drowHeader(QDomElement root)
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

void NewMcqPaper::drowQuestions(QDomElement root)
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

            if(itemNode.toElement().attribute("Type")=="Mcq")
            {
                int noOfChoises=itemNode.toElement().attribute("NoOfChoises").toInt();
                int mcqQusrionNo=itemNode.toElement().attribute("McqNo").toInt();
                int questionNo=itemNode.toElement().attribute("QusetionNo").toInt();


                QDomElement itemElement=itemNode.toElement();
                QDomNode question=itemElement.elementsByTagName("Question").at(0);
                qusestionLables[questionNo]=new QLabel(QString::number(questionNo)+")"+question.firstChild().nodeValue());



                if(noOfChoises==2)
                {
                    QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                    QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);

                    rBMcqAnswers[mcqQusrionNo-1][0]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][0]->setText(answer1.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][1]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][1]->setText(answer2.firstChild().nodeValue());

                    questionLayout[qNoInPage-1]->addWidget(qusestionLables[questionNo],0,0,1,40,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("1)", this),1,0,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][0],1,1,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("2)", this), 1,20,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][1],1,21,1,19,0);



                }
                if(noOfChoises==3)
                {
                    QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                    QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);
                    QDomNode answer3=itemElement.elementsByTagName("Choice").at(2);

                    rBMcqAnswers[mcqQusrionNo-1][0]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][0]->setText(answer1.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][1]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][1]->setText(answer2.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][2]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][2]->setText(answer3.firstChild().nodeValue());

                    questionLayout[qNoInPage-1]->addWidget(qusestionLables[questionNo],0,0,1,40,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("1)", this),1,0,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][0],1,1,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("2)", this), 1,20,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][1],1,21,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("3)", this), 2,0,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][2],2,1,1,39,0);


                }
                if(noOfChoises==4)
                {
                    QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                    QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);
                    QDomNode answer3=itemElement.elementsByTagName("Choice").at(2);
                    QDomNode answer4=itemElement.elementsByTagName("Choice").at(3);

                    rBMcqAnswers[mcqQusrionNo-1][0]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][0]->setText(answer1.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][1]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][1]->setText(answer2.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][2]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][2]->setText(answer3.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][3]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][3]->setText(answer4.firstChild().nodeValue());

                    questionLayout[qNoInPage-1]->addWidget(qusestionLables[questionNo],0,0,1,40,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("1)", this),1,0,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][0],1,1,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("2)", this), 1,20,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][1],1,21,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("3)", this), 2,0,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][2],2,1,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("4)", this),2,20,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][3],2,21,1,19,0);



                }

                //mcqFrames[mcqQusrionNo-1]=new QFrame();
                //mcqFrames[mcqQusrionNo-1]->setLayout(mcqQuestionLayout[mcqQusrionNo-1]);
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

                int mcqQusrionAnswer=teacherAnswer.firstChild().nodeValue().toInt();

                if(mcqQusrionAnswer!=0)
                {
                    rBMcqAnswers[mcqQusrionNo-1][mcqQusrionAnswer-1]->setChecked(true);

                }
                //paperQuestionsLayout->addWidget(mcqFrames[mcqQusrionNo-1],1);
               // paperQuestionsLayout->addWidget(ui->fQuestion1]);






            }

        }



    }


    ui->gBQuestions->setLayout(paperQuestionsLayout);


}

void NewMcqPaper::on_pBPrivious_clicked()
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

void NewMcqPaper::on_pBNext_clicked()
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


void NewMcqPaper::saveAnswers()
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
                  if(itemNode.toElement().attribute("Type")=="Mcq")
                  {

                      QDomElement itemElement=itemNode.toElement();
                      QDomNode teacherAnswer=itemElement.elementsByTagName("TeacherAnswer").at(0);


                      if(!teacherAnswer.isNull())
                      {
                          int mcqQusrionNo=itemNode.toElement().attribute("McqNo").toInt();
                          int noOfChoises=itemNode.toElement().attribute("NoOfChoises").toInt();

                          QDomElement newTeacherAnswer = document.createElement(QString("TeacherAnswer"));


                          for(int k=0;k<noOfChoises;k++)
                          {

                              if(rBMcqAnswers[mcqQusrionNo-1][k]->isChecked())
                              {

                                  newTeacherAnswer.appendChild(document.createTextNode(QString::number(k+1)));

                                  itemNode.replaceChild(newTeacherAnswer,teacherAnswer);

                                  break;
                              }

                          }


                      }
                      else
                      {

                          QDomElement newTeacherAnswer = document.createElement(QString("TeacherAnswer"));

                          int mcqQusrionNo=itemNode.toElement().attribute("McqNo").toInt();
                          int noOfChoises=itemNode.toElement().attribute("NoOfChoises").toInt();


                         for(int m=0;m<noOfChoises;m++)
                         {



                             if(rBMcqAnswers[mcqQusrionNo-1][m]->isChecked())
                             {
                                 newTeacherAnswer.appendChild(document.createTextNode(QString::number(m+1)));

                                 itemNode.appendChild(newTeacherAnswer);


                                 break;
                             }

                         }

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

void NewMcqPaper::drowEditQuestions(QDomElement root)
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

            if(itemNode.toElement().attribute("Type")=="Mcq")
            {
                int noOfChoises=itemNode.toElement().attribute("NoOfChoises").toInt();
                int mcqQusrionNo=itemNode.toElement().attribute("McqNo").toInt();
                int questionNo=itemNode.toElement().attribute("QusetionNo").toInt();


                QDomElement itemElement=itemNode.toElement();
                QDomNode question=itemElement.elementsByTagName("Question").at(0);
                //qusestionLables[questionNo]=new QLabel(QString::number(questionNo)+")"+question.firstChild().nodeValue());
                 qusestionEdit[questionNo]=new QTextEdit;
                 qusestionEdit[questionNo]->setText(question.firstChild().nodeValue());


                if(noOfChoises==2)
                {
                    QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                    QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);

                    lEMcqAnswers[mcqQusrionNo-1][0]=new QLineEdit;
                    lEMcqAnswers[mcqQusrionNo-1][0]->setText(answer1.firstChild().nodeValue());
                    lEMcqAnswers[mcqQusrionNo-1][1]=new  QLineEdit;
                    lEMcqAnswers[mcqQusrionNo-1][1]->setText(answer2.firstChild().nodeValue());

                    questionLayout[qNoInPage-1]->addWidget(new QLabel(QString::number(questionNo)+")", this),0,0);
                    questionLayout[qNoInPage-1]->addWidget(qusestionEdit[questionNo],0,1,1,3,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("A1)", this), 1, 0);
                    questionLayout[qNoInPage-1]->addWidget(lEMcqAnswers[mcqQusrionNo-1][0],1,1);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("A2)", this), 1, 2);
                    questionLayout[qNoInPage-1]->addWidget(lEMcqAnswers[mcqQusrionNo-1][1],1,3);



                }
                if(noOfChoises==3)
                {
                    QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                    QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);
                    QDomNode answer3=itemElement.elementsByTagName("Choice").at(2);

                    lEMcqAnswers[mcqQusrionNo-1][0]=new QLineEdit;
                    lEMcqAnswers[mcqQusrionNo-1][0]->setText(answer1.firstChild().nodeValue());
                    lEMcqAnswers[mcqQusrionNo-1][1]=new QLineEdit;
                    lEMcqAnswers[mcqQusrionNo-1][1]->setText(answer2.firstChild().nodeValue());
                    lEMcqAnswers[mcqQusrionNo-1][2]=new QLineEdit;
                    lEMcqAnswers[mcqQusrionNo-1][2]->setText(answer3.firstChild().nodeValue());

                    questionLayout[qNoInPage-1]->addWidget(new QLabel(QString::number(questionNo)+")", this),0,0);
                    questionLayout[qNoInPage-1]->addWidget(qusestionEdit[questionNo],0,1,1,3,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("A1)", this), 1, 0);
                    questionLayout[qNoInPage-1]->addWidget(lEMcqAnswers[mcqQusrionNo-1][0],1,1);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("A2)", this), 1, 2);
                    questionLayout[qNoInPage-1]->addWidget(lEMcqAnswers[mcqQusrionNo-1][1],1,3);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("A3)", this), 2, 0);
                    questionLayout[qNoInPage-1]->addWidget(lEMcqAnswers[mcqQusrionNo-1][2],2,1);


                }
                if(noOfChoises==4)
                {
                    QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                    QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);
                    QDomNode answer3=itemElement.elementsByTagName("Choice").at(2);
                    QDomNode answer4=itemElement.elementsByTagName("Choice").at(3);

                    lEMcqAnswers[mcqQusrionNo-1][0]=new QLineEdit;
                    lEMcqAnswers[mcqQusrionNo-1][0]->setText(answer1.firstChild().nodeValue());
                    lEMcqAnswers[mcqQusrionNo-1][1]=new QLineEdit;
                    lEMcqAnswers[mcqQusrionNo-1][1]->setText(answer2.firstChild().nodeValue());
                    lEMcqAnswers[mcqQusrionNo-1][2]=new QLineEdit;
                    lEMcqAnswers[mcqQusrionNo-1][2]->setText(answer3.firstChild().nodeValue());
                    lEMcqAnswers[mcqQusrionNo-1][3]=new QLineEdit;
                    lEMcqAnswers[mcqQusrionNo-1][3]->setText(answer4.firstChild().nodeValue());

                    questionLayout[qNoInPage-1]->addWidget(new QLabel(QString::number(questionNo)+")", this),0,0);
                    questionLayout[qNoInPage-1]->addWidget(qusestionEdit[questionNo],0,1,1,3,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("A1)", this), 1, 0);
                    questionLayout[qNoInPage-1]->addWidget(lEMcqAnswers[mcqQusrionNo-1][0],1,1);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("A2)", this), 1, 2);
                    questionLayout[qNoInPage-1]->addWidget(lEMcqAnswers[mcqQusrionNo-1][1],1,3);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("A3)", this), 2, 0);
                    questionLayout[qNoInPage-1]->addWidget(lEMcqAnswers[mcqQusrionNo-1][2],2,1);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("A4)", this), 2, 2);
                    questionLayout[qNoInPage-1]->addWidget(lEMcqAnswers[mcqQusrionNo-1][3],2,3);



                }

                //mcqFrames[mcqQusrionNo-1]=new QFrame();
                //mcqFrames[mcqQusrionNo-1]->setLayout(mcqQuestionLayout[mcqQusrionNo-1]);
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

//                QDomNode teacherAnswer=itemElement.elementsByTagName("TeacherAnswer").at(0);

//                int mcqQusrionAnswer=teacherAnswer.firstChild().nodeValue().toInt();


                //paperQuestionsLayout->addWidget(mcqFrames[mcqQusrionNo-1],1);
               // paperQuestionsLayout->addWidget(ui->fQuestion1]);






            }

        }



    }


    ui->gBEQuestions->setLayout(paperQuestionsLayout);

}

void NewMcqPaper::saveEditedQuestions()
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
                  if(itemNode.toElement().attribute("Type")=="Mcq")
                  {
                      int questionNo=itemNode.toElement().attribute("QusetionNo").toInt();
                      int noOfChoises=itemNode.toElement().attribute("NoOfChoises").toInt();

                      QDomElement itemElement=itemNode.toElement();
                      QDomNode question=itemElement.elementsByTagName("Question").at(0);


                      QDomElement newQuesion = document.createElement(QString("Question"));
                      newQuesion.appendChild(document.createTextNode(qusestionEdit[questionNo]->document()->toPlainText()));

                      itemNode.replaceChild(newQuesion,question);

                      int mcqQusrionNo=itemNode.toElement().attribute("McqNo").toInt();

                       QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                       QDomElement newAnswer1 = document.createElement(QString("Choice"));
                       newAnswer1.appendChild(document.createTextNode(lEMcqAnswers[mcqQusrionNo-1][0]->text()));
                       itemNode.replaceChild(newAnswer1,answer1);

                       QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);
                       QDomElement newAnswer2 = document.createElement(QString("Choice"));
                       newAnswer2.appendChild(document.createTextNode(lEMcqAnswers[mcqQusrionNo-1][1]->text()));
                       itemNode.replaceChild(newAnswer2,answer2);

                       if(noOfChoises==3)
                       {
                           QDomNode answer3=itemElement.elementsByTagName("Choice").at(2);
                           QDomElement newAnswer3 = document.createElement(QString("Choice"));
                           newAnswer3.appendChild(document.createTextNode(lEMcqAnswers[mcqQusrionNo-1][2]->text()));
                           itemNode.replaceChild(newAnswer3,answer3);

                       }
                       if(noOfChoises==4)
                       {
                           QDomNode answer3=itemElement.elementsByTagName("Choice").at(2);
                           QDomElement newAnswer3 = document.createElement(QString("Choice"));
                           newAnswer3.appendChild(document.createTextNode(lEMcqAnswers[mcqQusrionNo-1][2]->text()));
                           itemNode.replaceChild(newAnswer3,answer3);

                           QDomNode answer4=itemElement.elementsByTagName("Choice").at(3);
                           QDomElement newAnswer4 = document.createElement(QString("Choice"));
                           newAnswer4.appendChild(document.createTextNode(lEMcqAnswers[mcqQusrionNo-1][3]->text()));
                           itemNode.replaceChild(newAnswer4,answer4);

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



void NewMcqPaper::on_pBEPrivious_clicked()
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

void NewMcqPaper::on_pBENext_clicked()
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
