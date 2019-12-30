/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 王崧霖

Date: 2019-12-20

Description: 显示学分相关信息

**************************************************************************/
#ifndef POINTINFO_H
#define POINTINFO_H

#include <QWidget>
#include "algraph.h"
namespace Ui {
class PointInfo;
}

class PointInfo : public QWidget
{
    Q_OBJECT

public:
    explicit PointInfo(QWidget *parent = nullptr);
    ~PointInfo();

    /*
     * 函数名:ReadFileData
     * 功能:从已存在文件中读取已安排课程数据
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void ReadFileData();

    /*
     * 函数名:SetInfo
     * 功能:显示课程学分信息
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void SetInfo();

private:
    Ui::PointInfo *ui;
    QVector<VNode> Sort;
};

#endif // POINTINFO_H
