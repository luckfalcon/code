#pragma once
#ifndef _TREE_MAP_H_
#define _TREE_MAP_H_
#include<iostream>
#include<queue>
//------------------------------------------------------------------------//
//-------------------------树的表示法：-----------------------------------//
//-----------------------1、双亲表示法-------------------------------------//
//-----------------------2、孩子表示法-结点存数组，孩子存单链表---------------//
//-----------------------3、孩子兄弟表示法---------------------------------//
//特殊树结构
//二叉树----根结点--左子树--右子树
//左右子树分顺序，不可颠倒
//基本形态：
//1、空二叉树
//2、只有一个根结点 
//3、根结点只有左子树 
//4、根结点只有左子树 
//5、既有左子树又有右子树
//特殊二叉树
//1、斜树---左斜树(只有左子树)--右斜树(只有右子树)
//2、满二叉树--分支结点都有左右子树，所有的叶子都在同一层
//3、完全二叉树--按照完全二叉树的编号顺序，中间没有缺失编号，可以不满编号。也就是满二叉树是完全二叉树
//但完全二叉树不一定是满二叉树

//----------------------------------------------------------------------------//
//顺序二叉树：一维数组存储结点，数组下标体现结点间逻辑关系-----
//顺序结构只用于完全二叉树，否则会浪费大量空间（比如斜二叉树--右树）
//----------------------------------------------------------------------------//
template<typename T>
class Sequnce_Binary_Tree
{
    public:

    private:

};
//----------------------------------------------------------------------------//
//二叉链表:
//----------------------------------------------------------------------------//
template<typename T>
struct Link_BTree_node
{
    T data;
    Link_BTree_node *l_child,*r_child;
    Link_BTree_node():l_child(nullptr),r_child(nullptr){}
};
template <typename T>
class Link_BTree
{

    public:
        using link_bt = Link_BTree_node<T> *;
        Link_BTree():root(nullptr),node_cnt(0),level(0) {}
        ~Link_BTree();
        //Link_BTree_node<T>**==link_bt*
        void create_btree( link_bt*,const std::initializer_list<T>&,
                       int ,int );
        void create_btree(const std::initializer_list<T>&ls){ create_btree( &root,ls,0,ls.size()); }
        void preordertraverse(link_bt);                 //入口参数需要静态默认参数，而该类型
        void preordertraverse(){preordertraverse(root);}//需要运行时候才能确定，故可重载实现
        void inordertraverse(link_bt);                  
        void inordertraverse(){inordertraverse(root);}
        void postordertraverse(link_bt);
        void postordertraverse(){postordertraverse(root);}
        void layertraverse(link_bt);
        void layertraverse(){layertraverse(root);}
        void print_node(Link_BTree_node<T>*);
        void print_list(link_bt);
        void print_list(){print_list(root);}
    private:
    //Link_BTree_node<T> *root;
    link_bt root;
    int node_cnt;
    int level;
};

template<typename T>
void Link_BTree<T>::create_btree( link_bt*pos,
                                const std::initializer_list<T>&ls,int left,int right)
{
    if(left==right)//只控制了输入数据量，缺乏树递归退出递归条件，这样只会构造单边树(也就是单链表)
    {
        return;
    }
    auto beg=ls.begin();
    //insert_node(*pos,*(beg+left));
    *pos=new Link_BTree_node<T>;
    (*pos)->data=*(beg+left);
    ++node_cnt;
    ++left;
    create_btree(&(*pos)->l_child,ls,left,right);
    create_btree(&(*pos)->r_child,ls,left,right);
}
template<typename T>
Link_BTree<T>::~Link_BTree()
{

}
template<typename T>//前序/先序遍历---根左右
void Link_BTree<T>::preordertraverse(link_bt t)
{
    if(!t)//结点为空，则返回
    {
        return;
    }
    std::cout<<t->data<<" ";
    preordertraverse(t->l_child);
    preordertraverse(t->r_child);
    std::cout<<std::endl;
}
template<typename T>//中序遍历
void Link_BTree<T>::inordertraverse(link_bt t)
{
    if(!t)
    {
        return;
    }
    inordertraverse(t->l_child);
    std::cout<<t->data<<" ";
    inordertraverse(t->r_child);
    std::cout<<std::endl;
}
template<typename T>
void Link_BTree<T>::postordertraverse(link_bt t)
{
    if(!t)
    {
        return;
    }
    postordertraverse(t->l_child);
    postordertraverse(t->r_child);
    std::cout<<t->data<<std::endl;
}
template<typename T>
void Link_BTree<T>::print_node(Link_BTree_node<T>*node)
{
    if(!node)
    {
        return;
    }
    std::cout<<"node number:\t"<<node_cnt<<std::endl;
    std::cout<<"node data:\t"<<node->data<<std::endl;
}
template<typename T>
void Link_BTree<T>::layertraverse(link_bt p)
{
    std::queue<Link_BTree_node<T>>q;
    q.push(p);
    while(!q.empty())
    {
        q.pop();
        ++level;
        if (p->l_child)
        {
            q.push(p->l_child);
        }
        if (p->r_child)
        {
            q.push(p->r_child);
        }
    }
}
template<typename T>
void Link_BTree<T>::print_list(link_bt t)
{
    if(!t)
    {
        return;
    }
    std::cout<<t->data<<" ";
    print_list(t->l_child);
    print_list(t->r_child);
    std::cout<<std::endl;
}
#endif