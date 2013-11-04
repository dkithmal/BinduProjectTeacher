#ifndef CLASSMANAGE_H
#define CLASSMANAGE_H

#include <QDialog>
#include "selectpaperformark.h"
#include "selectstuforadddetails.h"
#include "selectstudentforview.h"

namespace Ui {
class ClassManage;
}

class ClassManage : public QDialog
{
    Q_OBJECT
    
public:
    explicit ClassManage(QWidget *parent = 0);
    ~ClassManage();
    SelectPaperForMark *selectPaperForMark;
    SelectStuForAddDetails *selectStuForAddDetails;
    SelectStudentForView *selectStudentForView;
    
private slots:
    void on_pBMarkPapers_clicked();

    void on_pBEditStudent_clicked();

    void on_pBStudentProgress_clicked();

private:
    Ui::ClassManage *ui;
};

#endif // CLASSMANAGE_H
