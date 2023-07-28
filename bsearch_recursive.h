#pragma once
#ifndef _BSEARCH_RE_H_
#define _BSEARCH_RE_H_

template<typename T,int N>
int bsearch_recursive(T (&arr)[N],T target,int low=0,int high=N-1)
{
    int mid=low+(high-low)/2;
    if(arr[mid]==target)
    return mid;
    else if(arr[mid]>target)
    return bsearch_recursive(arr,target,low,mid-1);
    else
    return bsearch_recursive(arr,target,mid+1,high);
    return -1;
}
/*
int arr[]={1,2,3,4,5,6,7,8,9};
int target=7;
cout<<"the index is:\n"<<bsearch_recursive(arr,target)<<endl;
        
*/
#endif