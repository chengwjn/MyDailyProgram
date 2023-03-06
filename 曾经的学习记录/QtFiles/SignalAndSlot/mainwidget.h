#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <subwidgets.h>//子窗口头文件

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void MySlot();
    void change();
    void dealSub();
private:
    QPushButton b1;
    QPushButton *b2;

    QPushButton b3;

    SubWidgets w;
};


#endif // MAINWIDGET_H
