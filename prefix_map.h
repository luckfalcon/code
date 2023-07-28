#pragma once
#ifndef _PM_H_
#define _PM_H_
//前缀表  PM表 ：prefix map
//前缀表结论：
//1、前缀表的第一个字符的前缀值一定为0(即没有前缀等于后缀的子串，规定)
//2、对于某个位置的前缀值，我们可以通过匹配该位置元素与其前一位前缀值所对应位置的元素来得到前缀值。
//如果匹配成功，则前缀值+1。如果匹配失败，我们可以通过前缀值得到的等价位置换位匹配
#endif