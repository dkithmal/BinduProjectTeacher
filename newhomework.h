#ifndef NEWHOMEWORK_H
#define NEWHOMEWORK_H

#include <QWidget>

namespace Ui {
class NewHomeWork;
}

class NewHomeWork : public QWidget
{
    Q_OBJECT
    
public:
    explicit NewHomeWork(QWidget *parent = 0);
    ~NewHomeWork();
    
private:
    Ui::NewHomeWork *ui;
};

#endif // NEWHOMEWORK_H
