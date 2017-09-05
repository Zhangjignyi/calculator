#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QValidator>
#include<QLineEdit>
#include<QRegExp>
#include<qdebug.h>
#include<math.h>


//π
void MainWindow::on_pushButton_pi_clicked()
{
    ui->pushButton_2add->setEnabled(true);
    ui->pushButton_2min->setEnabled(true);
    ui->pushButton_2mul->setEnabled(true);
    ui->pushButton_2dvd->setEnabled(true);
    ui->pushButton_2eq->setEnabled(true);
    if(left>0)
        ui->pushButton_r->setEnabled(true);
    if (cur_op == "=")   //若之前输入了=，则清空提示框
    {
        ui->lineEdit_1->clear();
        cur_op="";
    }
    ui->lineEdit->setText(QString::number(M_PI,'g',12));
    set_new_num(false);
    Flag=1;
}

//e
void MainWindow::on_pushButton_e_clicked()
{
    ui->pushButton_2add->setEnabled(true);
    ui->pushButton_2min->setEnabled(true);
    ui->pushButton_2mul->setEnabled(true);
    ui->pushButton_2dvd->setEnabled(true);
    ui->pushButton_2eq->setEnabled(true);
    if(left>0)
        ui->pushButton_r->setEnabled(true);
    if (cur_op == "=")   //若之前输入了=，则清空提示框
    {
        ui->lineEdit_1->clear();
        cur_op="";
    }
    ui->lineEdit->setText(QString::number(exp(1),'g',12));
    set_new_num(false);
    Flag=1;
}

