#include "mainwindow.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar> //菜单栏

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    //菜单栏
    QMenuBar* mBar = menuBar();
    //工具栏
    QMenu* pFile = mBar->addMenu("文件");
    //添加菜单项,添加动作
    QAction* pNew = pFile->addAction("新建");

    //状态栏
    //核心控件
    //浮动窗口
}

void MainWindow::InitUI()
{
    //创建UnderLine,Italic,Bold 3个Checkbox，并水平布局
    chkBoxUnder = new QCheckBox(tr("UnderLine"));
}

void MainWindow::on_chkBoxBold(bool Checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(Checked);
    txtEdit->setFont(font);
}

MainWindow::~MainWindow()
{
}
