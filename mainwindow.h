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


    void set_new_num(bool new_n);
    void option(const QString& op) ;
    void judge(int n);
    double calculate(); //计算当前表达式的值




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
    void on_pushButton_10x_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_200_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_29_clicked();
    void on_pushButton_2ac_clicked();
    void on_pushButton_2add_clicked();
    void on_pushButton_2bw_clicked();
    void on_pushButton_2dot_clicked();
    void on_pushButton_2dvd_clicked();
    void on_pushButton_2eq_clicked();
    void on_pushButton_2in_clicked();
    void on_pushButton_2min_clicked();
    void on_pushButton_2mul_clicked();
    void on_pushButton_2per_clicked();
    void on_pushButton_2x_clicked();
    void on_pushButton_2bi_clicked();
    void on_pushButton_cos_clicked();
    void on_pushButton_cosh_clicked();
    void on_pushButton_e_clicked();
    void on_pushButton_ex_clicked();
    void on_pushButton_l_clicked();
    void on_pushButton_ln_clicked();
    void on_pushButton_log10_clicked();
    void on_pushButton_log2_clicked();
    void on_pushButton_pi_clicked();
    void on_pushButton_r_clicked();
    void on_pushButton_s2_clicked();
    void on_pushButton_s3_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_sinh_clicked();
    void on_pushButton_sy_clicked();
    void on_pushButton_tan_clicked();
    void on_pushButton_tanh_clicked();
    void on_pushButton_x_clicked();
    void on_pushButton_x2_clicked();
    void on_pushButton_x3_clicked();
    void on_pushButton_xy_clicked();



};

#endif // MAINWINDOW_H
