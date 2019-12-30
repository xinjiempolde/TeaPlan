/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 周新纪

Date: 2019-12-20

Description: 将已排课程显示到界面上

**************************************************************************/
#ifndef SORTRESULT_H
#define SORTRESULT_H

#include <QWidget>
#include "algraph.h"
namespace Ui {
class SortResult;
}

class SortResult : public QWidget
{
    Q_OBJECT

public:
    explicit SortResult(const QVector<VNode> &Sort, QWidget *parent = nullptr, bool flag = false);
    ~SortResult();

    /*
     * 函数名:ShowData
     * 功能:显示成员数据Sort的相关信息
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void ShowData();

    /*
     * 函数名:SaveData
     * 功能:将成员Sort的信息保存到文件中
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void SaveData();

private:
    Ui::SortResult *ui;
    int termNum;
    const QVector<VNode> &Sort;
    bool isSaveFile;    // 是否需要保存到文件中
};

#endif // SORTRESULT_H
