#ifndef CLASSMANAGE_H
#define CLASSMANAGE_H

#include <QDialog>
#include "selectpaperformark.h"

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
    
private slots:
    void on_pBMarkPapers_clicked();

private:
    Ui::ClassManage *ui;
};

#endif // CLASSMANAGE_H
