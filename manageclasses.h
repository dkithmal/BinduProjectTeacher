#ifndef MANAGECLASSES_H
#define MANAGECLASSES_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class ManageClasses;
}

class ManageClasses : public QDialog
{
    Q_OBJECT
    
public:
    explicit ManageClasses(QDialog *parent = 0);
    ~ManageClasses();
    QString filepath;
    QString basicPath;
    bool removeDir(const QString &dirName);

    
private slots:
    void on_pBAddGrade_clicked();

    void on_tWManage_currentChanged(int index);

    void on_pBCreateClass_clicked();

    void on_cBSelectGrade_3_currentIndexChanged(const QString &arg1);

    void on_pBAddStudent_clicked();

    void on_cBSelectGradeForRClass_currentIndexChanged(int index);



    void on_cBSelectGradeFRStudent_currentIndexChanged(int index);

    void on_cBSelectClassFRStudent_currentIndexChanged(int index);

    void on_pBRemoveGrade_clicked();

    void on_pBRemoveClass_clicked();

    void on_pBRemoveStudent_clicked();

private:
    Ui::ManageClasses *ui;
};

#endif // MANAGECLASSES_H
