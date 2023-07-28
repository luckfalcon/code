#pragma once
#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_
#include<iostream>
//归并排序步骤：（本质也是一种D&C,Divide and Conquer思想）
//1、切分步骤：将大问题变为小问题，通过递归解决更小的问题
//2、解决步骤：将小问题的结果合并，以此找到大问题的答案
//
//时间复杂度: nlogN
//空间复杂度: O(n)

template<typename T,int N>
void merge_res(T (&arr)[N],int left,int mid,int right)
{
    T helper[N];
    std::copy(std::begin(arr),std::end(arr),std::begin(helper));
    //for(int i=start;i<end;++i)helper[i]=arr[i];
    int left_start=left;
    int right_start=mid+1;
    for(int i=left;i<=right;++i)
    {
        if(left_start>mid)
        {
            arr[i]=helper[right_start++];
        }
        else if(right_start>right)
        {
            arr[i]=helper[left_start++];
        }
        else if(helper[left_start]<helper[right_start])
        {
            arr[i]=helper[left_start++];
        }
        else
        {
            arr[i]=helper[right_start++];
        }
    }
}
template<typename T,int N>
void merge_sort(T (&arr)[N],int left=0,int right=N-1)
{
    if(right-left<1)return;
    int mid =left+(right-left)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merge_res(arr,left,mid,right);
}
#endif