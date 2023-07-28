#pragma noce
#ifndef _S_KMP_H_
#define _S_KMP_H_
#include<string>
//普通字符串匹配算法实现
//最好时时间复杂度O(m+n),最坏为O((n-m+1)*m)

//朴素字符串匹配算法//

//返回子串T在主串S中第pos位置个字符之后的位置。若不存在，则返回0
int s_index(std::string s,std::string t,int pos)//时间复杂度：O(n^2)
{
    int i=pos;//s字符查找起始位置
    int j=0;    //t子串字符起始位置
    while(i<s.size()&&j<t.size())
    {
        if(s[i]==t[j])//当前字符相等则继续查看下一个字符
        {
            ++i;
            ++j;
        }
        else
        {
            i=i-j+1;//返回上次匹配首位的下一个位置 
            j=0;                             
        }

    }
      if(j>=t.size())
        {
            //满足j>t.size()退出条件，i记录t字符串被索引完全后最后一个字符在s字符串中的位置
            return i-t.size(); 
        }
        else            //满足i>s.size(),表示未找到
        {
            return 0;
        }
}

//KMP模式匹配算法  //
//next数组结论：
//1、next[0]=-1,next[1]=0是恒成立的
//2、对于next的值，因为在原理上它为前缀表的后移，所以我们通过在求得前缀值后，先递增一位再赋值，
//即将某一位的前缀值赋给后一位的next值，所以对于next值，它只取决于与前一位的匹配情况，而与本身无关。
//这样我们在某个字符匹配成功时，先递增前缀值然后将值赋给下一位的next值，而匹配失败时，我们可以直接
//通过它的next值(前一位的前缀值)寻找等价位置进行回溯

//通过计算返回子串t的next数组
void get_next(std::string t,int *next)//当前字符串之前的字符串的前后缀的相似度
{
        int i = 0;//指向后缀
        int j = -1;//j指向前缀，j同时代表最长匹配子串长度

        next[0]=-1;
        //next[1]=0;
        while(i<t.size())
        {
            //若为t字符串起始位置，则开始检查
            if(j==-1||t[i]==t[j])//t[i]表示后缀的单个字符，t[j]表示前缀的单个字符
            {
                ++i;           
                ++j;            //j最终值为前后缀字符最大相似度
                next[i]=j;  //最长相等前后缀数+1，即为当前失配点应回溯的位置   1<k<j
            }
            else
            {
                j=next[j];      //若不相同则,j值回溯,本质是找到与j等价位置来进一步判断
            }
        }
}
void get_nextval(std::string t,int *nextval)
{
    int i=0;
    int j=-1;
    nextval[0]=-1;
    while(i<t.size())
    {
        if(j==-1||t[i]==t[j])
        {
            ++i;
            ++j;
            if(t[i]!=t[j])
            {
                nextval[i] = j;
            }
            else
            {
                nextval[i]=nextval[j];
            }
            
        }
        else
        {
            j=nextval[j];

        }
               
    }

}
int kmp_index(std::string s,std::string t,int pos)//时间复杂度 O(n)(n=s.size() >>> m=t.size())
{
    int i=pos;
    int j=0;    //子串当前位置下标值
    //int next[255];
    int nextval[255];
    //get_next(t,next);
    get_nextval(t,nextval);

    while (i < s.size()&&j<t.size())
    {
           
            if (s[i] == t[j]) 
            {
                ++i;
                ++j;
            }
            else
            {
                if(nextval[j]==-1)
               // if (next[j] == -1)
                {
                    ++i;
                }
                else
                {
                    //j = next[j]; // j回溯
                    j=nextval[j];
                }
            }
    }

    if(j==t.size())
    return i-t.size();
    else
    return 0;
}
#endif