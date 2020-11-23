#include "mainwidget.h"
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("Close");
    b1.move(100,100);

    b2=new QPushButton(this);
    b2->setText("-_-");

    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);
    /* &b1:信号发出者,指针类型
    * &QPushButton::pressed: 处理的信号 ，&发送者的类名::信号名字
    * this:信号接收者
    * &MainWidget::close :槽函数，信号处理函数， &接受的类名::槽函数名字
    */

    /*自定义槽
    * Qt5 :任意的成员函数，普通全局函数,静态函数
    *槽函数需要和信号一致(参数，返回值)
    * 由于信号都是没有返回值,所以,槽函数一定没有返回值
    */
    connect(b2,&QPushButton::released,this,&MainWidget::MySlot);

    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);
    /*
    * 信号：短信
    * 槽函数：接收信号的手机
    */

    setWindowTitle("老大");

    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);

    //显示子窗口
    //w.show();

    connect(&b3,&QPushButton::released,this,&MainWidget::change);

    //处理子窗口的信号
    connect(&w,&SubWidgets::mySignal,this,&MainWidget::dealSub);

    resize(400,300);
}

void MainWidget::MySlot()
{
    b2->setText("123");
}

void MainWidget::change(){
    //子窗口显示
    w.show();
    //本窗口隐藏
    this->hide();
}

void MainWidget::dealSub()
{
    //子窗口隐藏
    w.hide();
    //本窗口显示
    this->show();
}


MainWidget::~MainWidget()
{
}

