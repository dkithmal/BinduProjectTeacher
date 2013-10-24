#ifndef MANAGECLASSES_H
#define MANAGECLASSES_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class ManageClasses;
}

class ManageClasses : public QWidget
{
    Q_OBJECT
    
public:
    explicit ManageClasses(QWidget *parent = 0);
    ~ManageClasses();
    QString filepath;
    QString newGradeFolderPath;

    
private slots:
    void on_pBAddGrade_clicked();

    void on_tWManage_currentChanged(int index);

    void on_pBCreateClass_clicked();

    void on_cBSelectGrade_3_currentIndexChanged(const QString &arg1);

    void on_pBAddStudent_clicked();

private:
    Ui::ManageClasses *ui;
};

#endif // MANAGECLASSES_H
