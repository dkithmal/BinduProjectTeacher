#ifndef NEWNOTECREATING_H
#define NEWNOTECREATING_H

#include <QMainWindow>
#include <QTableWidget>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include <QtWidgets>
#include <QtGui>

namespace Ui {
class NewNoteCreating;
}

class NewNoteCreating : public QWidget
{
    Q_OBJECT
    
public:
    explicit NewNoteCreating(QWidget *parent = 0,QString filePath=NULL);
    ~NewNoteCreating();
    QString noteCrationPath;
    
private slots:
    void on_pBSaveAndClose_clicked();

private:
    Ui::NewNoteCreating *ui;
};

#endif // NEWNOTECREATING_H
