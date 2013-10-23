#include "teacher.h"

Teacher::Teacher(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
//	QWidget::showFullScreen();

	//QFont font = ui.pBHomeWork->font();
	//font.setPointSize(20);
	//ui.pBHomeWork->setFont(font);
	//ui.pBManager->setFont(font);
	//ui.pBUpload->setFont(font);

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
