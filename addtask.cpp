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

void AddTask::OKButtonClick(){
    QMessageBox messageBox;

    if(ui->TaskNameEdit->text()==""){
        messageBox.warning(this,"Empty Name","Відсутня назва завдання.");
        ui->TaskNameEdit->setFocus();
        return;
    }

    if(ui->TaskDescriptionEdit->text()==""){
        messageBox.warning(this,"Empty Description","Відсутній опис завдання.");
        ui->TaskDescriptionEdit->setFocus();
        return;
    }

    if(ui->DeadLineEdit->date()<QDate::currentDate()){
        messageBox.warning(this,"Incorrect Date","Вказана не коректна дата.");
        ui->DeadLineEdit->setFocus();
        return;
    }
    accept();
}


