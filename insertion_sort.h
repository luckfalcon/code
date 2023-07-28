#pragma onece
#ifndef _INSERT_SORT_H_
#define _INSERT_SORT_H_
#include<iostream>
//插入排序核心思想:
//将待排元素插入到之前排好序的元素之间

//步骤:
//1、从第二个元素(第一个要被排序的新元素)开始，从后向前扫描之前的元素序列
//2、如果当前扫描的元素大于新元素，将扫描元素移到下一位
//3、重复步骤2，直到找一个一个小于或者等于新元素的位置
//4、将新元素插入到该位置
//5、对于之后的元素重复步骤1~4

//时间复杂度:O(n^2)
//空间复杂度:O(1)
template<typename T,int N>
void print_arr(T (&arr)[N])
{
    for(int i=0;i<N;++i)
        std::cout<<arr[i]<<"";
    std::cout<<std::endl;
}

template<typename T,int N>
void insertion_sort(T (&arr)[N])
{
    for(int i=1;i<N;++i) 
    {
        T cur=arr[i];               //记录待排元素位置
        int j=i-1;                  //记录待排元素位置之前元素最大位置
        while(j>=0&&arr[j]>cur)     //待排前面元素扫描完成且待排元素前面的元素大于待排元素值
        {
            std::swap(arr[j],arr[j+1]); //将待排元素的位置与它之前小于它的值的元素位置交换
            --j;                        //扫描索引前移一位
        }
    }
  
}
/*
template<typename T,int N>
void insertion_sort(T (&arr)[N])
{
    for(int i=1;i<N;++i) 
    {
        T cur=arr[i];               //记录待排元素位置
        int j=i-1;                  //记录待排元素位置之前元素最大位置
        while(j>=0&&arr[j]>cur)     //待排前面元素扫描完成且待排元素前面的元素大于待排元素值
        {
            arr[j+1]=arr[j];            //将大于cur的元素依次后移
            --j;                        //扫描索引向前移一位
        }
        arr[j+1]=cur;                   //将cur元素插入到它之前值大于它的位置
    }
  
}
*/
// template<typename T,int N>
// void insertion_sort_for(T (&arr)[N])
// {
//     for(int i=0;i<N;++i) 
//     {
//         T cur=arr[i];
//       for(int j=i-1;j>=0&&arr[j]>cur;--j)
//       {
//         std::swap(arr[j+1],arr[j]); 
//       }
//     }
  
// }
#endif