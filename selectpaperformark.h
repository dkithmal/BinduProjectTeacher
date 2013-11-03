#ifndef SELECTPAPERFORMARK_H
#define SELECTPAPERFORMARK_H

#include <QDialog>
#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "papersummary.h"

namespace Ui {
class SelectPaperForMark;
}

class SelectPaperForMark : public QDialog
{
    Q_OBJECT
    
public:
    explicit SelectPaperForMark(QWidget *parent = 0);
    ~SelectPaperForMark();
    QString filepath;
    QString basicPath;
    void setSubjectToTree();
    QString getPaperType(QString paperXmlPath);
    void toMarkMcqPaper(QString paperXmlPath);
    QStringList getTeacherAnswers(QString answerPapersPath);
    void toUpdateMarksInPaperXml(QString paperXmlpath, QString studentName,QString marks);
    Papersummary *papersummary;
    
private slots:
    void on_tWSelectSubject_clicked(const QModelIndex &index);

    void on_pBMarkPaper_clicked();

private:
    Ui::SelectPaperForMark *ui;
};

#endif // SELECTPAPERFORMARK_H
