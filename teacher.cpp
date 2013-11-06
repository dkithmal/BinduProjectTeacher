#include "teacher.h"
//const QString Teacher::filepath=QString("D:/dk work/Motarola/Bindu New/Administration/Admin.xml");

Teacher::Teacher(QWidget *parent)
	: QWidget(parent)
{

	ui.setupUi(this);
    //QWidget::showFullScreen();

    //to remove all buttons
   //this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

    //this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    //this->sizeHint();

	//set time
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start(1000);

	showTime();










    //gui deco starting

    //to full screan view image
    QPalette p = palette();

    //Load image to QPixmap, Give full path of image
   QPixmap pixmap1(":/binduTeacher/new/imgs/homePage.jpeg"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location

   //resize image if it is larger than screen size.
   QDesktopWidget* desktopWidget = QApplication::desktop();
   QRect rect = desktopWidget->availableGeometry();

   QSize size(rect.width(), rect.height()+40);
   //resize as per your requirement..
   QPixmap pixmap(pixmap1.scaled(size));

   p.setBrush(QPalette::Background,  pixmap);
   QWidget::setPalette(p);


   //
   QPixmap pixmap2(":/binduTeacher/new/imgs/settings_symbol.png");
   QIcon cBSettings(pixmap2);
   ui.cBSettings->setItemIcon(0,cBSettings);
   ui.cBSettings->setItemIcon(1,cBSettings);
   ui.cBSettings->setItemIcon(2,cBSettings);
   ui.cBSettings->setItemIcon(3,cBSettings);
  // ui.cBSettings->setIconSize(homeDownloadlPM.rect().size());

   ui.wHeader->setStyleSheet(" background-color:black ;");
   ui.lClock->setStyleSheet(" color:Azure ;");
  // ui.cBSettings->setStyleSheet ("QComboBox::drop-down {border-width: 0px;} QComboBox::down-arrow {image: url(noimg); border-width: 0px;  color:Azure ; }");
  // ui.cBSettings->setStyleSheet("color:#ccc; background-color:#333;  selection-background-color:#1c1c1c; selection-color: #ccc; ");
   ui.cBSettings->setStyleSheet("down-arrow {image: url(noimg);  font-size:  20;");
   QSize size2(30,30);
   ui.cBSettings->setIconSize(size2);
  // ui.cBSettings->setFont(QFont ("Courier New", 30));




   //create activity icons
   QPixmap homeWorktoolPM(":/binduTeacher/new/imgs/hw.png");
   homeWorktoolPM.setDevicePixelRatio(Qt::KeepAspectRatio);
   QIcon homeWorktoolIcon(homeWorktoolPM);
   ui.pBHomeWork->setIcon(homeWorktoolIcon);
   ui.pBHomeWork->setIconSize(homeWorktoolPM.rect().size());

   QPixmap homeDownloadlPM(":/binduTeacher/new/imgs/dm.png");
   homeDownloadlPM.setDevicePixelRatio(Qt::KeepAspectRatio);
   QIcon homeDownloadIcon(homeDownloadlPM);
   ui.pBUpload->setIcon(homeDownloadIcon);
   ui.pBUpload->setIconSize(homeDownloadlPM.rect().size());

   QPixmap homeClassManagePM(":/binduTeacher/new/imgs/cm.png");
   homeClassManagePM.setDevicePixelRatio(Qt::KeepAspectRatio);
   QIcon homeClassManageIcon(homeClassManagePM);
   ui.pBManager->setIcon(homeClassManageIcon);
   ui.pBManager->setIconSize(homeClassManagePM.rect().size());

   ui.groupBox->setStyleSheet("background-color: rgba(0,0,0, 80%); ");

  // QPalette pal = this->palette();
  // pal.setBrush(QPalette::Base, Qt::transparent);
 // ui.groupBox->setPalette(pal);


	
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
    //ui.lcdNClock->display(text);
    ui.lClock->setText(text);
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
