/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 刘亚炯

Date: 2019-12-20

Description: 查询已排课程相关信息

**************************************************************************/
#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QWidget>
#include "algraph.h"
namespace Ui {
class SearchWindow;
}

class SearchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = nullptr);
    ~SearchWindow();
    /*
     * 函数名:ReadFileData
     * 功能:从文件中读取已存在的已排课程信息
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void ReadFileData();

private slots:
    void on_all_button_clicked();

    void on_name_button_clicked();

    void on_term_button_clicked();

private:
    Ui::SearchWindow *ui;
    QVector<VNode> Sort;
};

#endif // SEARCHWINDOW_H
