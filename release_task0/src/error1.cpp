#include "error1.h"
#include "ui_error1.h"
#include <widget.h>

error1::error1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error1)
{
    ui->setupUi(this);

}

error1::~error1()
{
    delete ui;
}

void error1::on_existButton_clicked()
{
    this->flag = true;
    this->close();
}
