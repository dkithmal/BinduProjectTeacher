#include "manageclasses.h"
#include "ui_manageclasses.h"

ManageClasses::ManageClasses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageClasses)
{
    ui->setupUi(this);
    ui->tWManage->setCurrentIndex(0);
}

ManageClasses::~ManageClasses()
{
    delete ui;
}

void ManageClasses::on_pBAddGrade_clicked()
{
    QString filepath ="D:/dk work/Motarola/Bindu/Administration/GradesAndClassManage/GradesAndClassManage.xml";
    QFile newPaperFile(filepath);
    if(!newPaperFile.open(QFile::Append| QFile::Text))
    {

    }
    else
    {
        QDomDocument document;
        document.setContent(&newPaperFile);
        QDomElement root= document.firstChildElement();
        if(newPaperFile.size()==0)
        {
            root = document.createElement("GradesAndClasses");
            QDomElement grade= document.createElement("Grade");
            grade.setAttribute("GradeName",ui->lEGradeName->text());
            root.appendChild(grade);

            qDebug() <<"fdfdfdfdf";

        }
        else
        {
            QDomElement grade= document.createElement("Grade");
            grade.setAttribute("GradeName",ui->lEGradeName->text());
            root.appendChild(grade);
            qDebug() <<"fdfdffdfdfdfdfdf";




        }


        document.appendChild(root);

        QTextStream stream(&newPaperFile);
        stream <<document.toString();
        newPaperFile.close();


    }


}
