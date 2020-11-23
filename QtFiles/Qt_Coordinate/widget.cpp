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
