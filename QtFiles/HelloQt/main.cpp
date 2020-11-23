#include <QApplication>
#include <QWidget> //窗口控件基类
#include <QPushButton>
int main(int argc,char *argv[])
{
    QApplication a(argc,argv);

    QWidget w;
    w.setWindowTitle("Hello,world");//设置标题
    //w.show();

    QPushButton b;
    b.setText("-_-");//给按钮设置内容
    b.setParent(&w);//指定父对象
    b.move(100,100);//移动坐标
    //b.show();


    QPushButton b1(&w);//通过构造函数传参
    b1.setText("^-^");

    /* 如果不指定父对象，对象和对象没有关系，独立的
     * a指定b为父对象 -> a放在b的上面
     * 指定父对象，有2种方法
     * 1） setParent
     * 2) 通过构造函数传参
     * 指定父对象，只需要父对象显示，上面的子对象自动显示
     */

    w.show();
    //我们的代码

    return a.exec();
}
