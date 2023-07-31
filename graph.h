#pragma once
#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;

//邻接矩阵(adjacency matrix)
template<typename T>
class MGraph
{
    public:
    const long long InFinity=65536;//代表无穷
    const int MaxCapacity=1024;
    enum tage{Undirected,Directed};     //标记用于无向图还是有向图
    MGraph():vertex(0),arc(0),numEdges(0),numVertexes(0),type(Undirected){}
    ~MGraph()=default;
    bool empty(){return (vertex.size()==0)||(arc.size()==0);}
    //void creategraph(*G,V,VR);//按照顶点集合V和边弧集合VR的定义构造图
    void creategraph(const vector<T>&,const vector<vector<int>>&,tage);
    void creategraph();
    //void destorygraph(*G);//图G存在则销毁
    void destorygraph();//图G存在则销毁
    //void locatevertex(G,u);//若图G存在顶点u，则返回图中的位置
    int locatevertex(const T&);//若图G存在顶点u，则返回图中的位置
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
    vector<T> vertex;          //顶点数组
    vector<vector<int>> arc;    //邻接矩阵
    int numVertexes,numEdges;           //图中当前顶点数和边数
    tage type;                          //有无向标签
};
template<typename T>
void MGraph<T>::creategraph(const vector<T>&v,const vector<vector<int>>&e,tage t)
{
    if(v.size()!=e.size())
    {
        std::cout<<"data error!"<<std::endl;
        return;
    }
    vertex=v;
    arc=e;
    type=t;
    numVertexes=v.size();
    numEdges=e[0].size();
}
template<typename T>
void MGraph<T>::creategraph()
{
   
    T ele_vertex;
    std::cout<<"input vertex element(input enter to end):"<<std::endl;
    while(std::cin>>ele_vertex)
    {
        vertex.push_back(ele_vertex);
        if(std::cin.get()=='\n')
        break;
    }
    numVertexes=vertex.size();
    std::cout<<"input type of Graph(0---undirected graph,or 1---directed graph)"<<std::endl;
    int n;
    while(std::cin>>n)
    {
        if (n == 0)
        {
            type = Undirected;
            break;
        }
        else if (n == 1)
        {
             type = Directed;
             break;
        }
        else
            std::cout << "wrong input! please repeat " << std::endl;
    }
   std::cout<<"input arc element(input 0 to end):"<<std::endl;
   vector<int>input;
   string temp;
   while(std::cin>>temp&&temp!="")
   {
    for(int i=0;i<temp.size();++i)
    {
        int num=0;
        while(temp[i]!=' '&&temp[i]!='\0')
        {
            num=num*10+(temp[i]-'0');
            ++i;
        }
        input.push_back(num);
    }
    arc.push_back(input);
    input.clear();//每次循环清空input
   }


}
template<typename T>
void MGraph<T>::destorygraph()
{
    if (empty())
    {
        std::cout << "no graph exist!" << std::endl;
        return;
    }
    vertex.clear();
    arc.clear();
    numVertexes=0;
    numEdges=0;
    type=Undirected;
}
template<typename T>
int MGraph<T>::locatevertex(const T &u)
{
    if(empty())
    {
        std::cout<<"no graph exist!"<<std::endl;
        return -2;
    }
    for(int i=0;i<vertex.size();++i)
    {
        if(u==vertex[i])
        {
            return i;
        }
    }
    return -1;
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
