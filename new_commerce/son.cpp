#include "son.h"
#include "ui_son.h"
son::son(QWidget *parent)
    : QWidget(parent), ui(new Ui::son)
{
    ui->setupUi(this);
    QPushButton *button = new QPushButton("Button");
    button->setFixedSize(100, 50);
    connect(ui->getbackButton,SIGNAL(clicked()),this,SLOT(sSlot()));
}

son::~son()
{
    delete ui;
}

void son::sSlot()
{
    emit sSignal();
}

void son::on_signalButton_clicked()
{
    if(ui->signalButton->text() == "+")
    {
        ui->signalButton->setFixedSize(30,20);//固定样式
        ui->signalButton->setStyleSheet(
            "QPushButton{"
            "color:rgba(255,0,0);"//红色
            "border: 2px solid rgb(178, 34, 34);"
            "}"
            "QPushButton:hover{"
            "border: 2px solid rgb(255, 165, 0);"
            "}");
        ui->signalButton->setText("-");

    }
    else if(ui->signalButton->text()=="-")
    {
        ui->signalButton->setFixedSize(30, 20);
        ui->signalButton->setStyleSheet(
            "QPushButton{"
            "color:rgba(0,0,0);" //黑色
            "border: 2px solid rgb(54, 100, 139);"
            "}"
            "QPushButton:hover{"
            "border: 2px solid rgb(0, 150, 136);"//橘红色
            "}");
        ui->signalButton->setText("+");
}

}
void son::on_confirmButton_clicked()
{
    double amount;
    //创建一个program，记录用户输入文本
    QString program=ui->amountEdit->text();
    if(ui->signalButton->text()=="+")
    {
           amount= program.toDouble();
    }
    else if(ui->signalButton->text()=="-")
    {
        amount=-program.toDouble();
    }

}

