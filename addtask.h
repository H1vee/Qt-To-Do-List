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
public slots:
    QString getTaskName();
    QString getTaskDescription();
    QDate   getDeadLine();

signals:
    void taskAdded(const QString &TaskName,const QString &TaskDescription,const QDate &DeadLine);
private slots:
    void OKButtonClick();
private:
    Ui::AddTask *ui;


};

#endif // ADDTASK_H
