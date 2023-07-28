#pragma once
#ifndef _STACK_QUEUE_H_
#define _STACK_QUEUE_H_
#include <iostream>
//-----------------------------------------------------------------//
//----------------------Link_stack---------------------------------//
//-----------------------------------------------------------------//
template <typename T>
struct Link_Stack_Node
{
    T data;
    Link_Stack_Node *next;
    Link_Stack_Node() : next(nullptr) {}
};
template <typename T>
class Link_Stack
{
public:
    Link_Stack() : cnt(0), top(nullptr) {}
    ~Link_Stack();
    void push(const T &);
    void pop();
    void print_count() { std::cout << "the stack node count: " << cnt << std::endl; }
    void print_top();
    bool empty(){return (nullptr==top);}

private:
    Link_Stack_Node<T> *top;
    int cnt;
};

template <typename T>
void Link_Stack<T>::push(const T &data)
{
    Link_Stack_Node<T> *next_node;
    next_node = new Link_Stack_Node<T>;
    next_node->data = data;
    next_node->next=top; // 将新结点压入栈，也就是旧的top连到新结点尾部
    top = next_node;       // 更新top位置
    ++cnt;
}
template <typename T>
void Link_Stack<T>::pop()
{
    if(empty())
    {
        std::cout<<"empty stack!"<<std::endl;
        return;
    }
    Link_Stack_Node<T> *next_node;
    next_node = top->next;
    delete top;
    top = next_node;

    --cnt;
}
template <typename T>
Link_Stack<T>::~Link_Stack()
{
    Link_Stack_Node<T> *next_node;
    while (top)
    {
        next_node = top->next;
        delete top;
        top = next_node;
    }
}
template<typename T>
void Link_Stack<T>::print_top()
{
    if(top)
    {
        std::cout<<"top->data is: "<<top->data<<std::endl;
    }
}
/*
//    Link_Stack<int>sk;
//    sk.push(1);
//    sk.push(2);
//    sk.push(3);
//    sk.push(4);
//    sk.print_count();
//    sk.print_top();
//    sk.pop();
//    sk.print_count();
//    sk.print_top();
//    sk.pop();
//    sk.print_count();
//    sk.print_top();
*/
//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//
template<typename T>
class link_stack_no_head
{
    public:
    link_stack_no_head():top(nullptr),length(0){}
    ~link_stack_no_head();
    void push(const T &);
    void pop();
    bool empty();
    T get_top();
    private:
    Link_Stack_Node<T>*top;
    int length;
};
template<typename T>
void link_stack_no_head<T>::push(const T &data)
{
    Link_Stack_Node<T>*new_data;
    new_data=new Link_Stack_Node<T>;
    new_data->data=data;
    if(!top)
    {
        top=new_data;
    }
    else
    {
        new_data->next=top;
        top=new_data;
    }
    ++length;
    
}
template<typename T>
void link_stack_no_head<T>::pop()
{
    Link_Stack_Node<T> *top_next;
    if(!top)
    {
        std::cout<<"empty stack"<<std::endl;
        return;
    }
    else
    {
        top_next=top->next;
        delete top;
        top=top_next;
        --length;
    }

}
template<typename T>
T link_stack_no_head<T>::get_top()
{
    if(!top)
    {
        std::cout<<"empty stack"<<std::endl;
        return T();
    }
    //std::cout << "the top data is: "<<top->data << std::endl;
    return top->data;
}
template<typename T>
bool link_stack_no_head<T>::empty()
{
    return (top == nullptr);
}
template<typename T>
link_stack_no_head<T>::~link_stack_no_head()
{
    Link_Stack_Node<T>*top_next;
    while(top)
    {
        top_next=top->next;
        delete top;
        top=top_next;
    }

}
//-------------------------------------------------------------------------//
//--------------------Link_queue-------------------------------------------//
//-------------------------------------------------------------------------//
template<typename T>
struct Link_Queue_Node
{
    T data;
    Link_Queue_Node *next;
    Link_Queue_Node():next(nullptr){}
};
template<typename T>
class Link_Queue
{
    public:
    Link_Queue():head(new Link_Queue_Node<T>){front=head;rear=head;}
    ~Link_Queue();
    void enqueue(const T&);
    void dequeue();
    bool empty(){return (front==rear);}
    void print_front();
    private:
    Link_Queue_Node<T>*head,*front,*rear;
    int cnt=0;
    int capcity=10;
};
template<typename T>
void Link_Queue<T>::enqueue(const T&data)
{
    Link_Queue_Node<T>*next_node;
    next_node=new Link_Queue_Node<T>;
    next_node->data=data;
    rear->next=next_node;   //rear 后插入新元素
    rear=next_node;         //更新rear位置
    ++cnt;
}
template<typename T>
void Link_Queue<T>::dequeue()   //头结点后继结点出队
{
    Link_Queue_Node<T>*front_next;//指向对头元素
    if(empty())
    {
     std::cout<<"dequeue erro, empty queue"<<std::endl;
     return;   
    }
    front_next = front->next;
    front->next = front_next->next;
    delete front_next;
    --cnt;
}
template<typename T>
Link_Queue<T>::~Link_Queue()
{
    while(front)
    {
        front=head->next;
        delete head;
        head=front;
    }

}
template<typename T>
void Link_Queue<T>::print_front()
{
    if(empty())
    {
        std::cout<<"print error,empty queue"<<std::endl;
        return;
    }
    std::cout<<front->next->data<<std::endl;
}
/*
// Link_Queue<int>q;
// q.enqueue(0);
// q.enqueue(1);
// q.enqueue(2);
// q.enqueue(3);
// q.enqueue(6);
// q.print_front();
*/
//----------------------------------------------------------------------//
//--------------------------Linear_stack--------------------------------//
//----------------------------------------------------------------------//
//入栈和出栈时间复杂度O(1)
const int Linear_capacity=1024;
template<typename T>
class Linear_Stack
{
    public:
    Linear_Stack():data{}{}     //重点：数组成员初始化，数组元素默认类型默认初始化
    void push(const T&);
    void pop();
    void print_top();
    private:
    T data[Linear_capacity];
    int top=-1;
};
template <typename T>
void Linear_Stack<T>::push(const T &mem)
{
    if(top>Linear_capacity-1)
    {
        std::cout<<"no capacity for new member"<<std::endl;
        return;
    }
    data[++top]=mem;
}
template<typename T>
void Linear_Stack<T>::pop()
{
    if(top==-1)
    {
        std::cout<<"empty stack"<<std::endl;
        return;
    }
    --top;
}
template<typename T>
void Linear_Stack<T>::print_top()
{
    if(top==-1)
    {
        std::cout<<"empty stack"<<std::endl;
        return;
    }
    std::cout<<data[top]<<std::endl;
}
/*
Linear_Stack<int>lsk;
lsk.push(1);
lsk.push(2);
lsk.push(3);
lsk.print_top();
lsk.pop();
lsk.print_top();
lsk.pop();
lsk.print_top();
lsk.pop();
lsk.print_top();
*/
//-----------------------------------------------------------------//
//---------------------------Loop linear queue--------------------------//
//-----------------------------------------------------------------//
//入队时间复杂度：O(1)，出队时间复杂度O(N)--需要移动对头后面的元素

//队列长度通用计算公式:当前队列长度 = (rear-front+queuesize)%queuesize
template<typename T>
class Loop_Linear_Queue
{
    public:
    Loop_Linear_Queue():front(0),rear(0),queue_size(0),data{}{}
    void enqueue(const T&);
    void dequeue();
    void print_front();
    int size(){return ((rear-front+Linear_capacity)%Linear_capacity);}
private:
    T data[Linear_capacity];
    int front; // 队头
    int rear;  // 队尾下一个元素
    int queue_size;
};
template<typename T>
void Loop_Linear_Queue<T>::enqueue(const T&mem)
{
    if((rear+1)%Linear_capacity==front)
        {
            std::cout<<"Queue is full"<<std::endl;
            return;
        }
        data[rear] = mem; 
        rear = (rear+1)% Linear_capacity;
}
template<typename T>
void Loop_Linear_Queue<T>::dequeue()
{
    if(front==rear)
    {
        std::cout<<"empty Queue"<<std::endl;
        return;
    }
    front = (front + 1) % Linear_capacity;
}
template<typename T>
void Loop_Linear_Queue<T>::print_front()
{
     if(front==rear)
    {
        std::cout<<"empty Queue"<<std::endl;
        return;
    }
    std::cout<<"Queue front is: "<<data[front]<<std::endl;
}
/*
Loop_Linear_Queue<int>lq;
lq.enqueue(1);
lq.enqueue(2);
lq.print_front();
lq.dequeue();
lq.print_front();
lq.dequeue();
lq.print_front();*/
#endif