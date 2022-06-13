#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->firstname->setText("");
    ui->lastname->setText("");

    connect(ui->getNameBtn,SIGNAL(clicked()),this,SLOT(getFullName()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(clear()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::getFullName()
{
    fullname = ui->firstname->text()+ui->lastname->text();
    ui->fullname->setText(fullname);
}

void Widget::clear()
{
    ui->firstname->clear();
    ui->lastname->clear();
    ui->fullname->clear();
}
