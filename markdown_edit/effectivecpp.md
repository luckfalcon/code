# C++注意条款
1. 拷贝构造函数---初始化-----A(B)---只发生在对象创建时
2. 拷贝赋值运算符--同类型对象值赋值给创建对象--A=B
3. 值传递（pass-by-value）--调用构造函数
4. 引用传递(passed-by-reference)--不调用构造函数

C++四大次级语言

- c语言部分编程
---
-  class类编程
___
+ template模板编程
***
* STL标准库编程
***

## 条款2：尽量以const,enum,inline 替换#define
```c++
class test
{
static const int num=1;//此处仅为声明而非定义
}
const int num;//此处为定义
```
