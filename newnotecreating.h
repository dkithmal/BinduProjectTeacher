#ifndef NEWNOTECREATING_H
#define NEWNOTECREATING_H

#include <QMainWindow>
#include <QDialog>
#include <QTableWidget>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QtGui>

namespace Ui {
class NewNoteCreating;
}

class NewNoteCreating : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewNoteCreating(QDialog *parent = 0,QString filePath=NULL);
    ~NewNoteCreating();
    QString noteCrationPath;
    
private slots:
    void on_pBSaveAndClose_clicked();

private:
    Ui::NewNoteCreating *ui;
};

#endif // NEWNOTECREATING_H
