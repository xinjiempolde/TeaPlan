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
    int GLocateVex(int x);
    bool Traverse();
public:
    VNode AdjList[MAX_VERTEX_NUM];   //顶点表
    int vexnum;        //图的当前顶点数
    int arcnum;        //边数
};

#endif // ALGRAPH_H
