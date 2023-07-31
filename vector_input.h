#pragma once
#ifndef _VECTOR_INPUT_H_
#define _VECTOR_INPUT_H_
#include<iostream>
#include<vector>
#include<string>
using std::string;
using std::vector;
using std::cin,std::cout,std::endl;

vector<vector<int>> string_to_int(std::istream &cin)
{
    vector<int> input;
    vector<vector<int>> matrix;
    string s;
    while ((getline(cin, s)) && s != "")
    {
        for (int i = 0; i < s.size(); ++i)
        {
            int num = 0;
            while (s[i] != ' ' && s[i] != '\0')
            {
                num = num * 10 + s[i] - '0'; // 从高位向低位逐个转换
                ++i;
            }
            if (i > 0 && s[i - 1] != ' ')//去除首位连续空格
                input.push_back(num);
        }
        matrix.push_back(input);
        input.clear();
    }
   return matrix;
}
void print(vector<vector<int>>matrix)
{
     for (auto &line : matrix)
    {
        for (auto &e : line)
            cout << e << " ";
        cout << endl;
    }
}
    

#endif