#include "addtask.h"
#include "ui_addtask.h"
#include "QMessageBox"
AddTask::AddTask(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTask)
{
    ui->setupUi(this);

    connect(ui->OKPushButton,&QPushButton::clicked,this,&AddTask::OKButtonClick);

}

AddTask::~AddTask()
{
    delete ui;

}


QString AddTask::getTaskName(){
    return ui->TaskNameEdit->text();
}

QString AddTask::getTaskDescription(){
    return ui->TaskDescriptionEdit->text();
}

QDate AddTask::getDeadLine(){
    return ui->DeadLineEdit->date();
}

void AddTask::AddTaskToMap(const QString &TaskName,const QString &TaskDescription,const QDate& DeadLine){
    TaskInfoForCheck check;
    check.TaskDesc=TaskDescription;
    check.deadLine=DeadLine;
    TaskMap[TaskName]=check;
}

void AddTask::deleteTask(const QString &TaskName){
    if(TaskMap.find(TaskName)!=TaskMap.end()){
        TaskMap.erase(TaskName);
    }
}

void AddTask::OKButtonClick(){
    QMessageBox messageBox;
    messageBox.setStyleSheet("QMessageBox {"
                             "background-color: #FFFFF;"
                             "}");
    if(ui->TaskNameEdit->text()==""){
        messageBox.setIcon(QMessageBox::Warning);
        messageBox.setWindowTitle("Empty Name");
        messageBox.setText("Відсутня назва завдання.");
        ui->TaskNameEdit->setFocus();
        messageBox.exec();

        return;
    }

    if(ui->TaskDescriptionEdit->text()==""){
        messageBox.setIcon(QMessageBox::Warning);
        messageBox.setWindowTitle("Empty Description");
        messageBox.setText("Відсутній опис завдання.");
        ui->TaskDescriptionEdit->setFocus();
        messageBox.exec();

        return;
    }

    if(ui->DeadLineEdit->date()<QDate::currentDate()){
        messageBox.setIcon(QMessageBox::Warning);
        messageBox.setWindowTitle("Wrong Date");
        messageBox.setText("Вказана некоректна дата.");
        ui->DeadLineEdit->setFocus();
        messageBox.exec();

        return;
    }

    QString TaskName = getTaskName();
    if(TaskMap.find(TaskName)!=TaskMap.end()){
        messageBox.setIcon(QMessageBox::Warning);
        messageBox.setWindowTitle("Dublicate Task");
        messageBox.setText("Таке завдання вже існує.");
        ui->TaskDescriptionEdit->setFocus();
        messageBox.exec();

        return;
    }

    AddTaskToMap(TaskName,getTaskDescription(),getDeadLine());
    emit taskAdded(TaskName,getTaskDescription(),getDeadLine());

    ui->TaskNameEdit->clear();
    ui->TaskDescriptionEdit->clear();
    ui->DeadLineEdit->clear();

    accept();
}
