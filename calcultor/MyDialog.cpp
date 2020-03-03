#include "MyDialog.h"
#include "ui_MyDialog.h"
MyDialog::MyDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MyDialog)
{
	ui->setupUi(this);

	// connect puushbutton
	this->mode=new model;
    connect(ui->btn_0,SIGNAL(clicked(bool)),this,SLOT(getBtn0()));
    connect(ui->btn_1,SIGNAL(clicked(bool)),this,SLOT(getBtn1()));
    connect(ui->btn_2,SIGNAL(clicked(bool)),this,SLOT(getBtn2()));
    connect(ui->btn_3,SIGNAL(clicked(bool)),this,SLOT(getBtn3()));
    connect(ui->btn_4,SIGNAL(clicked(bool)),this,SLOT(getBtn4()));
    connect(ui->btn_5,SIGNAL(clicked(bool)),this,SLOT(getBtn5()));
    connect(ui->btn_6,SIGNAL(clicked(bool)),this,SLOT(getBtn6()));
    connect(ui->btn_7,SIGNAL(clicked(bool)),this,SLOT(getBtn7()));
    connect(ui->btn_8,SIGNAL(clicked(bool)),this,SLOT(getBtn8()));
    connect(ui->btn_9,SIGNAL(clicked(bool)),this,SLOT(getBtn9()));
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::getBtn0()
{
    if(ui->label->text()!="0"){
        QString tmp=ui->label->text()+"0";
        ui->label->setText(tmp);
    }
}

void MyDialog::getBtn1()
{
    if(ui->label->text()=="0") ui->label->setText("");
    QString tmp=ui->label->text()+'1';
    ui->label->setText(tmp);
}

void MyDialog::getBtn2()
{
    if(ui->label->text()=="0") ui->label->setText("");
    QString tmp=ui->label->text()+'2';
    ui->label->setText(tmp);
}

void MyDialog::getBtn3()
{
    if(ui->label->text()=="0") ui->label->setText("");
    QString tmp=ui->label->text()+'3';
    ui->label->setText(tmp);
}

void MyDialog::getBtn4()
{
    if(ui->label->text()=="0") ui->label->setText("");
    QString tmp=ui->label->text()+'4';
    ui->label->setText(tmp);
}

void MyDialog::getBtn5()
{
    if(ui->label->text()=="0") ui->label->setText("");
    QString tmp=ui->label->text()+'5';
    ui->label->setText(tmp);
}

void MyDialog::getBtn6()
{
    if(ui->label->text()=="0") ui->label->setText("");
    QString tmp=ui->label->text()+'6';
    ui->label->setText(tmp);
}

void MyDialog::getBtn7()
{
    if(ui->label->text()=="0") ui->label->setText("");
    QString tmp=ui->label->text()+'7';
    ui->label->setText(tmp);
}

void MyDialog::getBtn8()
{
    if(ui->label->text()=="0") ui->label->setText("");
    QString tmp=ui->label->text()+'8';
    ui->label->setText(tmp);
}

void MyDialog::getBtn9()
{
    if(ui->label->text()=="0") ui->label->setText("");
    QString tmp=ui->label->text()+'9';
    ui->label->setText(tmp);
}

void MyDialog::on_btn_clear_clicked()
{
    ui->label->setText("0");
}

void MyDialog::on_btn_plus_clicked()
{
    mode->setNum1(ui->label->text().toInt());
    mode->setFlag(1);
    ui->label->setText("0");
}



void MyDialog::on_btn_sub_clicked()
{
    mode->setNum1(ui->label->text().toInt());
    mode->setFlag(2);
    ui->label->setText("0");
}

void MyDialog::on_btn_mul_clicked()
{
    mode->setNum1(ui->label->text().toInt());
    mode->setFlag(3);
    ui->label->setText("0");
}

void MyDialog::on_btn_div_clicked()
{
    mode->setNum1(ui->label->text().toInt());
    mode->setFlag(4);
    ui->label->setText("0");
}

void MyDialog::on_btn_equal_clicked()
{
    mode->setNum2(ui->label->text().toInt());
    ui->label->setText(mode->doExpr());
}
