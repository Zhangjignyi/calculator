#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QValidator>
#include<QLineEdit>
#include<QRegExp>
#include<qdebug.h>
#include<math.h>

//阶乘   目前只支持66以内阶乘
unsigned long long frac(long int n)
{
    if(n>1)
        return n*frac(n-1);
    return 1;
}
void MainWindow::on_pushButton_x_clicked()
{
    double num=ui->lineEdit->text().toDouble();
    int num2=num;

    if(num<0||num==0||num2!=num)
        ui->lineEdit_1->setText("阶乘须是大于0的整数");
    else
    {
        unsigned long long a=ui->lineEdit->text().toInt();
        a=frac(a);        
        ui->lineEdit->setText(QString::number(a));//
    }
    set_new_num(true);
}

// 1/x
void MainWindow::on_pushButton_2in_clicked()
{
    if(ui->lineEdit->text() == "0")
        ui->lineEdit_1->setText("0没有倒数");
    else
    {
        double num=ui->lineEdit->text().toDouble();
        double num1=1/num;
        QString n=QString::number(num1,'g',12);
        ui->lineEdit->setText(n);
    }
    Flag=1;
}

// 平方
void MainWindow::on_pushButton_x2_clicked()
{
    double num=ui->lineEdit->text().toDouble();
    double num1=num*num;
    QString n=QString::number(num1,'g',12);
    ui->lineEdit->setText(n);
    Flag=1;
}

//立方
void MainWindow::on_pushButton_x3_clicked()
{
    double num=ui->lineEdit->text().toDouble();
    double num1=num*num*num;
    QString n=QString::number(num1,'g',12);
    ui->lineEdit->setText(n);
    Flag=1;
}

//根号
void MainWindow::on_pushButton_s2_clicked()
{
    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    if(num<0)
        ui->lineEdit_1->setText("负数不能开方根");
    else{
        double num1=sqrt(num);
        QString n=QString::number(num1,'g',12);
        ui->lineEdit->setText(n);

    }
    Flag=1;
}

//开三次方
void MainWindow::on_pushButton_s3_clicked()
{
    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    double num1=pow(num,1.0/3);
    QString n=QString::number(num1,'g',12);
    ui->lineEdit->setText(n);
    Flag=1;
}

// 2的幂次
void MainWindow::on_pushButton_2x_clicked()
{
    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    double num1=pow(2,num);
    QString n=QString::number(num1,'g',12);
    ui->lineEdit->setText(n);
    Flag=1;
}

//10的幂次
void MainWindow::on_pushButton_10x_clicked()
{
    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    double num1=pow(10,num);
    QString n=QString::number(num1,'g',12);
    ui->lineEdit->setText(n);
    Flag=1;
}

//e的幂次
void MainWindow::on_pushButton_ex_clicked()
{
    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    double num1=pow(2.718,num);
    QString n=QString::number(num1,'g',12);
    ui->lineEdit->setText(n);
    Flag=1;
}

// ln
void MainWindow::on_pushButton_ln_clicked()
{
    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    if(num<0||num==0)
    {
        ui->lineEdit_1->setText("请输入大于0的数");
        ui->lineEdit->clear();
    }
    else
        ui->lineEdit->setText(QString::number(log(num),'g',12));
    Flag=1;
}

//log2
void MainWindow::on_pushButton_log2_clicked()
{
    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    if(num<0||num==0)
    {
        ui->lineEdit_1->setText("请输入大于0的数");
        ui->lineEdit->clear();
    }
    else
        ui->lineEdit->setText(QString::number(log(num)/log(2),'g',12));
    Flag=1;
}

//log10
void MainWindow::on_pushButton_log10_clicked()
{
    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    if(num<0||num==0)
    {
        ui->lineEdit_1->setText("请输入大于0的数");
        ui->lineEdit->clear();
    }
    else
        ui->lineEdit->setText(QString::number(log10(num),'g',12));
    Flag=1;
}

//cos
void MainWindow::on_pushButton_cos_clicked()
{
    ui->lineEdit_1->clear();
    double num=cos(ui->lineEdit->text().toDouble());
    ui->lineEdit->setText(QString::number(num,'g',12));
    Flag=1;
}

//sin
void MainWindow::on_pushButton_sin_clicked()
{
    ui->lineEdit_1->clear();
    double num=sin(ui->lineEdit->text().toDouble());
    ui->lineEdit->setText(QString::number(num,'g',12));
    Flag=1;
}

//tan
void MainWindow::on_pushButton_tan_clicked()
{
    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    if(fabs(cos(num))<0.000000001)
        ui->lineEdit_1->setText("请重新输入");
    else{
        double num1=tan(ui->lineEdit->text().toDouble());
        ui->lineEdit->setText(QString::number(num1,'g',12));
    }
    Flag=1;
}

//acos
void MainWindow::on_pushButton_acos_clicked()
{

    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    if(num>1||num<-1)
        ui->lineEdit_1->setText("请输入-1到1之间的数");
    else{
        double num1=180*acos(num)/M_PI;
        QString n=QString::number(num1,'g',12);
        ui->lineEdit->setText(n);
    }
    Flag=1;
}

//asin
void MainWindow::on_pushButton_asin_clicked()
{

    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    if(num>1||num<-1)
        ui->lineEdit_1->setText("请输入-1到1之间的数");
    else{
        double num1=180*asin(num)/M_PI;
        QString n=QString::number(num1,'g',12);
        ui->lineEdit->setText(n);
    }
    Flag=1;
}


//atan
void MainWindow::on_pushButton_atan_clicked()
{
    ui->lineEdit_1->clear();
    double num=ui->lineEdit->text().toDouble();
    double num1=180*atan(num)/M_PI;
    QString n=QString::number(num1,'g',12);
    ui->lineEdit->setText(n);
    Flag=1;
}


