#ifndef EDITNOTE_H
#define EDITNOTE_H

#include <QtWidgets>
#include <QDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class EditNote;
}

class EditNote : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditNote(QDialog *parent = 0,QString filePath=NULL);
    ~EditNote();
    void showExistingContent();
    QString noteFilePath;
    
private slots:
    void on_pBSaveAndClose_clicked();

private:
    Ui::EditNote *ui;
};

#endif // EDITNOTE_H
