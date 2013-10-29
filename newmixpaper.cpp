#include "newmixpaper.h"
#include "ui_newmixpaper.h"

NewMixPaper::NewMixPaper(QWidget *parent,QString filePath) :
    QWidget(parent),
    ui(new Ui::NewMixPaper)
{
    ui->setupUi(this);
    paperCrationPath=filePath;

    ui->cBNoOfChoises->setCurrentIndex(0);
    ui->tWPaperCreation->setCurrentIndex(0);
    on_cBNoOfChoises_currentIndexChanged(0);


    qustionNo = 0;
    mcqNo=0;
    essayNO=0;

    paperHeaderLayout=0;
    paperQuestionsLayout=0;
}

NewMixPaper::~NewMixPaper()
{
    delete ui;
}

void NewMixPaper::on_cBNoOfChoises_currentIndexChanged(int index)
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

void NewMixPaper::on_pBAddMcq_clicked()
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

void NewMixPaper::on_pBAddEssayQuestion_clicked()
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


//this method no need but cant romove
void NewMixPaper::on_tabWidget_currentChanged(int index)
{


}

void NewMixPaper::on_tWPaperCreation_currentChanged(int index)
{
    if(index==1)
     toCreatePaperLayout();
}

void NewMixPaper::toCreatePaperLayout()
{
    ;
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

        if(paperHeaderLayout!=NULL)
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


            drowQuestions(root);

        }
        else
        {
            drowHeader(root);
            drowQuestions(root);

        }








    }

}

void NewMixPaper::drowHeader(QDomElement root)
{
    QDomNodeList items = root.elementsByTagName("Header");

      QDomNode itemNode = items.at(0);
      QDomElement itemElement=itemNode.toElement();

      QDomNode title=itemElement.elementsByTagName("Title").at(0);
      QDomNode subject=itemElement.elementsByTagName("Subject").at(0);
      QDomNode duration=itemElement.elementsByTagName("Duration").at(0);

      QLabel *lTitle=new QLabel("<h3>"+title.firstChild().nodeValue()+"</h3>");
      QLabel *lSubject=new QLabel("Subject :"+subject.firstChild().nodeValue());
      QLabel *lDuration=new QLabel("Duration :"+duration.firstChild().nodeValue());

      paperHeaderLayout = new QVBoxLayout;

      paperHeaderLayout->addWidget(lTitle,0,Qt::AlignCenter);
      paperHeaderLayout->addWidget(lSubject);
      paperHeaderLayout->addWidget(lDuration);

      ui->gBHeader->setLayout(paperHeaderLayout);


}

void NewMixPaper::drowQuestions(QDomElement root)
{
    int qutsitonNoForFrame=1;

    QDomNodeList activityItems = root.elementsByTagName("Activity");
	paperQuestionsLayout = new QVBoxLayout;

    for (int i=0;i<activityItems.count();i++)
    {
        QDomNode itemNode = activityItems.at(i);
		 


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

				 mcqQuestionLayout[mcqQusrionNo-1] = new QVBoxLayout;

                if(noOfChoises==2)
                {
                    QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                    QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);

                    rBMcqAnswers[mcqQusrionNo-1][0]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][0]->setText(answer1.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][1]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][1]->setText(answer2.firstChild().nodeValue());

                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(qusestionLables[questionNo]);
                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][0]);
                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][1]);
                    


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

                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(qusestionLables[questionNo]);
                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][0]);
                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][1]);
                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][2]);					
                   

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

                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(qusestionLables[questionNo]);
                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][0]);
                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][1]);
                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][2]);
                    mcqQuestionLayout[mcqQusrionNo-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][3]);
					
                  

                }

                //mcqFrames[mcqQusrionNo-1]=new QFrame();
                //mcqFrames[mcqQusrionNo-1]->setLayout(mcqQuestionLayout[mcqQusrionNo-1]);
                if(qutsitonNoForFrame==1)
                ui->fQuestion1->setLayout(mcqQuestionLayout[mcqQusrionNo-1]);
                if(qutsitonNoForFrame==2)
                    ui->fQuestion2->setLayout(mcqQuestionLayout[mcqQusrionNo-1]);
                if(qutsitonNoForFrame==3)
                    ui->fQuestion3->setLayout(mcqQuestionLayout[mcqQusrionNo-1]);
                if(qutsitonNoForFrame==4)
                    ui->fQuestion4->setLayout(mcqQuestionLayout[mcqQusrionNo-1]);
                if(qutsitonNoForFrame==5)
                    ui->fQuestion5->setLayout(mcqQuestionLayout[mcqQusrionNo-1]);

                qutsitonNoForFrame++;

                //paperQuestionsLayout->addWidget(mcqFrames[mcqQusrionNo-1],1);
               // paperQuestionsLayout->addWidget(ui->fQuestion1]);






            }
            if(itemNode.toElement().attribute("Type")=="Essay")
            {
                 int questionNo=itemNode.toElement().attribute("QusetionNo").toInt();
                 int EssayQusrionNo=itemNode.toElement().attribute("EssayNo").toInt();

                 QDomElement itemElement=itemNode.toElement();
                 QDomNode question=itemElement.elementsByTagName("Question").at(0);
                 qusestionLables[questionNo]=new QLabel(QString::number(questionNo)+")"+question.firstChild().nodeValue());


                 essayAnswers[EssayQusrionNo] = new QLineEdit;



            }
        }



    }


    ui->gBQuestions->setLayout(paperQuestionsLayout);


}


