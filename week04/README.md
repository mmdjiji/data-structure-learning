# week4

程序填空题及主观题参考答案在 [ANSWERS.md](ANSWERS.md) 中，函数题及编程题参考答案为同目录下的 `.cpp` 文件。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
- [函数题](#函数题)
  - [4.1.1 一元多项式加法](#411-一元多项式加法)
- [编程题](#编程题)
  - [4.2.1 多项式求导](#421-多项式求导)
- [主观题](#主观题)
  - [Problem 1](#problem-1-1)
  - [Problem 2](#problem-2)
  - [Problem 3](#problem-3)

<!-- /TOC -->

## 程序填空题

### Problem 1
```c++
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  -1
#define OVERFLOW -2

typedef  int Status;
typedef  int ElemType;

//–––––线性表的链式存储结构–––––
typedef  struct  LNode
{  ElemType       data;
   struct  LNode  *next;
}LNode, *LinkList;

//--------------基本操作-----------------
Status InitList(LinkList &L)
{ //建立一个空的链表，L为头结点指针.
   L=(LinkList )malloc(sizeof(LNode));   //生成头结点
   if(!L) return ERROR;
   ____1____;
   return OK;
} //InitList

Status DestroyList(LinkList &L)
{ LinkList p,q;
  p=L->next;
  while(____2____)
  {q=p->next;
   free(p);
   p=q;
  }
  free(L);
  return OK;
}

int ListEmpty(LinkList L)
{ if (____3____) return TRUE;
  else return FALSE;
}

Status GetElem(LinkList L, int i, ElemType &e)
{ //L为带头结点的循环单链表的头指针.
  //当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR
 LinkList p; int j;
 p = ____4____;
 j= 1;      //初始化,p指向第一个结点,j为计数器
 while ( ____5____ )
  {                   //顺指针向后查找,直到p指向第i个元素
    p = p->next ;   ++j;
  }
 if ( ____6____ ||j>i)  return ERROR ;          //第i个元素不存在
 e =____7____ ;                             //取第i个元素
 return OK;
} //GetElem

Status ListInsert(LinkList &L, int i, ElemType e)
{//在带头结点的循环链表L中第i个位置之前插入元素e
 LinkList p,s; int j;
 p = L; j = 0;
 while ( ____8____ )
      { p = p->next; ++j; }                     //寻找第i-1个结点
 if  ( j>i-1||j<i-1 )  return ERROR; //i 小于1或者大于表长
 s = (LinkList )malloc(sizeof(LNode));   //生成新结点
 if(!s) return ERROR;
 s->data = e; 
 s->next = ____9____;                 //插入L中
 ____10____;
 return OK;
}

Status ListDelete(LinkList &L, int i,  ElemType &e)
{ // 在带头结点的循环单链线性表L中,删除第i个元素,并由e返回其值
 int j;
 LinkList p,q;
 p = L;  j = ____11____;
 while( ____12____ )
  { p = p->next; ++j; }      //寻找第i个元素,并令p指向其前驱
 if ( ____13____ ||j>i-1)  return ERROR;   //删除位置不合理
 q = p->next;
 p->next = ____14____;             //删除并释放结点
 e = ____15____;
 free(q);
 return OK;
}
```

## 函数题

### 4.1.1 一元多项式加法
输入格式:  
输入数据为两行，分别表示两个多项式。  
每行多项式首先输入一个 `n` ，代表多项式的项数，接着是 `n` 对整数，每对整数的第一个是系数，第二个是指数。每个多项式不超过 `100` 项，整数间用空格隔开。

输出格式:  
输出数据是一行，表示结果多项式，依次是若干对整数，每对整数的第一个是系数，第二个是指数，每对整数间用逗号隔开。指数从小到大。如果结果多项式为 `0` ，则仅输出 `0` 。

裁判测试程序样例:
```c++
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define  OK  1
#define  ERROR  -1
#define  OVERFLOW -2
typedef int Status;

typedef struct
{ //项的表示,多项式的项作为LinkList的数据元素
  int    coef;        // 系数COEFFICIENT
  int    expn;        // 指数EXPONENT
}term, ElemType;  

typedef struct LNode	//结点类型
{ ElemType         data;	
 struct LNode    *next;
} *Link, *Position;
typedef  struct       //链表类型
{Link  head, tail;    //分别指向线性链表中的头结点和最后一个结点
 int   len;           //指向线性链表中数据元素的个数
}LinkList;
typedef  LinkList  polynomial;   //用带表头结点的有序链表表示多项式

/* 请在这里填写答案 */

int main()
{  polynomial  Pa,Pb;
   int m,n;
   Position ha,hb,qa,qb;
   term a;
   scanf("%d",&m);
   CreatePolyn(Pa, m);
   scanf("%d",&n);
   CreatePolyn(Pb, n);  
   AddPolyn (Pa, Pb);
   if(Pa.len==0) { printf("0\n"); return 0;}
   ha=GetHead(Pa);       //ha和hb分别指向Pa和Pb的头结点
   qa=NextPos(Pa,ha);
   while(qa)
   { printf("%d,%d\n",qa->data.coef,qa->data.expn);
     ha=qa;
     qa = NextPos(Pa,ha);  
   }
    return 0;
}
```
输入样例:
```
3 5 2 4 1 7 0
2 1 4 -4 1
```
输出样例:
```
7,0
5,2
1,4
```

## 编程题

### 4.2.1 多项式求导
设计程序求一元多项式的导数。

输入格式:  
输入一共 `2` 行，第一行是多项式的项数，第二行给出每一项的系数和指数。系数和指数都是绝对值不超过 `1000` 的整数。系数不可能为 `0` 。

输出格式:  
输出多项式求导后每一项的系数和指数，中间用空格隔开，但结尾不能有多余空格。指数递增有序

输入样例1:
```
4
3 4 -5 2 6 1 -2 0
```
输出样例1:
```
6 0 -10 1 12 3
```
输入样例2:
```
1
-2 0
```
输出样例2:
```
0 0
```

## 主观题

### Problem 1
试写一个算法，识别依次读入的一个以 `@` 为结束符的字符序列是否为形如 `序列1&序列2` 模式的字符序列。其中序列1和序列2中都不含字符 `&` 且序列2是序列1的逆序列。例如， `a+b&b+a` 是属该模式的字符序列，而 `1+3&3-1` 则不是。

### Problem 2
假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素节点（注意不设头指针），试编写相应的队列初始化、入队列和出队列的算法。

### Problem 3
假设将循环队列定义为：以变量 `rear` 和 `length` 分别表示循环队列中队尾元素的位置和内含元素的个数。试写出循环队列的物理结构及相应的入队列和出队列的算法（在出队列的算法中要返回队头元素）。