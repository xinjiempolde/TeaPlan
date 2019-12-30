/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 刘亚炯

Date: 2019-12-20

Description: 更新课程表信息

**************************************************************************/
#ifndef UPDATE_H
#define UPDATE_H

#include <QWidget>
#include <QVector>
#include "algraph.h"
namespace Ui {
class UpDate;
}

class UpDateWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UpDateWindow(QWidget *parent = nullptr);
    ~UpDateWindow();

    /*
     * 函数名:ReadFileData
     * 功能:从文件中读取课程信息到Sort中
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void ReadFileData();

    /*
     * 函数名:SaveFileData
     * 功能:将成员Sort中的信息写入文件
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void SaveFileData();

private slots:
    void on_submit_button_clicked();

private:
    Ui::UpDate *ui;
    QVector<VNode> Sort;
};

#endif // UPDATE_H
