#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCheckBox>
#include <QDialog>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QRadioButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QCheckBox* chBoxUnder;
    QCheckBox* chkBoxUnder;
    QCheckBox* chkBoxBold;
    QRadioButton* rBrnBlack;
    QRadioButton* rBtnRed;
    QRadioButton* rBtnBlue;
    QPlainTextEdit* txtEdit;
    QPushButton* btnOk;
    QPushButton* btnCancel;
    QPushButton* btnClose;
    void InitUI(); //UI创建与初始化
    void InitSignalSlots(); //初始化信号与槽的链接
private slots:
    void on_chkBoxUnder(bool Checked); //UnderLine的槽函数
    void on_chkBoxItalic(bool Checked); //Italic的槽函数
    void on_chkBoxBold(bool Checked); //Bold的槽函数
    void SetTextFontColor(); //设置字体颜色

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
