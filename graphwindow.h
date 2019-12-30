/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 周新纪 && 刘亚炯

Date: 2019-12-20

Description:让用户通过连线的方式确定先导关系

**************************************************************************/
#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include "cacuutils.h"
#include "algraph.h"
#include <QMainWindow>
#include <QMap>
#include <QVector>
typedef struct {
    QPoint begin;
    QPoint end;
}line_point;
namespace Ui {
class GraphWindow;
}

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr, ALGraph* G = nullptr);
    ~GraphWindow();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    /*
     * 函数名:GetBtnPos
     * 功能:获取正n边形的顶点坐标
     * 参数:n为正几边形，center为中心坐标，stripe为大小，pointsize为顶点大小
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void GetBtnsPos(int n, const coor &center = {350, 350}, int stripe = 200, coor pointsize = {20, 20});

    /*
     * 函数名:PaintLable
     * 功能:在顶点附近输出课程名字
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void PaintLable();

    /*
     * 函数名:GetRandomColor
     * 功能:获取随机的颜色
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:颜色，类型为Qt::GlobalColor
     */
    Qt::GlobalColor GetRandomColor();

private:
    Ui::GraphWindow *ui;
    QVector<line_point> list_line;
    QVector<line_point>::iterator it;
    QVector<QRectF> list_button;
    QVector<QRectF>::iterator button_it;
    QMap<int, bool> PressMap;
    QMap<int, bool> OverMap;
    QMap<int, bool> CheckMap; // 保存哪些节点被点击
    QVector<Qt::GlobalColor> ColorList;
    QMap<int, QVector<bool>> HasArc; // 保存哪些节点间有弧
    ALGraph* G;
    line_point line;
    int last_click; // 上次点击了那个点
    int count;
    const int n;
    const int PointSize;

protected:
    void paintEvent(QPaintEvent* event);
private slots:
    void on_course_button_clicked();
};

#endif // GRAPHWINDOW_H
