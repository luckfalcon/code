#include<iostream>
#include<string>
#include<map>
#include<vector>
#include"graph.h"
//#include<algorithm>
//#include<stack>
// #include"bsearch_recursive.h"
// #include"insertion_sort.h"
// #include"q_sort.h"
// #include"merge_sort.h"
#include"link_list.h"
//#include"stack_queue.h"
#include"string_KMP.h"
#include"tree_map.h"
using namespace std;

int main()
{

    //int arr[]={9,4,3,7,1,8,5,2,6};
    //insertion_sort<int>(arr);
    //cout<<"pivot index: "<<qs_partion<int>(arr)<<endl;
    //q_sort<int>(arr);
    // merge_sort<int>(arr);
    // print_arr<int>(arr);
    //cout<<bsearch_recursive(arr,8)<<endl;
    //vector<int>v={1,2,3,4,5,6};
   //MGraph<int>g;
   //g.creategraph({1,2,3,4,5},{{1,2,3},{4,5,6},{7,8,9},{10,11,12}},MGraph<int>::Undirected);
   //g.creategraph();

    vector<int>input;
    vector<vector<int>>matrix;
    string s;
    while((getline(cin,s))&&s!="")
    {
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
        matrix.push_back(input);
        input.clear();
    }
    for (auto &line : matrix)
    {
        for (auto &e : line)
            cout << e << " ";
        cout << endl;
    }
        
    //system("pause");
    return 0;
}