#include "widget.h"
#include "ui_widget.h"
#include <string>
#include "allFunc.h"
#include <iostream>
#include "error1.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->radioMode, &QRadioButton::toggled, this, &Widget::changeMode);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_okButton_clicked()
{
    //获取所需的数据
    std::string inputInfo = (ui->lineEditInput->text()).toStdString();
    std::string outputInfo = (ui->lineEditOutput->text()).toStdString();
    std::string strInfo = (ui->lineEditStr->text()).toStdString();
    if(this->modeType)
        encodeFunc(*this, inputInfo, outputInfo, strInfo);
    else
        decodeFunc(*this, inputInfo, outputInfo, strInfo);

    if(this->errorType == 1){
        error1 e1;
        e1.exec();
        this->errorType = 0;  //别忘了重置回去
    }
    else
        this->close();

}

void Widget::changeMode(){
    this->modeType = ui->radioMode->isChecked();
}

void Widget::on_cancelButton_clicked()
{
    this->close();
}



void Widget::on_radioMode_clicked(bool checked)
{
    //因为已经设置了radioMode选中与否的行为了，这里设置为空
}
