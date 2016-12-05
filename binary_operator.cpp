#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QValidator>
#include<QLineEdit>
#include<QRegExp>
#include<qdebug.h>
#include<math.h>

void MainWindow::on_pushButton_logy_clicked()
{
    flag=2;
//    if(!new_num||ui->lineEdit_1->text().isEmpty())
//    {
//        int m=ui->lineEdit->text().length()-1;
//        if(ui->lineEdit->text().at(m)=='.')
//           {
//            QString a=ui->lineEdit->text();
//            a=a.left(a.length()-1);
//            ui->lineEdit->setText(a);    //删除小数点
//        }
//        ui->lineEdit_1->setText("jhbhjb");
//        ui->lineEdit->setText(QString::number(calculate(),'g',12));
//        set_new_num(true);
//    }
//    else
//    {
//        ui->lineEdit_1->end(false);
//        ui->lineEdit_1->backspace();
//        ui->lineEdit_1->setText(ui->lineEdit_1->text()+"log"+QString::number(123));


//    }
//    dot=false;
//    cur_op="";
    option("^");

}

//double MainWindow::binary(double x,double y)
//{
//    switch(flag)
//    {
//        case 2:  //logy
//        {
//            return log(x)/log(y);
//            break;
//        }
//    }
//}

