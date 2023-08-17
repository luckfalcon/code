#pragma once
#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

vector<int> string_to_int(string s)
{
    vector<int>input;
    for(int i=0;i<s.size();++i)
        {
            int num=0;
            while(s[i]!=' '&&s[i]!='\0')
            {
                num=num*10+s[i]-'0';//从高位向低位逐个转换
                ++i;
            }
            if(i>0&&s[i-1]!=' ')
                input.push_back(num);
        }
    return input;
}
//邻接矩阵(adjacency matrix)
const long long InFinity=65536;//代表无穷
const int MaxCapacity=1024;
template<typename T>
class Matrix_Graph
{
    public:
    enum class tage{Undirected,Directed};     //加class私有enum//标记用于无向图还是有向图
    Matrix_Graph():vertex(T()),arc(0),numEdges(0),numVertexes(0),type(tage::Undirected){}
    ~Matrix_Graph()=default;
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
    vector<T> get_vertex()const{return vertex;}
    vector<vector<int>> get_arc()const{return arc;}
    int get_numVertexes()const{return numVertexes;}
    int get_numEdges()const{return numEdges;}
    vector<T> vertex;          //顶点数组
    vector<vector<int>> arc;    //邻接矩阵
    int numVertexes,numEdges;           //图中当前顶点数和边数
    tage type;                          //有无向标签
};
template<typename T>
inline
void Matrix_Graph<T>::creategraph(const vector<T>&v,const vector<vector<int>>&e,tage t)
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
inline
void Matrix_Graph<T>::creategraph()
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
            type = tage::Undirected;
            break;
        }
        else if (n == 1)
        {
             type = tage::Directed;
             break;
        }
        else
            std::cout << "wrong input! please repeat " << std::endl;
    }
   std::cout<<"input arc element one line by one line(tap two enter to end):"<<std::endl;
   vector<int>input;
   string temp;
   while((getline(std::cin,temp))&&temp!="")
   {
    for(int i=0;i<temp.size();++i)
    {
        int num=0;
        while(temp[i]!=' '&&temp[i]!='\0')
        {
            num=num*10+(temp[i]-'0');
            ++i;
        }
        if(i>0&&temp[i-1]!=' ')
            input.push_back(num);
    }
    arc.push_back(input);
    input.clear();//每次循环清空input
   }

}
template<typename T>
void Matrix_Graph<T>::destorygraph()
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
    type=tage::Undirected;
}
template<typename T>
int Matrix_Graph<T>::locatevertex(const T &u)
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
//--------------------------------------------------------------//
//邻接表
template<typename EdgeType>    //边表结构
struct Edge_Node
{
    int adjavex;        //邻接点域，存储该顶点对应的下标
    EdgeType weight;         //用于存储权值
    Edge_Node *next;    //链域，指向下一个邻接点

};
template<typename VertexType,typename EdgeType>        //顶点表结构  
struct Vex_node
{
    VertexType data;                 //顶点域，存储顶点信息
    Edge_Node<EdgeType>*firstedge;     //边表头指针
    //Vex_node():data(0),firstedge(nullptr){}
    Vex_node():data(0),firstedge(new Edge_Node<EdgeType>){}
    //Vex_node(const VertexType &d):data(d),firstedge(nullptr){}//带参数初始化,初始化为头结点
    Vex_node(const VertexType &d):data(d),firstedge(new Edge_Node<EdgeType>){}//带参数初始化
    //~Vex_node(){if(firstedge!=nullptr) delete firstedge;}
  // friend istream &operator>>(istream &,Vex_node);
};//vertexlist[max]//顶点表

// template<typename VertexType,typename EdgeType>  
// istream &operator>>(istream &is,Vex_node<VertexType,EdgeType>v)
// {
//     is>>v.data>>v.firstedge;//初始化顶点和对应边表第一个结点
//     return is;
// }
template<typename VertexType,typename EdgeType>
class Ajacenty_graph
{
    public:
    enum class tage{Undirected,Directed};
    void create();
    vector<Vex_node<VertexType,EdgeType>> get_adjlist(){return adjlist;}
    int get_numVertexs(){return numVertexs;}
    int get_numEdges(){return numEdges;}
    private:
    vector<Vex_node<VertexType,EdgeType>>adjlist;//邻接表
    int numVertexs;                 //图中当前顶点数
    int numEdges;                   //图中当前边数
    tage type;
};

template<typename VertexType,typename EdgeType>
void Ajacenty_graph<VertexType,EdgeType>::create()
{
    cout<<"input vertex data,input enter to end"<<endl;
    VertexType vex_data;
    while(cin>>vex_data)
    {
        adjlist.push_back(Vex_node<VertexType,EdgeType>(vex_data));
        if(cin.get()=='\n')
        break;
    }
    numVertexs=adjlist.size();
    cout<<"input graph type data"<<endl;
    int t;
    while(cin>>t)
    {
        if(t==0)
        {
            type = tage::Undirected;//无向图
            break;
        }
       
        else if(t == 1)
        {
            type = tage::Directed;//有向图
            break;
        }
        
        else
        {
            cout<<"wrong input,repeat input"<<endl;
        }
    }
    cout<<"input edge data"<<endl;
    EdgeType weight;
    Edge_Node<EdgeType>*next_edge_node;//下一个边结点
    for(int i=0;i<numVertexs;++i)
    {
        EdgeType weigt;
        while(cin>>weigt)
        {
            next_edge_node = new Edge_Node<EdgeType>;
            next_edge_node->weight=weigt;
            next_edge_node->next=adjlist[i].firstedge->next;
            adjlist[i].firstedge->next=next_edge_node;
            if(cin.get()=='\n')
            break;
        }
    }
}
#endif
