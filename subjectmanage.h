#ifndef SUBJECTMANAGE_H
#define SUBJECTMANAGE_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class SubjectManage;
}

class SubjectManage : public QDialog
{
    Q_OBJECT
    
public:
    explicit SubjectManage(QDialog *parent = 0);
    ~SubjectManage();
    void setDefaultCB();
    QString filepath;
    QString basicPath;
    bool removeDir(const QString &dirName);
    
private slots:
       void on_pBAddSubject_clicked();

       void on_tWSubjectManage_currentChanged(int index);

       void on_cBSelectGradeRemove_currentIndexChanged(int index);

       void on_pBRemove_clicked();

       void on_cBSelectGradeAdd_currentIndexChanged(int index);

       void on_cBSelectClassToRSub_currentIndexChanged(int index);

private:
    Ui::SubjectManage *ui;
};

#endif // SUBJECTMANAGE_H
