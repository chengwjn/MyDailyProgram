#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    /*对于父窗口(主窗口)，坐标系统相对于屏幕
     * 原点:相对于屏幕左上角
     * x:向右递增
     * y:向下递增
     */
    resize(400, 300);
    move(100, 100);

    /* 子窗口，坐标系统相对于父窗口
     * 原点：相对于窗口空白区域左上角
     * x:向右递增
     * y:向下递增
     */

    QPushButton* b = new QPushButton(this);
    b->move(100, 100);
    b->resize(100, 100);
    b->setText("-_-");

    QPushButton* b2 = new QPushButton(b);
    b2->setText("^_^");
}

Widget::~Widget()
{
}
//chengwenjie
//2020年11月24日 .凌晨2:16
//想睡觉，还是想学东西，还是想摸鱼

//2020年11月25日，凌晨0：31
//内存回收机制

//1）指定父对象后 2）直接或间接继承于QObject
//子对象如果是动态分配空间的new，不需要手动释放delete
//系统会自动释放
