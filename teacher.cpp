#include "teacher.h"

Teacher::Teacher(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
//	QWidget::showFullScreen();



	//set time
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start(1000);

	showTime();

	
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
    homeWorkTool->show();

}

void Teacher::on_cBSettings_currentIndexChanged(int index)
{
    if(index==1)
    {
        manageClasses = new ManageClasses;
        manageClasses->show();

        ui.cBSettings->setCurrentIndex(0);

    }
    if(index==2)
    {
        subjectManage = new SubjectManage;
        subjectManage->show();

        ui.cBSettings->setCurrentIndex(0);
    }

}

void Teacher::on_pBUpload_clicked()
{
    newUploadOrDownload= new NewUploadOrDownload;
    newUploadOrDownload->show();

}
