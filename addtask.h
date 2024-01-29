#ifndef ADDTASK_H
#define ADDTASK_H
#include"QString"
#include <QDialog>
#include "QDateEdit"
namespace Ui {
class AddTask;
}

class AddTask : public QDialog
{
    Q_OBJECT

public:
    explicit AddTask(QWidget *parent = nullptr);
    ~AddTask();
    QString getTaskName();
    QString getTaskDescription();
    QDate getDeadLine();
public slots:

private slots:
    void OKButtonClick();
private:
    Ui::AddTask *ui;


    bool checkName(QString Name);
    bool checkTaskDescription(QString Description);

};

#endif // ADDTASK_H
