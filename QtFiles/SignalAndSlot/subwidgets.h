#ifndef SUBWIDGETS_H
#define SUBWIDGETS_H

#include <QWidget>
#include <QPushButton>

class SubWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidgets(QWidget *parent = nullptr);

    void SendSlot();

signals:
    /*
     * 信号必须有signals关键字来声明
     * 信号没有返回值,但可以有参数
     * 信号就是函数的声明，秩序声明，无需定义
     * 使用信号 ; emit mySignal()；
     */
    void mySignal();

private:
    QPushButton b;
};

#endif // SUBWIDGETS_H
