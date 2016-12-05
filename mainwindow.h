#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString cur_op="";
    double number=0;  //number目前总和
    bool dot=false;  //检测小数点是否已输入
    bool new_num=true; //输入框无数字时为真
    int flag=0;  // 为1时输入数字前清空显示栏


    void set_new_num(bool new_n);
    void option(const QString& op) ;
    void judge(int n);
    double calculate(); //计算当前表达式的值
    double binary(double x,double y);  // logy




private slots:
    //简单计算器
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_dot_clicked();  //小数点
    void on_pushButton_ac_clicked();   //AC
    void on_pushButton_00_clicked();   // +/-
    void on_pushButton_back_clicked();  //退格
    void on_pushButton_per_clicked();  // %
    void on_pushButton_add_clicked();  // +
    void on_pushButton_min_clicked();  // -
    void on_pushButton_mul_clicked();  //*
    void on_pushButton_dvd_clicked();  // /
    void on_pushButton_eq_clicked();   // =

    //科学计算器

    //常数
    void on_pushButton_e_clicked();
    void on_pushButton_pi_clicked();

    //单目运算
    void on_pushButton_2in_clicked();
    void on_pushButton_2x_clicked();
    void on_pushButton_10x_clicked();
    void on_pushButton_ex_clicked();
    void on_pushButton_ln_clicked();
    void on_pushButton_log2_clicked();
    void on_pushButton_log10_clicked();
    void on_pushButton_s2_clicked();
    void on_pushButton_s3_clicked();
    void on_pushButton_x_clicked();
    void on_pushButton_x2_clicked();
    void on_pushButton_x3_clicked();

    void on_pushButton_cos_clicked();
    void on_pushButton_acos_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_asin_clicked();
    void on_pushButton_tan_clicked();
    void on_pushButton_atan_clicked();

    //双目运算
//    void on_pushButton_logy_clicked();
    void on_pushButton_sy_clicked();
    void on_pushButton_xy_clicked();

//    void on_pushButton_l_clicked();    //左括号
//    void on_pushButton_r_clicked();    //右括号

};

#endif // MAINWINDOW_H
