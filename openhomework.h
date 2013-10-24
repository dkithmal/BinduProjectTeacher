#ifndef OPENHOMEWORK_H
#define OPENHOMEWORK_H

#include <QWidget>

namespace Ui {
class OpenHomeWork;
}

class OpenHomeWork : public QWidget
{
    Q_OBJECT
    
public:
    explicit OpenHomeWork(QWidget *parent = 0);
    ~OpenHomeWork();
    
private:
    Ui::OpenHomeWork *ui;
};

#endif // OPENHOMEWORK_H
