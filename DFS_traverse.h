#pragma once
#ifndef _DFSDFSDFSDFS_
#define _DFSDFSDFSDFS_
#include"graph.h"
//邻接矩阵dfs----------------------------------------------------//
const int Max_Size=1024;
// typedef int boolean;
// boolean visited[Max_Size];//访问标志数组
bool visted[Max_Size];

//邻接矩阵的深度优先递归算法
void M_dfs(Matrix_Graph<int>g,int i)//i对应第i个顶点
{
    int j;
    visted[i]=true;     //标记访问顶点
    printf("%c",(g.get_vertex())[i]);//打印顶点，也可进行其他操作
    for(j=0;j<g.numVertexes;++j)
    {
        if(g.arc[i][j]==1&&!visted[j])
            M_dfs(g,j); //对未访问的邻接点递归
    }
}
//邻接矩阵深度遍历操作------------O(n^2)
void DFStraverse(Matrix_Graph<int>g)
{
    int i;
    for(i=0;i<g.numVertexes;++i)
    {
        visted[i]=false;//初始化顶点访问数组,都是未访问过状态
    }
    for(i=0;i<g.numVertexes;++i)
    {
        if(!visted[i])//对未访问的顶点进行dfs，若是连通图，只会执行一次
        M_dfs(g,i);
    }
}

//邻接表-----------------------------------------//
//邻接表递归算法
void Adjancy_dfs(Ajacenty_graph<string,int>g,int i)
{
    visted[i]=true;
    printf("%s",&(g.get_adjlist()[i].data));
    Edge_Node<int> *p=g.get_adjlist()[i].firstedge;
    while(p)
    {
        if(!visted[p->adjavex])
        Adjancy_dfs(g,p->adjavex);//对未访问的邻接点递归
        p=p->next;
    }
}
//邻接表深度遍历操作------------O(n+e)
void DFStraverse(Ajacenty_graph<string,int>g)
{
    int i;
    for(i=0;i<g.get_numVertexs();++i)
    {
        visted[i]=false;//初始化顶点访问数组,都是未访问过状态
    }
    for(i=0;i<g.get_numVertexs();++i)
    {
        if(!visted[i])//对未访问的顶点进行dfs，若是连通图，只会执行一次
        Adjancy_dfs(g,i);
    }
}
#endif