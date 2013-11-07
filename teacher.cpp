#include "teacher.h"
//const QString Teacher::filepath=QString("D:/dk work/Motarola/Bindu New/Administration/Admin.xml");

Teacher::Teacher(QWidget *parent)
	: QWidget(parent)
{

	ui.setupUi(this);

    ui.lWSettings->setHidden(true);
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
   ui.pBSettings->setIcon(cBSettings);
    QSize size2(30,30);
    ui.pBSettings->setIconSize(size2);
    ui.lWSettings->setStyleSheet( "background-color: rgba(0,0,0, 80%); color:Azure;");


   ui.wHeader->setStyleSheet(" background-color:black ;");
   ui.lClock->setStyleSheet(" color:Azure ;");





   //create activity icons
   QPixmap homeWorktoolPM(":/binduTeacher/new/imgs/hw.png");

   QIcon homeWorktoolIcon(homeWorktoolPM);
   ui.pBHomeWork->setIcon(homeWorktoolIcon);
   ui.pBHomeWork->setIconSize(homeWorktoolPM.rect().size());

   QPixmap homeDownloadlPM(":/binduTeacher/new/imgs/dm.png");
   QIcon homeDownloadIcon(homeDownloadlPM);
   ui.pBUpload->setIcon(homeDownloadIcon);
   ui.pBUpload->setIconSize(homeDownloadlPM.rect().size());

   QPixmap homeClassManagePM(":/binduTeacher/new/imgs/cm.png");
   QIcon homeClassManageIcon(homeClassManagePM);
   ui.pBManager->setIcon(homeClassManageIcon);
   ui.pBManager->setIconSize(homeClassManagePM.rect().size());

   ui.groupBox->setStyleSheet("background-color: rgba(0,0,0, 80%); ");


 ui.lWSettings->addItem(new QListWidgetItem(QIcon(":/binduTeacher/new/imgs/addclass.png"), "Add Class"));
 ui.lWSettings->addItem(new QListWidgetItem(QIcon(":/binduTeacher/new/imgs/addsubject.png"), "Add Subject"));
 ui.lWSettings->addItem(new QListWidgetItem(QIcon(":/binduTeacher/new/imgs/shutdown.png"), "Shut Down"));
 QSize sizeforSettingList(20,20);
 ui.lWSettings->setIconSize(sizeforSettingList);




	
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
        //ui.lWSettings->setCurrentIndex(0);

        ui.lWSettings->setHidden(true);
        manageClasses->exec();
        //manageClasses->show();



    }
    if(index==2)
    {
        subjectManage = new SubjectManage;
        subjectManage->setModal(false);

        ui.lWSettings->setHidden(true);
        subjectManage->exec();



    }

}

void Teacher::on_pBUpload_clicked()
{
    newUploadOrDownload= new NewUploadOrDownload;
    newUploadOrDownload->setModal(false);
    newUploadOrDownload->exec();


}

void Teacher::on_pBManager_clicked()
{
    classManage = new ClassManage;
    classManage->setModal(false);
    classManage->exec();
}

void Teacher::on_pBSettings_clicked()
{

    if(ui.lWSettings->isHidden())
    {
        ui.lWSettings->setHidden(false);
    }
    else
    {
        ui.lWSettings->setHidden(true);

    }

}

void Teacher::on_lWSettings_clicked(const QModelIndex &index)
{
    if(ui.lWSettings->currentItem()->text()=="Add Class")
    {
        manageClasses = new ManageClasses;
        manageClasses->setModal(false);


        ui.lWSettings->setHidden(true);
        manageClasses->exec();




    }
    if(ui.lWSettings->currentItem()->text()=="Add Subject")
    {
        subjectManage = new SubjectManage;
        subjectManage->setModal(false);
        ui.lWSettings->setHidden(true);
        subjectManage->exec();



    }

}
