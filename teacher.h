#ifndef TEACHER_H
#define TEACHER_H

#include <QtWidgets/QWidget>
#include <QTime>
#include <QTimer>
#include "ui_teacher.h"

class Teacher : public QWidget
{
	Q_OBJECT

public:
	Teacher(QWidget *parent = 0);
	~Teacher();
	//void showTime();

private:
	Ui::TeacherClass ui;

private slots:
	void showTime();
};

#endif // TEACHER_H
