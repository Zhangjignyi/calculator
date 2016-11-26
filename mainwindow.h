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
//    int flag=0;  //用来检测算符的输入 1\2\3\4 --- 加\减\乘\除

    void set_new_num(bool new_n);
    void option(const QString& op) ;
    void judge(int n);
    double calculate(); //计算当前表达式的值




private slots:
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

};

#endif // MAINWINDOW_H
