#include "second.h"
#include "ui_second.h"
#include"addtask.h"

second::second(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::second)
{
    ui->setupUi(this);
    ui->DeletePushButton->setVisible(false);
    ui->EditPushButton->setVisible(false);
    Task = new AddTask();
    connect(ui->ExitPushButton,&QPushButton::clicked,this,&second::ExitItemClickLabel);
    connect(ui->AddPushButton,&QPushButton::clicked,this,&second::AddItemClickLabel);

}

second::~second()
{
    delete ui;
    delete Task;
}
void second::openWindow(){
    this->show();
}

void second::ExitItemClickLabel(){
    QApplication::quit();
}

void second::AddItemClickLabel(){
    Task->show();
}
