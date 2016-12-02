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


void MainWindow::judge(int n)   //输入数字前判断是否已输入算符  n代表要键入的数字
{

    if (new_num ||ui->lineEdit->text() == "0")
        ui->lineEdit->clear();
    QString N=QString("%1").arg(n);
    ui->lineEdit->setText(ui->lineEdit->text()+N);
    set_new_num(false);
}

void MainWindow::option(const QString& op) //输入算符前判断执行上一步算符
{
    if(!new_num||ui->lineEdit_1->text().isEmpty())
    {
        int m=ui->lineEdit->text().length()-1;
        if(ui->lineEdit->text().at(m)=='.')
           {
            QString a=ui->lineEdit->text();
            a=a.left(a.length()-1);
            ui->lineEdit->setText(a);    //删除小数点
        }
        ui->lineEdit_1->setText(ui->lineEdit_1->text()+ui->lineEdit->text()+op);

        ui->lineEdit->setText(QString::number(calculate()));
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
}


// +

void MainWindow::on_pushButton_add_clicked()
{
    option("+");
}

// -
void MainWindow::on_pushButton_min_clicked()
{
    option("-");

}
// x
void MainWindow::on_pushButton_mul_clicked()
{
    option("*");

}
// /
void MainWindow::on_pushButton_dvd_clicked()
{
    option("/");

}
// =
void MainWindow::on_pushButton_eq_clicked()
{
    if(!new_num)
    {
         ui->lineEdit_1->setText(ui->lineEdit_1->text()+ui->lineEdit->text());
         ui->lineEdit->setText(QString::number(calculate()));
    }
    else
        ui->lineEdit->setText(QString::number(number));
    ui->lineEdit_1->clear();
    cur_op="";
    dot=false;
    set_new_num(true);

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

    return number = ui->lineEdit->text().toDouble();

}

void MainWindow::set_new_num(bool new_n)
{
    new_num = new_n;
    if (new_n) {
        ui->lineEdit->setFrame(false);
    } else {
        ui->lineEdit->setFrame(true);
    }
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
    ui->lineEdit_1->clear();
    ui->lineEdit->setText("0");
    cur_op="";
    number=0;
    set_new_num(true);
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


