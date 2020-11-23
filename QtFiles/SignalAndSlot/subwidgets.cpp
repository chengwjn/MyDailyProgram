#include "subwidgets.h"

SubWidgets::SubWidgets(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("小弟");
    b.setParent(this);
    b.setText("切换到主窗口");

    connect(&b,&QPushButton::clicked,this,&SubWidgets::SendSlot);

    resize(400,300);
}

void SubWidgets::SendSlot()
{
    emit mySignal();
}
