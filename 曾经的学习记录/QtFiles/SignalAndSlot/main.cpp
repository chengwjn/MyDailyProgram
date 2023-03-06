#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;//执行MainWidget构造函数
    w.show();
    return a.exec();//等待用户操作
}
/* 信号与槽
 */
