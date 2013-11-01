#ifndef SUBJECTMANAGE_H
#define SUBJECTMANAGE_H

#include <QtWidgets>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class SubjectManage;
}

class SubjectManage : public QWidget
{
    Q_OBJECT
    
public:
    explicit SubjectManage(QWidget *parent = 0);
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

private:
    Ui::SubjectManage *ui;
};

#endif // SUBJECTMANAGE_H
