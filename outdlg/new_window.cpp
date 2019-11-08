#include "new_window.h"
#include "ui_new_window.h"
#include <QDebug>
New_window::New_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_window)
{
    ui->setupUi(this);
}

New_window::~New_window()
{
    delete ui;
}

void New_window::on_pushButton_clicked()
{
    qDebug()<<"come on here";
}
