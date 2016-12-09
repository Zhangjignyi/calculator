# calculator
a scientific calculator by Qt&amp;C++

# 计算器大作业说明

[TOC]

##1.编译说明
###1.1开发环境
Qt 5.7
###1.2语言
C++

##2.使用说明
###2.1界面介绍
本计算器**简单计算器**和**科学计算器**两个分界面
简单计算器界面如下：
![8A08A78B-E2BD-4C27-B886-0D587F93394E.png](http://upload-images.jianshu.io/upload_images/3766646-3544f55398fcac71.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

科学计算器界面如下：
![BCA6999A-34CD-45FA-ADA3-99EBF986C49E.png](http://upload-images.jianshu.io/upload_images/3766646-a519806c9924357a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
###2.2功能说明
####2.2.1 简单计算器
简单计算器实现了基本的 *加减乘除* 运算，支持根据乘除号的优先级计算不带括号的表达式
####2.2.2科学计算器
科学计算器支持的功能有：

- [x] 常用常数
- [x] 单目运算
- [x] 双目运算
- [x] 三角函数运算
- [x] 多项式表达式识别及计算 
- [x] 容错

#####常用常数
相关代码见 `constant.cpp`
![BED13D8A-00A8-40BB-8D9D-4D0A01C43B88.png](http://upload-images.jianshu.io/upload_images/3766646-b86a4626bfebb67d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
#####单目运算
相关代码见 `unary.cpp`
![CCB727E4-8F33-4B87-8EAB-03467401BAE2.png](http://upload-images.jianshu.io/upload_images/3766646-76f1d02132c29445.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240) ![054FB5A3-104A-4500-8B63-7D4381DD624D.png](http://upload-images.jianshu.io/upload_images/3766646-fd27ad6dcd9848e5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)  

#####双目运算
相关代码见 `binary.cpp`
![1976345B-78E7-459F-8D3E-0787B7F2A09D.png](http://upload-images.jianshu.io/upload_images/3766646-4ab67ed5a19ed3e8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)   ![145C7373-932F-4F76-B353-4857E2A02E03.png](http://upload-images.jianshu.io/upload_images/3766646-703fcb90d079ea95.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
#####三角函数运算
相关代码见 `unary.cpp`
![65CC660A-84B1-4040-AEAC-43EB9958F8F2.png](http://upload-images.jianshu.io/upload_images/3766646-bf554a6d9445dbb7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
#####多项式表达式识别及运算（核心功能）
- 关于多项式的识别，采用中缀表达式转后缀表达式，相关代码见 `expression.cpp` 中函数`void postfix()` 
- 关于后缀表达式的计算，采用数据结构**栈**，将后缀表达式放入栈中，依据后缀表达式的计算方法相应入栈出栈，相关代码见`expression.cpp` 中函数`void sum()`
- 关于多项式的合法输入问题，采用限制输入的解决办法，如下图所示
![DE39BB2D-7100-4E59-8D80-8F170FBB67FA.png](http://upload-images.jianshu.io/upload_images/3766646-7e68f86ed08b6271.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
 
 完成当用户未完成合法输入时，限制按钮的活动，如上图中右括号后只能输入算符，所以此时左括号和数字按钮均为不可按
 ![EECDD66A-020C-4B73-8C2A-0C2C88A27FAE.png](http://upload-images.jianshu.io/upload_images/3766646-b80af49378262488.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
 同理，当左右括号数目相等时才能继续输入左括号同时设置右括号不可按
 
 限制输入的方法可减去识别表达式不必要的麻烦
 
#####容错
支持多种容错
![QQ20161207-3.png](http://upload-images.jianshu.io/upload_images/3766646-d01554e25ae99d16.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)![QQ20161207-2.png](http://upload-images.jianshu.io/upload_images/3766646-a42c95b2d3bac694.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![QQ20161207-1.png](http://upload-images.jianshu.io/upload_images/3766646-573d39636a8321cb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![QQ20161207-0.png](http://upload-images.jianshu.io/upload_images/3766646-5ed7b337d4205019.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
 




