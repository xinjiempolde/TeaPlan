#include "algraph.h"

ALGraph::ALGraph()
{
    vexnum = 0;
    arcnum = 0;
}

int ALGraph::GLocateVex(int x)
{
    int i, j = -1;
    for (i = 0; i < vexnum; i++)
    {
        if (AdjList[0].data.Num == x)
        {
            j = i;
            break;
        }
    }
    return j;
}

bool ALGraph::Traverse()
{
    bool flag = false;
    for (int i = 0; i < vexnum; i++)
    {
        if (AdjList[i].data.marks == 0)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

