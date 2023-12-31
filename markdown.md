vscode 内，按crtl+shift+v,显示markdown预览效果
1、斜体、加粗、删除线
*示例文字*          * *
_示例文字_          _ _
**示例文字**       ** **
***示例文字***      *** ***
~~示例文字~~        ~~  ~~

2、分级标题
写法一
用不同个数的"#"并在后加一个空格(空格可有可无)来表示标题的级数
# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题
写法二
在标题下一行写入三个"=“或”-"使得上一行成为标题
一级标题
===
二级标题
---

3、插入图片
常用的插入图片的方式有两种。
插入本地图片
我们可以将本地文件夹下的图片插入到文本中，需要用到如下语法
![图片解释](图片路径)
其中的图片解释可以省去，注意’!‘和’[]'都是英文字符
插入网络图片
我们可以将网页上的图片插入到文本中，语法类似
1[图片解释](网页图片链接)
我们可以将网页图片"复制图片链接"，然后粘贴到括号里。

4、分割线
我们可以在一个单独的行写入三个"-“或”*“或”_"来表现出一个分割线，效果是一样的
---
***
___

5、代码块
OK，代码块的使用应该会是学习者最常用的语法也是markdown备受青睐的原因之一。
对于vscode下的markdown渲染器，笔者认为主要有两个语法方法实用一些。
行内代码
如果在一行中需要引用代码，我们可以用一个‘`’表示开始，然后在用一个‘`’表示结束。(此键一般在ESC键下方，与‘~’同键)
eg:在这一行内我需要`示例代码`
多行代码
当我们需要引用多行代码时，可以在代码的上一行写入三个连续的‘`’，并在其后标注代码语言，渲染器会根据你的代码语言给代码渲染上不同的颜色。
eg:
```c
//开始并标注语言
#include<stdio.h>
int main()
{
  printf("Hello, world");
  
  return 0;
}
//结束
```

6、列表
(1) 无序列表
使用“*”，“+”，“-”表示无序列表。
需要注意的是，在符号右面需要加一个空格，起到缩进的作用。
* 列表
- 列表
+ 列表
(2) 有序列表
使用数字和一个英文句点“.”表示有序列表。
同样需要注意的是，在句点后需要加一个空格，起到缩进的作用。
1. 列表
2. 列表
3. 列表
(3) 有序无序相结合
* 1. 小标题
* 2. 小标题

7、 表格
表格的写法很形象，和表格的形状很相似。
表头1|表头2|表头3
-|-|-
数据1|数据2|数据3

四、其他可能用到的
markdown的基本语法已经讲完了，使用三中的基本语法我们就基本可以很好地使用markdown了。额外的，markdown支持html语法，如果使用者有什么需求是markdown语法不能够实现的，我们可以通过html实现，笔者在这里举两个例子。
居中语法
markdown原本语法是不包含居中的，但我们可以通过html实现。
<center>居中标题</center>
上下角标
我们可以通过语法实现平方上角标和对数下角标的效果
x<sup>2</sup>
log<sub>2</sub>x

