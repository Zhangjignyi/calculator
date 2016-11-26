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
 //   void pushButton();

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
    void on_pushButton_eq_clicked();   // =

};

#endif // MAINWINDOW_H
