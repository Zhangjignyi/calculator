#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QValidator>
#include<QLineEdit>
#include<QRegExp>
#include<qdebug.h>
#include<math.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp regExp("^(-?\\d+)(\\.\\d+)?$");    //浮点数
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//以下为简单计算器功能实现

void MainWindow::set_new_num(bool new_n)
{
    new_num = new_n;
    if (new_n) {
        ui->lineEdit->setFrame(false);
    }
    else {
        ui->lineEdit->setFrame(true);
    }
}

void MainWindow::judge(int n)   //输入数字前判断是否已输入算符  n代表要键入的数字
{
    ui->pushButton_2add->setEnabled(true);
    ui->pushButton_2min->setEnabled(true);
    ui->pushButton_2mul->setEnabled(true);
    ui->pushButton_2dvd->setEnabled(true);
    ui->pushButton_l->setEnabled(false);
    if(left==0)     ui->pushButton_2eq->setEnabled(true);
    if(left>0)      ui->pushButton_r->setEnabled(true);

    if (cur_op == "=")   //若之前输入了=，则清空提示框
    {
        ui->lineEdit_1->clear();
        ui->lineEdit->clear();
        cur_op="";
    }
    if (new_num ||ui->lineEdit->text() == "0"||flag==1)
        ui->lineEdit->clear();
    QString N=QString("%1").arg(n);
    ui->lineEdit->setText(ui->lineEdit->text()+N);
    set_new_num(false);
    flag=0;

    if(left>0) ui->pushButton_2eq->setEnabled(false);
    else if(left==0) ui->pushButton_r->setEnabled(false);
}


void MainWindow::option(const QString& op) //输入算符前判断执行上一步算符
{

    //算符后可以有数字和 （
    ui->pushButton_20->setEnabled(true);
    ui->pushButton_21->setEnabled(true);
    ui->pushButton_22->setEnabled(true);
    ui->pushButton_23->setEnabled(true);
    ui->pushButton_24->setEnabled(true);
    ui->pushButton_25->setEnabled(true);
    ui->pushButton_26->setEnabled(true);
    ui->pushButton_27->setEnabled(true);
    ui->pushButton_28->setEnabled(true);
    ui->pushButton_29->setEnabled(true);
    ui->pushButton_2dot->setEnabled(true);
    ui->pushButton_l->setEnabled(true);
    //算符后不可以有 ）和 =
    ui->pushButton_r->setEnabled(false);
    ui->pushButton_2eq->setEnabled(false);

    if(!new_num||ui->lineEdit_1->text().isEmpty())
    {
        int m=ui->lineEdit->text().length()-1;
        if(ui->lineEdit->text().at(m)=='.')  //小数不完整则删除小数点
           {
            QString a=ui->lineEdit->text();
            a=a.left(a.length()-1);
            ui->lineEdit->setText(a);
        }

        if(flag==3)
        {
            ui->lineEdit_1->setText(op+QString::number(number,'g',12));
        }
        else if(flag==4)
        {
            ui->lineEdit_1->clear();
            ui->lineEdit_1->setText(op+QString::number(number,'g',12));
        }
        else
        {
            if(cur_op=="=")
            {
                ui->lineEdit_1->setText(ui->lineEdit->text()+op);
                ui->lineEdit->clear();
                cur_op="";
            }
            else
            {
            ui->lineEdit_1->setText(ui->lineEdit_1->text()+ui->lineEdit->text()+op);
            ui->lineEdit->setText(QString::number(calculate(),'g',12));
            }
        }
        set_new_num(true);
    }
    else
    {
        ui->lineEdit_1->end(false);
        ui->lineEdit_1->backspace();
        ui->lineEdit_1->setText(ui->lineEdit_1->text()+op);
    }
    cur_op=op;
    dot=false;
    ui->lineEdit->clear();
}


// 计算结果
double MainWindow::calculate() {
    if (cur_op == "+")
        return number += ui->lineEdit->text().toDouble();
    else if (cur_op == "-")
        return number -= ui->lineEdit->text().toDouble();
    else if (cur_op == "*")
        return number *= ui->lineEdit->text().toDouble();
    else if (cur_op == "/")
        return number /= ui->lineEdit->text().toDouble();
    else if (cur_op == "=")
    {
        ui->lineEdit_1->clear();
        ui->lineEdit_1->setText(ui->lineEdit->text());  //
        ui->lineEdit->clear();
        cur_op="";
    }
    else if(cur_op=="_√")
        return number=pow(number,1/(ui->lineEdit->text().toDouble()));
    else if(cur_op=="log_")
        return number=log10(number)/log10(ui->lineEdit->text().toDouble());

    return number = ui->lineEdit->text().toDouble();


}

void MainWindow::on_pushButton_1_clicked()
{
    judge(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    judge(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    judge(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    judge(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    judge(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    judge(6);
}

void MainWindow::on_pushButton_7_clicked()
{
    judge(7);
}

void MainWindow::on_pushButton_8_clicked()
{
   judge(8);
}

void MainWindow::on_pushButton_9_clicked()
{
   judge(9);
}

void MainWindow::on_pushButton_0_clicked()
{
   judge(0);
}

//小数点
void MainWindow::on_pushButton_dot_clicked()
{
    if(ui->lineEdit->text()==NULL)
        ui->lineEdit->setText("0");
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_dot->text());
    dot=true;
    set_new_num(false);
    return;
}

//AC
void MainWindow::on_pushButton_ac_clicked()
{
    init();
    isleft=false;
    ui->pushButton_200->setEnabled(true);
    ui->lineEdit_1->clear();
    ui->lineEdit->setText("0");
    cur_op="";
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
    double num=ui->lineEdit->text().toDouble();
    double num1=num/100;
    QString n=QString::number(num1,'g',12);
    ui->lineEdit->setText(n);
}


