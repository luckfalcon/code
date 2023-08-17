#pragma once
#ifndef _UUUUUUIOUOUOUOUIOU_H_
#define _UUUUUUIOUOUOUOUIOU_H_
#include"graph.h"
#include<queue>
using std::queue;
const int Max_BFS=1024;
bool visited[Max_BFS];//标记顶点状态
//广度优先搜索/遍历---Breadth-First-Search(BFS)
//邻接矩阵
void M_BFS(Matrix_Graph<int> g)
{
    queue<int> q;
    for(int i=0;i<g.numVertexes;++i)
        visited[i] = false;
    for(int i=0;i<g.numVertexes;++i)
    {
        if(!visited[i])
        {
            visited[i]=true;
            printf("%s",g.get_vertex()[i]);
            q.push(i);//顶点入队
            while(!q.empty())
            {
                int k=q.front();//顶点出队，赋值给k
                q.pop();
                for(int j=0;j<g.numVertexes;++j)
                {
                    if(g.arc[k][j]==1&&!visited[j])
                    {
                        visited[j]=true;
                        printf("%d",g.get_vertex()[j]);
                        q.push(j);
                    }
                }
            }
        }

    }
}void adjacency_BFS(Ajacenty_graph<int,int>g)
{
    queue<int>q;    //存邻接顶点
    for(int i=0;i<g.get_numVertexs();++i)
    {
        visited[i]=false;
    }
    for(int i=0;i<g.get_numVertexs();++i)
    {
        if(!visited[i])
        {
             visited[i]=true;
             printf("%c",&g.get_adjlist()[i].data);//打印当前顶点信息
             q.push(i);
             while(!q.empty())
             {
                q.pop();
                Edge_Node<int> *p = g.get_adjlist()[i].firstedge;
                while (p)
                {
                    if (!visited[p->adjavex])
                    {
                        visited[p->adjavex] = true;
                         printf("%c",&g.get_adjlist()[p->adjavex].data);//打印邻接点信息
                        q.push(p->adjavex);
                    }
                    p = p->next;
                }
             }
        }
       
       
    }

}
#endif