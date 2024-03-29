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
    QString  toMarkMcqPaper(QString paperXmlPath);
    QString  toMarkEssayMcqPaper(QString paperXmlPath);
    QStringList getTeacherAnswers(QString answerPapersPath);
    QString  toMarkEssayPaper(QString paperXmlPath);
    void toUpdateMarksInPaperXml(QString paperXmlpath, QString studentName,QString marks);
    Papersummary *papersummary;
    int totleMarksOfPaper;
    int totleMarksOfStudent;
   QString paperType;
    
private slots:
    void on_tWSelectSubject_clicked(const QModelIndex &index);

    void on_pBMarkPaper_clicked();

private:
    Ui::SelectPaperForMark *ui;
};

#endif // SELECTPAPERFORMARK_H
