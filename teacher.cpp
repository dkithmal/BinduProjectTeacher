#include "teacher.h"
//const QString Teacher::filepath=QString("D:/dk work/Motarola/Bindu New/Administration/Admin.xml");

Teacher::Teacher(QWidget *parent)
	: QWidget(parent)
{

	ui.setupUi(this);
    //QWidget::showFullScreen();



	//set time
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start(1000);

	showTime();

    //to remove all buttons
   //this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

    //this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    //this->sizeHint();
	
}


Teacher::~Teacher()
{

}

void Teacher::showTime()
{
	QTime time = QTime::currentTime();
	QString text = time.toString("hh:mm");
	if ((time.second() % 2) == 0)
		text[2] = ' ';
    ui.lcdNClock->display(text);
}

void Teacher::on_pBHomeWork_clicked()
{
    homeWorkTool= new HomeWorkTool;
    homeWorkTool->setModal(false);
    homeWorkTool->exec();
    //homeWorkTool->show();

}

void Teacher::on_cBSettings_currentIndexChanged(int index)
{
    if(index==1)
    {
        manageClasses = new ManageClasses;
        manageClasses->setModal(false);
        ui.cBSettings->setCurrentIndex(0);

        manageClasses->exec();
        //manageClasses->show();



    }
    if(index==2)
    {
        subjectManage = new SubjectManage;
        subjectManage->setModal(false);
        ui.cBSettings->setCurrentIndex(0);

        subjectManage->exec();
        //subjectManage->show();


    }

}

void Teacher::on_pBUpload_clicked()
{
    newUploadOrDownload= new NewUploadOrDownload;
    newUploadOrDownload->setModal(false);
    newUploadOrDownload->exec();
    //newUploadOrDownload->show();

}

void Teacher::on_pBManager_clicked()
{
    classManage = new ClassManage;
    classManage->setModal(false);
    classManage->exec();
}
