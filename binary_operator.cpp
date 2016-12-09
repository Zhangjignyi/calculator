#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QValidator>
#include<QLineEdit>
#include<QRegExp>
#include<qdebug.h>
#include<math.h>

//双目运算

// +
void MainWindow::on_pushButton_add_clicked()
{
    is_1=true;  //有加号
    option("+");
}

// -
void MainWindow::on_pushButton_min_clicked()
{
    is_1=true;  //有减号
    option("-");

}

// x
void MainWindow::on_pushButton_mul_clicked()
{
    is_2=true;  //记录有乘号
    option("*");

}

// /
void MainWindow::on_pushButton_dvd_clicked()
{
    is_2=true; //记录有除号
    option("/");

}

// =
void MainWindow::on_pushButton_eq_clicked()
{
    if(isleft||(is_1&&is_2))
    {

        ui->lineEdit_1->setText(ui->lineEdit_1->text()+ui->lineEdit->text());
        postfix();
        sum();
        init();
        isleft=false;
        Flag=1;
    }
    else
    {

        if(!new_num)
        {

            ui->lineEdit_1->setText(ui->lineEdit_1->text()+ui->lineEdit->text());
            ui->lineEdit->setText(QString::number(calculate(),'g',12));
        }
        else
            ui->lineEdit->setText(QString::number(calculate(),'g',12));
        ui->lineEdit_1->clear();
        is_1=false;
        is_2=false;
    }
    cur_op="=";  ////

}

// ^
void MainWindow::on_pushButton_xy_clicked()
{
    flag=2;
    isleft=true;
    option("^");

}

//√
void MainWindow::on_pushButton_sy_clicked()
{
    flag=3;
    calculate();
//    if(number<0||number==0)
//    {
//        ui->lineEdit->clear();
//        ui->lineEdit->setText(QString::number(number,'g',12));
//        ui->lineEdit_1->setText("请输入正数");
//        cur_op="";
//        dot=false;
//        set_new_num(true);
//        Flag=1;

//    }
//    else
        option("_√");
}

// logy
void MainWindow::on_pushButton_logy_clicked()
{
    flag=4;
    calculate();
    if(number<0||number==0)
    {
        ui->lineEdit->clear();
        ui->lineEdit->setText(QString::number(number,'g',12));
        ui->lineEdit_1->setText("请输入正数");
        cur_op="";
        dot=false;
        set_new_num(true);
        Flag=1;

    }
    else
        option("log_");
}

