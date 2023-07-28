#pragma once
#ifndef _Q_SORT_H_
#define _Q_SORT_H_
#include<iostream>
//快排步骤:
//1、对于当前的数组，取最后一个元素当作基准数(pivot)
//2、将所有比基准数小的元素排到基准数之前，比基准数大的排到基准数之后(分D)
//3、当基准数被放到准确位置后，根据基准数的位置将数组切分为前后两个子数组
//4、对子数组采取1~4的递归操作，直到子数组的长度小于等于1为止

//时间复杂度O(n^2),平均时间复杂的O(nlogN)
//空间复杂度O(n),平均空间复杂度O(logN)

template<typename T,int N>
int qs_partion(T (&arr)[N],int left=0,int right=N-1)
{
    T pivot=arr[right];
    int left_index=left;
    int right_index=right-1;
    while (true)
    {
        while (left_index < right && arr[left_index] <= pivot)
        {
            ++left_index;
        }//寻找比pivot大的元素
        while (right_index >= left && arr[right_index] > pivot)
        {
            --right_index;
        }//寻找第一个比pivot小的元素
        if(left_index > right_index)break;
        std::swap(arr[left_index],arr[right_index]);//交换完后，保证left_index<right_index
    }
      std::swap(arr[left_index],arr[right]);//交换pivot和正确位置的元素来获取pivot的正确下标
      return left_index;
}
template<typename T,int N>
void q_sort(T (&arr)[N],int left=0,int right=N-1)
{
    if(left>=right)return;//递归终止条件
    int partion_index=qs_partion(arr,left,right);
    q_sort(arr,left,partion_index-1);
    q_sort(arr,partion_index+1,right);
}
#endif