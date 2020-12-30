# week3

程序填空题及主观题参考答案在 [ANSWERS.md](ANSWERS.md) 中，函数题及编程题参考答案为同目录下的 `.cpp` 文件。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
  - [Problem 2](#problem-2)
- [函数题](#函数题)
  - [3.1.1 集合的交集（单链表）](#311-集合的交集单链表)
- [编程题](#编程题)
  - [3.2.1 求链式线性表的倒数第K项](#321-求链式线性表的倒数第k项)
  - [3.2.2 链表去重](#322-链表去重)
  - [3.2.3 生死者游戏](#323-生死者游戏)
- [主观题](#主观题)
  - [Problem 1](#problem-1-1)
  - [Problem 2](#problem-2-1)
  - [Problem 3](#problem-3)

<!-- /TOC -->

## 程序填空题

### Problem 1
两个有序链表合并过程中需要用到单链表的基本操作，请填空。
```c++
typedef  int Status;
typedef  int ElemType;

//–––––线性表的链式存储结构–––––
typedef  struct  LNode
{  ElemType       data;
  ____1____next;
}LNode, *LinkList;

//--------------基本操作-----------------
Status InitList_L(LinkList &L)
{ //建立一个空的链表，L为带头结点的单链表的头指针.
   L=____2____;   //生成头结点
   if(!L) return ERROR;
   L->next=____3____; 
     return OK;
} //InitList_L

Status ListInsert_L(LinkList &L, int i, ElemType e)
{//在带头结点的单线性链表L中第i个位置之前插入元素e
 LinkList p,s; int j;
 p = L; j = 0;
 while ( p && j<i-1 )
      { ____4____ }          //寻找第i-1个结点
 if  (!p||j>i-1)  return ERROR;     //i 小于1或者大于表长
 s = (LinkList )malloc(sizeof(LNode));   //生成新结点
 s->data = e; s->next = ____5____;                 //插入L中
 ____6____;
 return OK;
}//ListInsert_L

int LocateElem_L(LinkList L,ElemType e, Status (*compare)(ElemType,ElemType))
{ //在线性链表L中查找第1个值与e满足compare()的元素的位序
  //若找到,则返回其在L中的位序,否则返回0
 int i; LinkList p;
 i = 1;                                            //i的初值为第1个元素的位序
 p = ____7____;                         //p的初值为第1个元素的存储位置
 while(  ____8____ )
 {  ++i; p=p->next;}
 if (p) ____9____;
 else ____10____;
}//LocateElem_Sq

Status GetElem_L(LinkList L, int i, ElemType &e)
{ //L为带头结点的单链表的头指针.
  //当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR
 LinkList p; int j;
  ____11____; 
  ____12____; 
 while ( p&& j<i )
  {                   //顺指针向后查找,直到p指向第i个元素或p为空
   ____13____
  }
 if (!p||j>i)  return ERROR ;          //第i个元素不存在
 e = ____14____;                           //取第i个元素
 return OK;
} //GetElem_L

int ListEmpty_L(LinkList L)
{ if (____15____) return TRUE;
  else return FALSE;
}

int ListLength_L(LinkList L)
{LinkList p;
 int len=0;
 p=____16____;
 while(p)
 {
    ____17____
 }
 return len;
}

Status ListDelete_L(LinkList &L, int i,  ElemType &e)
{ // 在带头结点的单链线性表L中,删除第i个元素,并由e返回其值
 int j;
 LinkList p,q;
 p = L;  j = 0;
 while( ____18____ )
  { p = p->next; ++j; }      //寻找第i个元素,并令p指向其前驱
 if (!(p->next)||j>i-1)  return ERROR;   //删除位置不合理
 q = ____19____;   
 ____20____;             //删除并释放结点
 e = ____21____;
 free(q);
 return OK;
}
```

### Problem 2
已知顺序线性表 `La` 和 `Lb` 的元素按值非递减排列，合并 `La` 和 `Lb` 得到新的顺序线性表 `Lc` , `Lc` 的元素也按值非递减排列。线性表采用单链表的存储结构。
```c++
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{ //已知单链线性表La和Lb的元素按值非递减排列
//归并La和Lb得到新的单链线性表Lc,Lc的元素也按值非递减排列
  LinkList pa,pb,pc;
   pa = ____1____;  pb = ____2____;
  Lc = pc = La;                         //用La的头结点作为Lc的头结点
  while( ____3____ )
     if (pa->data<= pb->data)
      { ____4____ }
     else{ ____5____ }
   pc->next = ____6____;                   //插入剩余段
   free(Lb);                               //释放Lb的结点
}//MergeLis
```

## 函数题

### 3.1.1 集合的交集（单链表）
用带头结点的单链表表示字符集合，用基本操作实现字符集合的交集。请先实现单链表的基本操作。

裁判测试程序样例:
```c++
#include<stdio.h>
#include <stdlib.h>

typedef  char ElemType;
typedef  struct  LNode
{  ElemType       data;
   struct  LNode  *next;
}LNode, *LinkList;

/* 你的程序将嵌在这里 */
int main()
{int i,j,len;
 ElemType e;
 LinkList La,Lb,Lc;
 int m,n;        //分别存放两个集合初始长度
 scanf("%d%d",&m,&n);  getchar();
 InitList(La); InitList(Lb);           //建立两个空集
 for(i=1; i<=m; i++)               //建立第一个集合
  {scanf("%c",&e);  ListInsert(La,i,e);  } 
 getchar();
 for(i=1; i<=n; i++)              //建立第二个集合
  {scanf("%c",&e);  
  ListInsert(Lb,i,e);  }
 jiaoji(La,Lb,Lc);                   //计算集合La、Lb的交集Lc
//输出结果
 len=ListLength(Lc);
 for(i=1; i<=len; i++)
  {GetElem(Lc,i,e); printf("%c",e);  }
 //printf("\n");
 DestroyList(La); DestroyList(Lb); DestroyList(Lc);      //销毁3个集合
 return 0;
}
```
输入样例:
```
3 5
abc
decbf
```
输出样例:
```
cb
```

## 编程题

### 3.2.1 求链式线性表的倒数第K项
给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第 `K` 个位置上的数字。

输入格式:  
输入首先给出一个正整数 `K` ，随后是若干非负整数，最后以一个负整数表示结尾（该负数不算在序列内，不要处理）。

输出格式:  
输出倒数第 `K` 个位置上的数据。如果这个位置不存在，输出错误信息 `NULL` 。

输入样例:
```
4 1 2 3 4 5 6 7 8 9 0 -1
```
输出样例:
```
7
```

### 3.2.2 链表去重
给定一个带整数键值的链表 `L`，你需要把其中绝对值重复的键值结点删掉。即对每个键值 `K`，只有第一个绝对值等于 `K` 的结点被保留。同时，所有被删除的结点须被保存在另一个链表上。例如给定 `L` 为 `21→-15→-15→-7→15`，你需要输出去重后的链表 `21→-15→-7`，还有被删除的链表 `-15→15`。

输入格式:
输入在第一行给出 `L` 的第一个结点的地址和一个正整数 `N`（≤10<sup>5</sup>，为结点总数）。一个结点的地址是非负的 `5` 位整数，空地址 `NULL` 用 `-1` 来表示。

随后 `N` 行，每行按以下格式描述一个结点：
```
地址 键值 下一个结点
```
其中地址是该结点的地址，键值是绝对值不超过10<sup>4</sup>的整数，下一个结点是下个结点的地址。

输出格式:  
首先输出去重后的链表，然后输出被删除的链表。每个结点占一行，按输入的格式输出。

输入样例:
```
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
```
输出样例:
```
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
```

### 3.2.3 生死者游戏
有 `n` 个旅客同乘一条船，因为船发生故障，最多只能留下一半旅客。大家议定如下办法： `n` 个人围成一圈，由第一个人起，依次报数，报到 `m` 的人必须被扔进大海。如此循环。问最后哪些旅客仍留在船上？每个人都有一个 `m` 值，当他被扔进大海后， `m` 的值改为这个人的 `m` 值。 `m` 的初值由第一个人决定。

输入格式:  
输入共二行，第一行为人数 `n` ，第二行为 `n` 个整数，代表每个人的 `m` 值。

输出格式:  
在一行中输剩下乘客的编号（用 `%3d` 格式输出）。

输入样例:
```
10
2 3 4 3 2 4 3 6 3 2
```
输出样例:
```
  1  4  6  8  9
```

## 主观题

### Problem 1
已知线性表中的元素以值递增有序排列，并以单链表（带头结点）作存储结构，试写一高效的算法，删除表中所有值大于 `mink` 且小于 `maxk` 的元素（若表中存在这样的元素）同时释放被删结点空间，并分析你的算法的时间复杂度（注意: `mink` 和 `maxk` 是给定的两个参变量，它们的值可以和表中的元素相同，也可以不同）

### Problem 2
试写一算法，对单链表实现就地逆置。

### Problem 3
已知由一个线性链表表示的线性表中含有三类字符的数据元素（如，字母字符、数字字符和其他字符），试编写算法将该链表分割为三个循环链表，其中每个循环链表表示的线性表中只含一类字符。