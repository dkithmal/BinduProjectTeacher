#ifndef TEACHER_H
#define TEACHER_H

#include <QtWidgets>
#include <QTime>
#include <QTimer>
#include "ui_teacher.h"
#include "homeworktool.h"
#include "manageclasses.h"
#include "subjectmanage.h"
#include "newuploadordownload.h"
#include "classmanage.h"

class Teacher : public QWidget
{
	Q_OBJECT

public:
	Teacher(QWidget *parent = 0);
	~Teacher();
	//void showTime();
    HomeWorkTool *homeWorkTool;
    ManageClasses *manageClasses;
    SubjectManage *subjectManage;
    NewUploadOrDownload *newUploadOrDownload;
    ClassManage *classManage;

   // static const QString filepath ;


private:
	Ui::TeacherClass ui;


private slots:
	void showTime();
    void on_pBHomeWork_clicked();
    void on_cBSettings_currentIndexChanged(int index);
    void on_pBUpload_clicked();
    void on_pBManager_clicked();
};

#endif // TEACHER_H
