#ifndef MANAGECLASSES_H
#define MANAGECLASSES_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>

namespace Ui {
class ManageClasses;
}

class ManageClasses : public QWidget
{
    Q_OBJECT
    
public:
    explicit ManageClasses(QWidget *parent = 0);
    ~ManageClasses();
    
private slots:
    void on_pBAddGrade_clicked();

private:
    Ui::ManageClasses *ui;
};

#endif // MANAGECLASSES_H
