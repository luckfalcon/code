#pragma once
#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream>
//邻接矩阵(adjacency matrix)
const int MaxNum=1024;
const long long InFinity=65536;//代表无穷
template<typename T>
class MGraph
{
    public:
    typedef T VertexType;//顶点类型
    typedef int EdegeType;//边权值类型
    MGraph():vertex{},edege{},numEdges(0),numVertexes(0){}
    //void creategraph(*G,V,VR);//按照顶点集合V和边弧集合VR的定义构造图
    void creategraph();//按照顶点集合V和边弧集合VR的定义构造图
    //void destorygraph(*G);//图G存在则销毁
    //void locatevertex(G,u);//若图G存在顶点u，则返回图中的位置
    //void getvex(G,v);//返回顶点v的值
    //void putvex(G,v,value);//将顶点值赋值为value
    //void firstadjvex(G,*v);//返回顶点v的一个邻接顶点，若顶点在G中无邻接顶点则返回空
    //void nextadjvex(G,v,*w);//返回顶点v相对于顶点w的下一个邻接顶点，若w是v的最后一个邻接点，则返回空
    //void insertvex(*G,v);//在图中增添新顶点v
    //void deletevex(*G,v);//删除顶点
    //void insertarc(*G,v,w);//在图中增添弧<v,w>,若G为无向图，则还需增添对称弧<w,v>
    //void deletearc(*G,v,w);//删除边弧
    //void DFStraverse(G);//对图进行深度优先遍历，在遍历中对每个顶点调用
    //void HFStraverse(G);//广度优先遍历...
    private:
    VertexType vertex[MaxNum];//顶点数组
    EdegeType edege[MaxNum][MaxNum];//邻接矩阵
    int numVertexes,numEdges;//图中当前顶点数和边数
};
template<typename T>
void MGraph<T>::creategraph()
{


}
//邻接表
template<typename T>
struct Edge_Node
{
    T data;
    Edge_Node *next;

};
template<typename T>
class graph
{

};

#endif
