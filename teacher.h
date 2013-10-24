#ifndef TEACHER_H
#define TEACHER_H

#include <QtWidgets/QWidget>
#include <QTime>
#include <QTimer>
#include "ui_teacher.h"
#include "homeworktool.h"
#include "manageclasses.h"

class Teacher : public QWidget
{
	Q_OBJECT

public:
	Teacher(QWidget *parent = 0);
	~Teacher();
	//void showTime();
    HomeWorkTool *homeWorkTool;
    ManageClasses *manageClasses;

private:
	Ui::TeacherClass ui;

private slots:
	void showTime();
    void on_pBHomeWork_clicked();
    void on_cBSettings_currentIndexChanged(int index);
};

#endif // TEACHER_H
