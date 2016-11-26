#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QValidator>
#include<QLineEdit>
#include<QRegExp>
#include<qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp regExp("^(-?\\d+)(\\.\\d+)?$");    //浮点数
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

float number=0;
int flag=0;  //用来检测算符的输入 1\2\3\4 --- 加\减\乘\除

//void abc()
//{
//    if(flag) ui->lineEdit->clear();
//    if(ui->lineEdit->text()==NULL)
//    {
//        flag=0;
//        dot=false;
//    }
//}

//只要lineedit为空 dot=false  flag=0 ？？？？？？？？？？？？


void MainWindow::on_pushButton_1_clicked()
{
    if(flag) ui->lineEdit->clear();
//    if(ui->lineEdit->text()==NULL)
//    {
//        flag=0;
//        dot=false;
//        number=0;
//    }
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_1->text());

}

void MainWindow::on_pushButton_2_clicked()
{
    if(flag) ui->lineEdit->clear();

    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_2->text());
}

void MainWindow::on_pushButton_3_clicked()
{
    if(flag) ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_3->text());
}

void MainWindow::on_pushButton_4_clicked()
{
    if(flag) ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_4->text());
}

void MainWindow::on_pushButton_5_clicked()
{
    if(flag) ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_5->text());
}

void MainWindow::on_pushButton_6_clicked()
{
    if(flag) ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_6->text());
}

void MainWindow::on_pushButton_7_clicked()
{
    if(flag) ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_7->text());
}

void MainWindow::on_pushButton_8_clicked()
{
    if(flag) ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_8->text());
}

void MainWindow::on_pushButton_9_clicked()
{
    if(flag) ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_9->text());
}

void MainWindow::on_pushButton_0_clicked()
{
    if(flag) ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_0->text());
}


//小数点
bool dot=false;  //检测小数点是否已输入
void MainWindow::on_pushButton_dot_clicked()
{
    if(ui->lineEdit->text()==NULL)
        ui->lineEdit->setText("0");
    else if(dot==true)
    {
        ui->lineEdit_hint->setText("请勿重复输入小数点~");
        return;
    }
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_dot->text());
    dot=true;
    return;
}

//AC
void MainWindow::on_pushButton_ac_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_hint->clear();
    number=0;
    flag=0;
    dot=false;
}

// +/-
int flag_0=1;  //检测数的正负号，默认为正
void MainWindow::on_pushButton_00_clicked()
{
    if(flag_0==1)
        ui->lineEdit->setText("-"+ui->lineEdit->text());
    else
    {
        QString a=ui->lineEdit->text();
        a=a.remove(0,1);
        ui->lineEdit->setText(a);
        flag_0=1;
        return;
    }
    flag_0=0;
    return;
}

//退格
void MainWindow::on_pushButton_back_clicked()
{
    QString a=ui->lineEdit->text();
    a=a.left(a.length()-1);
    ui->lineEdit->setText(a);
}

// %
void MainWindow::on_pushButton_per_clicked()
{
    float num=ui->lineEdit->text().toFloat();
    float num1=num/100;

    QString n=QString::number(num1);
    ui->lineEdit->setText(n);
}

// +

void MainWindow::on_pushButton_add_clicked()
{
    flag=1;
    float a,b;
    a=ui->lineEdit->text().toFloat();
    number+=a;
    b=ui->lineEdit->text().toFloat();
    number+=b;
    qDebug()<<number;///////
}

// -
void MainWindow::on_pushButton_min_clicked()
{
    float a,b;
    a=ui->lineEdit->text().toFloat();
    number-=a;

    b=ui->lineEdit->text().toFloat();
    number-=b;
    qDebug()<<number;///////
}
// x
// chu
// =
void MainWindow::on_pushButton_eq_clicked()
{
    QString n=QString::number(number);
    ui->lineEdit->setText(n);
}
