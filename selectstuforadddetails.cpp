#include "selectstuforadddetails.h"
#include "ui_selectstuforadddetails.h"

SelectStuForAddDetails::SelectStuForAddDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectStuForAddDetails)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
    basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
    setClassList();
}

SelectStuForAddDetails::~SelectStuForAddDetails()
{
    delete ui;
}



void SelectStuForAddDetails::setClassList()
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
                grade->setIcon(0,QIcon(":/binduTeacher/new/imgs/grade.png"));


                QDomNodeList classeList= itemNode.toElement().elementsByTagName("Class");

                    for(int j=0;j<classeList.count();j++)
                    {
                        QDomNode itemNodeClass = classeList.at(j);
                        QTreeWidgetItem *classItem= new QTreeWidgetItem(grade);
                        classItem->setText(0,itemNodeClass.toElement().attribute("ClassName"));
                        classItem->setIcon(0,QIcon(":/binduTeacher/new/imgs/class.png"));



                    }




              ui->tWSelectClass->addTopLevelItem(grade);


            }




       }


   }

}

void SelectStuForAddDetails::on_tWSelectClass_clicked(const QModelIndex &index)
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
                                       //ui->lWStudent->addItem(studentName);
                                        ui->lWStudent->addItem(new QListWidgetItem(QIcon(":/binduTeacher/new/imgs/student.jpg"), studentName));

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

void SelectStuForAddDetails::on_pBAddDetails_clicked()
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
        //creaging directry if not exist
        QString creatingDirctry=basicPath;
        creatingDirctry.append("StudentInformation");

        if(!QDir(creatingDirctry).exists())
        {
            QDir().mkdir(creatingDirctry);


        }

        creatingDirctry.append("/").append(ui->tWSelectClass->currentItem()->parent()->text(0));

        if(!QDir(creatingDirctry).exists())
        {
            QDir().mkdir(creatingDirctry);
        }

        creatingDirctry.append("/").append(ui->tWSelectClass->currentItem()->text(0));
        if(!QDir(creatingDirctry).exists())
        {
            QDir().mkdir(creatingDirctry);
        }

        //creating studentinfo file path and sent to class
        creatingDirctry.append("/").append(ui->lWStudent->currentItem()->text()).append(".xml");

        addStudentInfromation = new AddStudentInfromation(0,ui->lWStudent->currentItem()->text(),creatingDirctry);
        addStudentInfromation->setModal(false);
        addStudentInfromation->exec();

    }







}
