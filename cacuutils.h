/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 王崧霖

Date: 2019-12-20

Description: 工具类，数学变换相关的自定义函数

**************************************************************************/
#ifndef CACUUTILS_H
#define CACUUTILS_H
typedef double angle;   // 定义角度
typedef double radiam;  // 定义弧度
typedef struct{
    double x;
    double y;
}coor;    // 定义坐标
class CacuUtils
{
public:
    CacuUtils();

    /*
     * 函数名:CacuCordinate
     * 功能:坐标旋转变换
     * 参数:center为中心顶点坐标
           point为要变换的点
           angle为旋转弧度
     * 输入:无
     * 输出:无
     * 返回值:旋转后的坐标位置
     */
    coor CacuCordinate(const coor &center, const coor &point, const radiam &angle);

    /*
     * 函数名:AngleToRadiam
     * 功能:弧度转角度
     * 参数:a为角度
     * 输入:无
     * 输出:无
     * 返回值:弧度值
     */
    radiam AngleToRadiam(angle a);

private:
    const double PI = 3.1415926535898;  // 定义常量pai
};

#endif // CACUUTILS_H
