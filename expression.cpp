#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<math.h>

void MainWindow::init()
{
    //数字 常量类
    ui->pushButton_20->setEnabled(true);
    ui->pushButton_21->setEnabled(true);
    ui->pushButton_22->setEnabled(true);
    ui->pushButton_23->setEnabled(true);
    ui->pushButton_24->setEnabled(true);
    ui->pushButton_25->setEnabled(true);
    ui->pushButton_26->setEnabled(true);
    ui->pushButton_27->setEnabled(true);
    ui->pushButton_28->setEnabled(true);
    ui->pushButton_29->setEnabled(true);
    ui->pushButton_2dot->setEnabled(true);
    ui->pushButton_e->setEnabled(true);
    ui->pushButton_pi->setEnabled(true);
    //括号
    ui->pushButton_l->setEnabled(true);
    ui->pushButton_r->setEnabled(true);
    //单目运算
    ui->pushButton_log2->setEnabled(true);
    ui->pushButton_log10->setEnabled(true);
    ui->pushButton_2x->setEnabled(true);
    ui->pushButton_10x->setEnabled(true);
    ui->pushButton_2in->setEnabled(true);
    ui->pushButton_x->setEnabled(true);
    ui->pushButton_ln->setEnabled(true);
    ui->pushButton_ex->setEnabled(true);
    ui->pushButton_sin->setEnabled(true);
    ui->pushButton_asin->setEnabled(true);
    ui->pushButton_cos->setEnabled(true);
    ui->pushButton_acos->setEnabled(true);
    ui->pushButton_tan->setEnabled(true);
    ui->pushButton_atan->setEnabled(true);
    ui->pushButton_x2->setEnabled(true);
    ui->pushButton_x3->setEnabled(true);
    ui->pushButton_s2->setEnabled(true);
    ui->pushButton_s3->setEnabled(true);
    //双目运算
    ui->pushButton_2add->setEnabled(true);
    ui->pushButton_2min->setEnabled(true);
    ui->pushButton_2mul->setEnabled(true);
    ui->pushButton_2dvd->setEnabled(true);
    ui->pushButton_2eq->setEnabled(true);

    ui->pushButton_logy->setEnabled(true);
    ui->pushButton_xy->setEnabled(true);
    ui->pushButton_sy->setEnabled(true);
    ui->pushButton_200->setEnabled(true);

    number=0;
    set_new_num(true);
    dot=false;
    left=0;
    if(!stack_op.isEmpty())
        stack_op.clear();

    stack_op.push('#');
    is_1=false;
    is_2=false;
}

void MainWindow::on_pushButton_l_clicked()
{
    isleft=true;
    left++;
    ui->lineEdit_1->setText(ui->lineEdit_1->text()+"(");
    //不可选
    ui->pushButton_sin->setEnabled(false);
    ui->pushButton_asin->setEnabled(false);
    ui->pushButton_cos->setEnabled(false);
    ui->pushButton_acos->setEnabled(false);
    ui->pushButton_tan->setEnabled(false);
    ui->pushButton_atan->setEnabled(false);
    ui->pushButton_200->setEnabled(false);
    ui->pushButton_logy->setEnabled(false);
    ui->pushButton_sy->setEnabled(false);
    // ( 后可以有数字
    ui->pushButton_20->setEnabled(true);
    ui->pushButton_21->setEnabled(true);
    ui->pushButton_22->setEnabled(true);
    ui->pushButton_23->setEnabled(true);
    ui->pushButton_24->setEnabled(true);
    ui->pushButton_25->setEnabled(true);
    ui->pushButton_26->setEnabled(true);
    ui->pushButton_27->setEnabled(true);
    ui->pushButton_28->setEnabled(true);
    ui->pushButton_29->setEnabled(true);
    ui->pushButton_2dot->setEnabled(true);
    // （ 后不能有算符和 ）
    ui->pushButton_2add->setEnabled(false);
    ui->pushButton_2min->setEnabled(false);
    ui->pushButton_2mul->setEnabled(false);
    ui->pushButton_2dvd->setEnabled(false);
    ui->pushButton_2eq->setEnabled(false);
    ui->pushButton_r->setEnabled(false);
}

void MainWindow::on_pushButton_r_clicked()
{
    left--;
    ui->lineEdit_1->setText(ui->lineEdit_1->text()+ui->lineEdit->text()+")");
    ui->lineEdit->clear();
    // )后可有算符和=
    ui->pushButton_2add->setEnabled(true);
    ui->pushButton_2min->setEnabled(true);
    ui->pushButton_2mul->setEnabled(true);
    ui->pushButton_2dvd->setEnabled(true);
    ui->pushButton_2eq->setEnabled(true);
    // ) 后不能有数字
    ui->pushButton_20->setEnabled(false);
    ui->pushButton_21->setEnabled(false);
    ui->pushButton_22->setEnabled(false);
    ui->pushButton_23->setEnabled(false);
    ui->pushButton_24->setEnabled(false);
    ui->pushButton_25->setEnabled(false);
    ui->pushButton_26->setEnabled(false);
    ui->pushButton_27->setEnabled(false);
    ui->pushButton_28->setEnabled(false);
    ui->pushButton_29->setEnabled(false);
    ui->pushButton_2dot->setEnabled(false);

    if(left==0)
    {
        ui->pushButton_r->setEnabled(false);
        ui->pushButton_2eq->setEnabled(true);
    }

}


int MainWindow::level(const QChar &op)
{
    switch(op.cell())
    {
        case '#':               //结束标志
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;

        default:
            return 0;
    }
}

//转换为后缀表达式
void MainWindow::postfix()
{

    QString exp=ui->lineEdit_1->text();
    QString tmp=exp;

    int i;
    //只有数字时
    for(i=0;i<tmp.size()&&tmp[i].isDigit()||tmp[i]=='.';i++)
        postfix_form.push_back(tmp[i]);
    if(i==tmp.size())
    {
        postfix_form.push_back(' ');
        return;
    }
    postfix_form.clear();
    //
    for(int j=0;j<exp.size();j++)
    {

        if(exp[j].isDigit()||exp[j]=='.')  //数字
            postfix_form.push_back(exp[j]);
        else if(exp[j]=='(')   //入操作符栈
            stack_op.push(exp[j]);
        else if(exp[j]==')')
        {
            postfix_form.push_back(' ');
            while(stack_op.top()!='(')
                postfix_form.push_back(stack_op.pop());
            stack_op.pop();
        }
        //算符比栈顶优先级高时入栈顶
        else if(level(exp[j])>level(stack_op.top()))
        {
            postfix_form.push_back(' ');
            stack_op.push(exp[j]);
        }

        else
        {
            postfix_form.push_back(' ');
            while (level(exp[j])<=level(stack_op.top()))  //算符比栈顶优先级低时，弹出添加到后缀表达式
                postfix_form.push_back(stack_op.pop());
            stack_op.push(exp[j]); //栈顶优先级低  入栈
        }
    }
    while(stack_op.top()!='#')
    {
        QChar c=stack_op.pop();
        postfix_form.push_back(' ');
        postfix_form.push_back(c);

    }
}

//计算后缀表达式
void MainWindow::sum()
{
    QString tmp;
    QStack<double> ans;

    for(int i=0;i<postfix_form.size();i++)
    {
        if(postfix_form[i].isDigit()||postfix_form[i]=='.')
            tmp.push_back(postfix_form[i]);
        else if(postfix_form[i]==' ')  //操作符或括号
        {
            if(!tmp.isEmpty())
            {
                ans.push(tmp.toDouble());
                tmp.clear();
            }

        }
        else //遇到操作符，pop两个数计算，结果入栈
        {
            double a=0,b=0;
            switch(postfix_form[i].cell())
            {
            case '+': a=ans.pop(); b=ans.pop();
                      ans.push(b+a); break;
            case '-': a=ans.pop(); b=ans.pop();
                      ans.push(b-a); break;
            case '*': a=ans.pop(); b=ans.pop();
                      ans.push(b*a); break;
            case '/': a=ans.pop(); b=ans.pop();
                      ans.push(b/a); break;
            case '%': a=ans.pop(); b=ans.pop();
                      ans.push((int)b%(int)a); break;
            case '^': a=ans.pop(); b=ans.pop();
                      ans.push(pow(b,a)); break;
            default:
                break;

            }
        }
    }
    ui->lineEdit->setText(QString::number(ans.top(),'g',12));

}
