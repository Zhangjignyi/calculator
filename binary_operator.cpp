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
         ui->lineEdit->setText(QString::number(calculate(),'g',12));
    }
    else
        ui->lineEdit->setText(QString::number(calculate(),'g',12)); //ui->lineEdit->setText(QString::number(number,'g',12));
    ui->lineEdit_1->clear();
    cur_op="";
    dot=false;
    set_new_num(true);

}

// ^
void MainWindow::on_pushButton_xy_clicked()
{
    flag=2;
    option("^");

}

//√
void MainWindow::on_pushButton_sy_clicked()
{
    flag=3;
    option("√");
}


