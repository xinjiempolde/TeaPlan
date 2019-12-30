/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 周新纪

Date: 2019-12-20

Description: 主窗口的设计，主要是QTabWidget

**************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*
     * 函数名:InitTabWidget
     * 功能:初始化tabwidget
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void InitTabWidget();

private slots:

private:
    Ui::MainWindow *ui;
    QTabWidget* m_tabwidget;
};
#endif // MAINWINDOW_H
