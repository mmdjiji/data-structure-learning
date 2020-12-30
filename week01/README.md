# week1

程序填空题和主观题参考答案在 [ANSWERS.md](ANSWERS.md) 中，函数题及编程题参考答案为同目录下的 `.c` 或 `.cpp` 文件。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
- [函数题](#函数题)
  - [1.1.1 复数运算](#111-复数运算)
- [编程题](#编程题)
  - [1.2.1 成绩查询](#121-成绩查询)
  - [1.2.2 计算平均数、中位数和众数](#122-计算平均数中位数和众数)
  - [1.2.3 删除链表中指定值的节点](#123-删除链表中指定值的节点)
  - [1.2.4 最大子列和问题](#124-最大子列和问题)
- [主观题](#主观题)
  - [Problem 1](#problem-1-1)
  - [Problem 2](#problem-2)

<!-- /TOC -->

## 程序填空题

### Problem 1
本程序的功能是用动态数组编程输入任意 `m` 个班学生(每班 `n` 个学生)的某门课的成绩，计算最高分，并指出具有该最高分成绩的学生是第几个班的第几个学生。其中， `m` 和 `n` 的值由用户从键盘任意输入。
```c++
#include  <stdio.h>
#include  <stdlib.h>
void InputScore(int *p, int m, int n);
int  FindMax(int *p, int m, int n, int *pRow, int *pCol);
int main()
{ 
  int  *pScore, m, n, maxScore, row, col;
  scanf("%d,%d", &m, &n);  
  ____1____;     /* 申请动态内存 */

  if (pScore == NULL) 
  {   printf("No enough memory!\n");    exit(0);   }
  InputScore(pScore, m, n);
  maxScore = FindMax(____2____);

  printf("maxScore = %d, class = %d, number = %d\n", maxScore, row+1, col+1);                            
  free(pScore);   /* 释放动态内存 */
  return 0;
}

/* 函数功能：输入m行n列二维数组的值 */
void InputScore(int *p, int m, int n) 
{
    int i, j;
    //printf("Input %d*%d array:\n", m, n);
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            scanf("%d", ____3____); 
        }
    }
}
/*  函数功能：计算任意m行n列二维数组中元素的最大值，并指出其所在行列下标值 */
int  FindMax(int *p, int m, int n, int *pRow, int *pCol)    
{ int  i, j, max = p[0];
 ____4____;
 ____5____;
 for (i=0; i<m; i++)
 {  for (j=0; j<n; j++)
     { if (____6____)        
         {
             max = p[i*n+j];
             *pRow = i;   /*记录行下标*/
             *pCol = j;   /*记录列下标*/
         } 
     }  
 }  
 return max;                
}
```

## 函数题

### 1.1.1 复数运算
请设计并实现复数加法、减法、乘法运算的函数。

裁判测试程序样例:
```c++
#include <stdio.h>
struct fushu{
    float shibu;
    float xubu;
};
/* 你的程序将放在这里 */
int main()
{
    struct fushu a,b,c,d;
    scanf("%f%fi",&a.shibu,&a.xubu);      //输入第一个复数
    scanf("%f%fi",&b.shibu,&b.xubu);      //输入第二个复数
    add(a,b);                             //计算a=a+b
    mul(a,b);                             //计算a=a*b
    scanf("%f%fi",&c.shibu,&c.xubu);      //输入第三个复数
    sub(a,c);                             //计算a=a-c
    if(a.xubu>0)
      printf("%.2f+%.2fi\n",a.shibu,a.xubu);
    else if(a.xubu<0) printf("%.2f%.2fi\n",a.shibu,a.xubu);
    else printf("%.2f\n",a.shibu);
    return 0;
}
```

输入样例:
```
1+2i
3+4i
5+6i
```
输出样例:
```
-17.00+28.00i
```

## 编程题

### 1.2.1 成绩查询
输入 `N` 个同学的成绩，查询某个同学的成绩。如果没有找到输出 `not found!`  
本题目要求用链表存放每个同学的数据(包括学号、姓名、成绩)。

输入格式:  
输入共 `N+2` 行，第一行是学生人数 `N` ，接下来 `N` 行是 `N` 个学生的数据，最后一行是一个学号。

输出格式:  
输出只有一行，是一个整数或 `not found!` 。

输入样例:
```
5
s104  zhangshan   95
t321  lisi  88
p005  maliu   79
s109  wangjun  90
t349  lili  67
t321
```
输出样例:
```
88
```

### 1.2.2 计算平均数、中位数和众数
在调查数据分析(Survey data analysis)中经常需要计算平均数、中位数和众数。用函数编程计算 `40` 个输入数据(每个数据是取值 `1~10` 之间的任意整数)的平均数(Mean)、中位数(Median)和众数(Mode)。中位数指的是排列在数组中间的数。众数是数组中出现次数最多的那个数(不考虑两个或两个以上的输入数据出现次数相同的情况)。

计算中位数时，首先要调用排序函数对数组按升序进行排序，然后取出排序后数组中间位置的元素 `answer[n/2]` ，就得到了中位数。如果数组元素的个数是偶数，那么中位数就等于数组中间那两个元素的算术平均值。

输入格式:  
输入共4行，每行中给出10个1-10之间的整数，用空格隔开。

输出格式:  
输出共三行，分别按制定格式输出平均数、中位数和众数。
```
Mean value=%d\n
Median value=%d\n
Mode value=%d\n
```

输入样例:
```
10 9 10 8 7 6 5 10 9 8
8 9 7 6 10 9 8 8 7 7
6 6 8 8 9 9 10 8 7 7
9 8 7 9 7 6 5 9 8 7
```
输出样例:
```
Mean value=7
Median value=8
Mode value=8
```

### 1.2.3 删除链表中指定值的节点
输入若干个整数，建立链表，删除其中所有值为k的结点。本题目要求用链表实现。

输入格式:  
输入共二行。  
第一行，以数字0结束的若干非零整数作为新建链表的各节点值；  
第二行，一个整数k作为要删除的值。

输出格式:  
删除后的链表中各节点值，没有分隔符。

输入样例:
```
4 2 1 3 3 2 0
3
```
输出样例:
```
4212
```

### 1.2.4 最大子列和问题
给定 K 个整数组成的序列 { N<sub>1</sub>, N<sub>2</sub>, ..., N<sub>K</sub> }，“连续子列”被定义为{ N<sub>i</sub>, N<sub>i+1</sub>, ..., N<sub>j</sub> }，其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列 { -2, 11, -4, 13, -5, -2 } ，其连续子列 { 11, -4, 13 } 有最大的和 20 。现要求你编写程序，计算给定整数序列的最大子列和。

本题旨在测试各种不同的算法在各种数据情况下的表现。各组测试数据特点如下:
  * 数据1: 与样例等价，测试基本正确性；
  * 数据2: 10<sup>2</sup>个随机整数；
  * 数据3: 10<sup>3</sup>个随机整数；
  * 数据4: 10<sup>4</sup>个随机整数；
  * 数据5: 10<sup>5</sup>个随机整数；

输入格式:  
输入第1行给出正整数 K (≤100000) ；第2行给出 K 个整数，其间以空格分隔。

输出格式:  
在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

输入样例:
```
6
-2 11 -4 13 -5 -2
```
输出样例:
```
20
```

## 主观题

### Problem 1
写出下列程序的执行结果
```c++
void f1(int x)
{ x++; printf("in f1, x=%d\n" , x);}
void f2(int &x)
{ x++; printf("in f2, x=%d\n" , x);}
int main()
{ int n=1;
  f1(n);
  printf("after f1, n=%d\n" , n);
  n=1;
  f2(n);
  printf("after f2, n=%d\n" , n);
  return 0;
}
```

### Problem 2
图书存放  
现有 `N`(`N>100000`) 本图书，请问你将怎样在图书馆摆放这些书？并说明如何在其中查找“数据结构与算法”这本书，如何插入“数据结构与算法习题集”？你的图书摆放方式采用的是哪种数据结构？