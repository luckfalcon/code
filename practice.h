#include<iostream>
// template<typename T,int N>
// int partion(T(&arr)[N],int left,int right)
// {
//     T pivot=arr[right];
//     int left_index=left;
//     int right_index=right-1;
//     while(true)
//     {
//         while(left_index<right&&arr[left_index]<=pivot)
//         {
//             ++left_index;
//         }
//         while(right_index>=left&&arr[right_index]>pivot)
//         {
//             --right_index;
//         }
//         if(left_index>right_index)break;
//         std::swap(arr[left_index,right_index]);
//     }
//     std::swap(arr[left_index],arr[right]);
//     return left_index;
// }
// template<typename T,int N>
// void qqsort(T(&arr)[N],int left,int right)
// {
//     int partion_index=partion(arr,left,right);
//     if(left>=right)return;
//     qqsort(arr,left,partion_index-1);
//     qqsort(arr,partion_index+1,right);
// }
// template<typename T,int N>
// void merge_re_p(T (&arr)[N],int left,int mid,int right)
// {
//     T helper[N];
//     for(int i=0;i<N;++i)helper[i]=arr[i];
//     int left_index=left;        //左起始索引坐标
//     int right_index=mid+1;      //又起始索引坐标
//     for(int i=0;i<right;++i)
//     {
//         if(left_index>mid) //检测左侧元素越界
//         {
//             arr[i]=helper[right_index++];
//         }
//         else if(right_index>right)//检测右侧元素越界
//         {
//             arr[i]=helper[left_index++];
//         }
//         else if(helper[left_index]<helper[right_index])
//         {
//             arr[i]=helper[left_index++];
//         }
//         else
//         {
//             arr[i]=helper[right_index];
//         }   
//     }
// }
// template<typename T,int N>
// void merger_sort(T (&arr)[N],int left,int right)
// {
//     if(right-left<1)return;
//     int mid=left+(right-left)/2;
//     merger_sort(arr,left,mid);
//     merger_sort(arr,mid+1,right);
//     merge_re_p(arr,left,mid,right);
// }