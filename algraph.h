/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 王崧霖

Date: 2019-12-20

Description: 邻接表定义的图结构以及相关操作

**************************************************************************/

#ifndef ALGRAPH_H
#define ALGRAPH_H

#include <QString>

#define MAX_VERTEX_NUM 100
/* 弧节点结构体 */
typedef struct node{
    int adjvex;     //该弧所指向的顶点的位置
    struct node* nextarc;   //指向下一条弧的指针
}ArcNode;

/* 顶点数据结构体 */
typedef struct {
    QString Num;          //课程序号
    QString	Name;    //课程名字
    float Point;        //学分
    int Weeks;        //周数
    bool marks;       //访问标记
    int term;         //学期序号
    int Indegree;      //入度
    int Outdegree;    //出度
}VertexType;

/* 表头结点 */
typedef struct {     //头结点
    VertexType data;   //顶点信息
    ArcNode* firstarc;  //指向第一条依附该顶点的弧的指针
}VNode;

/* 采用邻接表的图结构类 */
class ALGraph
{
public:
    ALGraph();
    /*
     * 函数名:GLocateVex
     * 功能:在图中查找课程
     * 参数:x为课程编号
     * 输入:无
     * 输出:无
     * 返回值:课程在图中的位置
     */
    int GLocateVex(int x);

    /*
     * 函数名:Traverse
     * 功能:遍历图，寻找是否有未被访问的节点
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:true已访问 false 未访问
     */
    bool Traverse();

    /*
     * 函数名:clear
     * 功能:清空图的一切数据
     * 参数:无
     * 输入:无
     * 输出:无
     * 返回值:无
     */
    void clear();
public:
    VNode AdjList[MAX_VERTEX_NUM];   //顶点表
    int vexnum;        //图的当前顶点数
    int arcnum;        //边数
};

#endif // ALGRAPH_H
