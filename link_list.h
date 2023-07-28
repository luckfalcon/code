#pragma once
#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include<iostream>

//Single Link_List
template<typename T>
struct Node
{
    T data=T();
    Node *next;
    Node(){next=nullptr;}
};

 template<typename T>
 class Link_List
 {
    public:
    Link_List():length(0),head(new(Node<T>)){}
    ~Link_List();
    void creat_list_at_end(const std::initializer_list<T>&);
    void creat_list_at_begin(const std::initializer_list<T>&);
    void insert_mem(int ,const T &);
    void back_insert(const T &);
    void delete_mem_by_pos(int );
    bool empty(){return (head->next==nullptr);}//链表是否为无元素
    void clear_list();
    void reverse();
    void print_list();
    //void q_sort(int left=0,int right=length);
    int get_length(){return length;}
    private:
    Node<T>*head;
    int length;
    Node<T> *check(Node<T>*);//检查链表是否存在
 };

 template<typename T>
Node<T> *Link_List<T>::check(Node<T>*head)
{
    if(!head)
    {
        throw "no node exist!";
    }
    return head;
}
 template<typename T>
void Link_List<T>::creat_list_at_end(const std::initializer_list<T>&ls)
{
    Node<T>*now_node=check(head),*new_node;
    auto beg=ls.begin();
    while(beg!=ls.end())
    {
        if(!now_node->next)
        {
            new_node=new Node<T>;
            new_node->data=*beg;
            now_node->next=new_node;
            now_node=new_node;
        }
        ++length;
        ++beg;
    }
}
template<typename T>
void Link_List<T>::creat_list_at_begin(const std::initializer_list<T>&ls)
{
     Node<T>*now_node=check(head),*new_node;
    auto beg=ls.begin();
    while(beg!=ls.end())
    {
        if(!now_node->next)
        {
            new_node=new Node<T>;
            new_node->data=*beg;
            now_node->next=new_node->next;
            now_node->next=new_node;
        }
        ++length;
        ++beg;
    }
}
 template<typename T>
 Link_List<T>::~Link_List()
 {
    Node<T>*temp_node;
    while(head)
    {
        temp_node=head->next;
        delete head;
        head=temp_node;
    }
 }

 template<typename T>
void Link_List<T>::insert_mem(int pos,const T &data)//中间某个位置前插入元素
{
    Node<T> *now_node=check(head),*new_node;
    if(pos>length||pos<=0)
    {
        std::cout<<"wrong position,check your position!"<<std::endl;
    }
    while(now_node->next&&pos>1)//pos>1可控制插入元素位于插入点前后位置
    {
        now_node=now_node->next;//要插入的pos结点位置
        --pos;
    }
    new_node=new Node<T>;
    new_node->data=data;    //后面插入元素,无前向指链接指针，所以无法在前面插入元素
    new_node->next=now_node->next;
    now_node->next=new_node;
    ++length;
}
 template<typename T>
void Link_List<T>::back_insert(const T&data)
{
    Node<T>*now_node=check(head),*new_node;
    while(now_node->next)  //尾部有数据就循环
    {
        now_node=now_node->next;
    }
    new_node=new Node<T>;
    new_node->data=data;
    now_node->next=new_node;
    ++length;
}
 template<typename T>
void Link_List<T>::delete_mem_by_pos(int pos)//删除结点元素
{
    Node<T>*now_node=check(head),*delete_node;
    if(pos>length||pos<=0)
    {
        std::cout<<"wrong position,check your position!"<<std::endl;
    }
    
    while(now_node->next&&pos>1)//迭代至删除结点前一个结点位置 pos>1控制迭代结点位于删除结点的位置
    {
        now_node=now_node->next;
        --pos;
    }
    delete_node=now_node->next;
    now_node->next=delete_node->next;
    --length;
    delete delete_node;
}

 template<typename T>
 void Link_List<T>::reverse()//单链表数据反转,需要三个结点指针
 {
    Node<T>*cur_node=check(head),*pre_node,*rear_node;
    pre_node=nullptr;//空结点
    cur_node=cur_node->next;//第一个数据结点
    while(cur_node)
    {
        rear_node=cur_node->next;//数据结点下一个结点

        cur_node->next=pre_node;
        pre_node=cur_node;
        cur_node=rear_node;
    }
    head->next=pre_node;
 }
 template<typename T>
 void Link_List<T>::clear_list()
 {
     Node<T>*now_node=check(head),*temp_node;
    while(now_node->next)
    {
        temp_node=now_node->next;
        now_node->next=temp_node->next;
        delete temp_node;
    }
    length=0;
 }
 template<typename T>
void Link_List<T>::print_list()
{
    Node<T>*now_node=check(head);
    int cnt=0;
    while(now_node->next)
    {   
        ++cnt;
        std::cout<<"Node "<<cnt<<" is : "<<now_node->next->data<<std::endl;
        now_node=now_node->next;
    }
}
//  template<typename T>
// void Link_List<T>::q_sort(int left=0,int right=length)
// {

//     Node<T> *fast=check(head),*slow=check(head);

//     q_sort(left,mid);
//     q_sort(mid,right);
// }
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//
//Double Loop Link_List双向循环链表
//-------------------------------------------------------------------//
//-------------------------------------------------------------------//

template<typename T>
struct D_Node
{
    T data=T();
    D_Node *front,*rear;
    D_Node(){front=rear=nullptr;}
};
template<typename T>
class Double_Loop_Link_List
{
    public:
    Double_Loop_Link_List():length(0),head(new D_Node<T>){head->rear=head->front=head;}
    ~Double_Loop_Link_List();
    void creat_list_at_end(const std::initializer_list<T>&);
    void creat_list_at_begin(const std::initializer_list<T>&);
    void insert_mem(int ,const T&);
    void back_insert(const T&);
    void reverse();
    void print_list();
    void clear_list();
    void delete_mem(int);
    bool empty(){return (head->rear==head&&head->front==head);}
    int get_length(){return length;}
    private:
    D_Node<T> *head;
    int length;
    D_Node<T>*check(D_Node<T>*);
};
template<typename T>
Double_Loop_Link_List<T>::~Double_Loop_Link_List()
{
    D_Node<T>*now_node=check(head);
    while(now_node!=head)
    {
        now_node=head->rear;//暂存数据结点
        delete head;
        head=now_node;
    }
}
template<typename T>
D_Node<T> *Double_Loop_Link_List<T>::check(D_Node<T>*head)
{
    if(!head)
    {
        throw "no link_list exist";
    }
    return head;
}
template<typename T>
void Double_Loop_Link_List<T>::creat_list_at_begin(const std::initializer_list<T>&ls)
{
    D_Node<T>*now_node=check(head),*new_node;
    auto beg=ls.begin();
    while(beg!=ls.end())
    {
       //std::cout<<*beg<<std::endl;
        new_node=new D_Node<T>;
        new_node->data=*beg;
        new_node->rear=now_node->rear;
        new_node->front=now_node;
        new_node->rear->front=new_node;
        new_node->front->rear=new_node;
        ++length;
        ++beg;
    }
}
template<typename T>
void Double_Loop_Link_List<T>::creat_list_at_end(const std::initializer_list<T>&ls)
{
     D_Node<T>*now_node=check(head),*new_node;
    auto beg=ls.begin();
    while(beg!=ls.end())
    {
       //std::cout<<*beg<<std::endl;
        new_node=new D_Node<T>;
        new_node->data=*beg;
        now_node->rear=new_node;
        new_node->front=now_node;
        new_node->rear=head;
        new_node->rear->front=new_node;
        now_node=new_node;
        ++length;
        ++beg;
    }
}
template<typename T>
void Double_Loop_Link_List<T>::insert_mem(int pos,const T&data)
{
    D_Node<T>*now_node=check(head),*new_node;
    int i=1;
    if(i>pos)
    {
        std::cout<<"wrong position"<<std::endl;
    }
    while(now_node->rear&&i<pos)
    {
        now_node=now_node->rear;
        ++i;
    }
    new_node=new D_Node<T>;
    new_node->data=data;
    new_node->rear=now_node->rear;
    new_node->front=now_node;
    new_node->front->rear=new_node;
    now_node->rear=new_node;
    ++length;
}
template<typename T>
void Double_Loop_Link_List<T>::delete_mem(int pos)
{
    D_Node<T>*now_node=check(head),*temp_node;
    int i=1;
    if(pos>length)
    {
        std::cout<<"wrong position"<<std::endl;
    }
    while(now_node->rear&&i<pos)
    {
        now_node=now_node->rear;
        ++i;
    }
    temp_node=now_node->rear;
    now_node->rear=temp_node->rear;//前结点后向指针指向待删除指针后一个结点
    temp_node->rear->front=now_node;//后一结点的前向指针指向待删除结点的前一个结点
    delete temp_node;

}
template<typename T>
void Double_Loop_Link_List<T>::back_insert(const T&data)
{
    D_Node<T>*now_node=check(head),*new_node;
    while(now_node->rear!=head)
    {
        now_node=now_node->rear;//获取待删除结点前一个结点位置
    }
    new_node=new D_Node<T>;
    new_node->data=data;
    new_node->rear=now_node->rear;
    new_node->front=now_node;
    new_node->rear->front=new_node;
    new_node->front->rear=new_node;
    ++length;
}
template<typename T>
void Double_Loop_Link_List<T>::reverse()
{
        //保存前一个当前位置，前一个结点位置，后一个结点位置
    D_Node<T> *cur_node = check(head), *pre_node, *next_node;

    pre_node = cur_node->front; // 保存上一个结点
    next_node = cur_node->rear;//保存下一个结点
    while(cur_node->rear!=head)
    {
       std::cout<<"cur_node->rear->data is: "<<cur_node->rear->data<<std::endl;
       cur_node->rear=pre_node;
       cur_node->front=next_node;
       pre_node=cur_node;
       cur_node=next_node;
       next_node=next_node->rear;//
    }
    cur_node->rear = pre_node;
    cur_node->front = next_node;
}
template<typename T>
void Double_Loop_Link_List<T>::print_list()
{
    D_Node<T>*now_node=check(head);
    int cnt=0;
    while(now_node->rear!=head)
    {   
        ++cnt;
        std::cout<<"D_Node "<<cnt<<" is : "<<now_node->rear->data<<std::endl;
        now_node=now_node->rear;
    }
}
template<typename T>
void Double_Loop_Link_List<T>::clear_list()
{
    D_Node<T>*now_node=check(head),*temp_data;
    while(now_node->rear!=head)
    {
        temp_data=now_node->rear;//暂存数据结点
        now_node->rear=temp_data->rear;
        now_node->rear->front=now_node;
        delete temp_data;
    }
    length=0;
}

/*
 //Link_List<int>lst;
 Double_Loop_Link_List<int>lst;
    //Link_List<int>lst;
    lst.creat_list_at_end({1,2,3,4,5,6,7,8,9});
     // lst.back_insert(1);
    // lst.back_insert(2);
    // lst.back_insert(3);
    // lst.back_insert(4);
    //cout<<"link_list state : "<<lst.empty()<<endl;
     lst.print_list();
    //cout<<"list length is : "<<lst.get_length()<<endl;
   
    lst.reverse();
    cout<<"after reverse:"<<endl;
    lst.print_list();
    // lst.clear_list();
    // cout<<"list state is :"<<lst.empty()<<endl;
    //cout<<"list length is : "<<lst.get_length()<<endl;
    // lst.delete_mem_by_pos(2);
    // // lst.reverse();
    // lst.print_node();
    // cout<<"list length is : "<<lst.get_length()<<endl;
    // lst.clear_list();
    // cout<<lst.empty()<<endl;
*/
#endif