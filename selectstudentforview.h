#ifndef SELECTSTUDENTFORVIEW_H
#define SELECTSTUDENTFORVIEW_H

#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "studentinformation.h"

namespace Ui {
class SelectStudentForView;
}

class SelectStudentForView : public QDialog
{
    Q_OBJECT
    
public:
    explicit SelectStudentForView(QWidget *parent = 0);
    ~SelectStudentForView();
    void setClassList();


    QString filepath;
    QString basicPath;
    StudentInformation *studentInformation;
    
private slots:
    void on_tWSelectClass_clicked(const QModelIndex &index);

    void on_pBViewStudent_clicked();

private:
    Ui::SelectStudentForView *ui;
};

#endif // SELECTSTUDENTFORVIEW_H
