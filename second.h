#ifndef SECOND_H
#define SECOND_H

#include <QDialog>
#include "addtask.h"

namespace Ui {
class second;
}

class second : public QDialog
{
    Q_OBJECT

public:
    explicit second(QWidget *parent = nullptr);
    ~second();

public slots:
    void openWindow();
private slots:
    void AddItemClickLabel();
    void ExitItemClickLabel();

private:
    Ui::second *ui;
    AddTask *Task;
};

#endif // SECOND_H
