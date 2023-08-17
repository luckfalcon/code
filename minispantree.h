#pragma once
#ifndef _JKJLHJKJKHKJKHKJ_H_
#define _JKJLHJKJKHKJKHKJ_H_
#include"graph.h"
//最小生成树算法

void minspantree_prim(Matrix_Graph<int>g)
{
//min设置一个极大值，用来找到一定范围的最小权值，j用来做顶点下标的循环变量,k存储最小权值的顶点下标
    int min,i,j,k;
    int adjvex[MaxVex];//保存相关顶点下标
    int lowcost[MaxVex];//保存相关顶点间边的权值
    lowcost[0]=0;       //初始化第一个权值为0，即v0加入生成树
                        //lowcost值为0，在这里就是此下标顶点已经加入生成树
    adjvex[0]=0;        //初始化第一个顶点下标为0
    for(i=1;i<g.numVertexes;++i)//循环除第一个顶点外的全部顶点
    {
        lowcost[i]=g.arc[0][i];//将V0顶点与之有关的边的权值存入数组
        adjvex[i]=0;            //初始化都为V0的下标
    }
    
    for(i=1;i<g.numVertexes;++i)
    {
        int min=InFinity;//初始化最小权值为无穷,通常设置为不可能大的数字65535，32767等
        j=1,k=0;
        while(j<g.numVertexes)
        {
            if(lowcost[j]!=0&&lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
            ++j;
        }
        printf("%d%d",adjvex[k],k);//打印当前顶点边中权值最小的
        lowcost[k]=0;//将当前顶点的权值置为0，表示此顶点已完成任务
        for(j=1;j<g.numVertexes;++j)
        {
            if(lowcost[j]!=0&&g.arc[k][j]<lowcost[j])
            {
                //若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
                lowcost[j]=g.arc[k][j];//将较小权值存入lowcost
                adjvex[j]=k;            //将下标为k顶点存入adjvex
            }
        }
    }

 


}
#endif