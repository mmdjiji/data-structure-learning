# week2

程序填空题及主观题参考答案在 [ANSWERS.md](ANSWERS.md) 中，函数题参考答案为同目录下的 `.cpp` 文件。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
  - [Problem 2](#problem-2)
  - [Problem 3](#problem-3)
- [函数题](#函数题)
  - [2.1 用顺序结构线性表的基本操作实现整数集合的并集](#21-用顺序结构线性表的基本操作实现整数集合的并集)
  - [2.2 用顺序结构线性表实现字符串集合的差集](#22-用顺序结构线性表实现字符串集合的差集)
- [主观题](#主观题)
  - [Problem 1](#problem-1-1)
  - [Problem 2](#problem-2-1)
  - [Problem 3](#problem-3-1)

<!-- /TOC -->

## 程序填空题

### Problem 1
本题目比较两个顺序表的大小，需要用到顺序表的基本操作，请填空。
```c++
#include <stdio.h>
#include <stdlib.h>

typedef  int Status;
typedef  int ElemType;

#define TRUE 1
#define FALSE 0
#define  OK  1
#define  ERROR  -1
#define  OVERFLOW -2

typedef  int Status;
typedef  int ElemType;

//–––––线性表的动态分配顺序存储结构–––––
 #define LIST_INIT_SIZE    30  //线性表存储空间的初始分配
 #define LISTINCREMENT     10  //线性表存储空间的分配增量
 typedef   struct {
  ElemType   *elem;      //存储空间基址
  int        length;     //当前长度
  int        listsize;   //当前分配的存储容量(以sizeof(ElemType)为单位)
 }SqList;

//--------------基本操作-----------------
 Status InitList_Sq(SqList  &L)
 { L.elem=____1____;
   if(!L.elem)exit(OVERFLOW);
   L.length=____2____;
   L.listsize=LIST_INIT_SIZE;
   return OK;
 }//InitList_Sq      算法2.3

int ListLength_Sq(SqList L)
{____3____;
}

Status GetElem_Sq(SqList L,int i, ElemType &e)
{ if(____4____) return ERROR;
  e=____5____;
  return OK;
}

Status ListInsert_Sq(SqList &L,int i,ElemType e)
 {//  在顺序线性表L中第i个位置之前插入新的元素e,
  //  i的合法值为1≤i≤ListLength_Sq(L)+1
   ElemType *newbase,*p,*q;
   if (i<1||i>L.length+1) return ERROR;     //i 值不合法
   if (L.length>=L.listsize)                //当前存储空间已满,增加分配
     { newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
      if(!newbase)exit(OVERFLOW);           //存储分配失败
      L.elem=newbase;                       //新基址
      L.listsize +=LISTINCREMENT;           //增加存储容量
    }
   q = ____6____;                           //q为插入位置
   if(L.length>=1)
     for(p=____7____;p>=q;--p)
           ____8____;
   *q=e;                          //插入e
  ____9____;
   return OK;
 }//ListInsert_Sq

int LocateElem_Sq(SqList L,ElemType e, Status (*compare)(ElemType,ElemType))
{
 int i; ElemType *p;
 i = 1;
 p = L.elem;                                  //p的初值为第1个元素的存储位置
 while(____10____) ++i;
 if (i<=L.length)  ____11____;
 else return 0;
}//LocateElem_Sq
```

### Problem 2
已知顺序线性表 `La` 和 `Lb` 的元素按值非递减排列，合并 `La` 和 `Lb` 得到新的顺序线性表 `Lc` , `Lc` 的元素也按值非递减排列。
```c++
void MergeList_Sq(SqList La,SqList Lb, SqList &Lc)
{ int i,j,k;
  int La_len,Lb_len;
  ElemType ai,bj;
  ____1____;
  i=j=1;k=0;
  La_len=____2____;
  Lb_len=____3____;
  while( ____4____ )        //La和Lb均为空
   { GetElem_Sq(La,i,ai);GetElem_Sq(Lb,j,bj);
     if(ai<=bj) {____5____;++i;}
     else{____6____;++j;}
   }
  while(i<=La_len)
   { ____7____}
  while(j<=Lb_len)
   {____8____ }
}
```

### Problem 3
已知顺序线性表 `La` 和 `Lb` 的元素按值非递减排列，合并 `La` 和 `Lb` 得到新的顺序线性表 `Lc` , `Lc` 的元素也按值非递减排列。
```c++
void MergeList_Sq(SqList La,SqList Lb, SqList &Lc)
{ElemType *pa,*pb,*pc,*pa_last,*pb_last;
 pa = ____1____;
 pb = ____2____;
 Lc.listsize = Lc.length = La.length + Lb.length;
 pc = Lc.elem =(ElemType *)malloc(Lc.listsize * sizeof(ElemType));
 if (!Lc.elem) exit(OVERFLOW);            //存储分配失败
 ____3____ = La.elem + La.length - 1;
 ____4____ = Lb.elem + Lb.length - 1;
 while (pa<=pa_last && pb<=pb_last)       //归并
  {if ( *pa<= *pb) ____5____;
   else ____6____;
  }
 while(____7____)  *pc++=*pa++;
 while(____8____)  *pc++=*pb++;
}
```

## 函数题

### 2.1 用顺序结构线性表的基本操作实现整数集合的并集
用顺序结构线性表存放整数集合，请用SqList的基本操作实现整数集合的并集  
(1)需要定义用到的宏名（符号常量），如OK、OVERFLOW等  
(2)需要定义类型标识符Status  
(3)需要定义以下函数
```c++
Status InitList_Sq(SqList  &L);  
int ListLength_Sq(SqList L);  
Status GetElem_Sq(SqList L,int i, ElemType &e);  
Status ListInsert_Sq(SqList &L,int i,ElemType e);  
Status equal(ElemType x,ElemType  y);   //比较x与y是否相等
int LocateElem_Sq(SqList L,ElemType e, Status (*compare)(ElemType,ElemType));  
void union_Sq(SqList La,SqList Lb,SqList &Lc);  //线性表La、Lb分别表示集合A、B，C=A∪B
```
裁判测试程序样例:
```c++
#include <stdio.h>
#include <stdlib.h>

typedef  int ElemType;
#define LIST_INIT_SIZE    30 //线性表存储空间的初始分配
#define LISTINCREMENT     10  //线性表存储空间的分配增量
 typedef   struct {
  ElemType   *elem;    //存储空间基址
  int        length;   //当前长度
  int        listsize; //当前分配的存储容量(以sizeof(ElemType)为单位)
 }SqList;

/* 你的程序将嵌在这里 */

int main()
{int i,j,len;
 int m,n;   //分别存放两个集合初始长度
 ElemType e;
 SqList La,Lb,Lc;
 scanf("%d%d",&m,&n);
 InitList_Sq(La); InitList_Sq(Lb);  //建立两个空集
 for(i=1; i<=m; i++)  //建立第一个集合
  {scanf("%d",&e);  ListInsert_Sq(La,i,e);  }
 for(i=1; i<=n; i++)  //建立第二个集合
  {scanf("%d",&e);   ListInsert_Sq(Lb,i,e);  }
 union_Sq(La,Lb,Lc);  //计算集合La、Lb的交集Lc
 len=ListLength_Sq(Lc);
 for(i=1; i<=len; i++) //输出
  {GetElem_Sq(Lc,i,e); printf("%4d",e);  }
 return 0;
}
```
输入样例:
```
4 5
3 2 5 7
4 5 7 9 21
```
输出样例:
```
   3   2   5   7   4   9  21
```

### 2.2 用顺序结构线性表实现字符串集合的差集
本题的集合元素是字符串，请完善程序，实现字符串集合的差集运算。`A-B={e|e∈A且e∉B}`

裁判测试程序样例:
```c++
//这里只给出主函数，其他程序需要你编写。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType[20];

/* 你的程序将嵌在这里 */

int main()
{int i,j,len;
 ElemType e;
 SqList La,Lb,Lc;
 int m,n;   //分别存放两个集合初始长度
 printf("input the length of two set:\n");
 scanf("%d%d",&m,&n);
 InitList_Sq(La); InitList_Sq(Lb);   //建立两个空集
 printf("input the first set:\n ");
 for(i=0; i<m; i++)  //建立第一个集合
  {scanf(" %s",e);  ListInsert_Sq(La,i+1,e);  }  //注意有空格
 printf("input the second set:\n ");
 for(i=1; i<=n; i++)  //建立第二个集合
  {scanf(" %s",e);   ListInsert_Sq(Lb,i,e);  }  //注意有空格
 chaji_Sq(La,Lb,Lc);  //计算集合La、Lb的差集Lc
 printf("the chaji set is:\n");
 len=ListLength_Sq(Lc);
 for(i=1; i<=len; i++)
  {GetElem_Sq(Lc,i,e); printf("%s\n",e);  }
 DestroyList_Sq(La); DestroyList_Sq(Lb); DestroyList_Sq(Lc); //销毁3个集合（顺序表）
 return 0;
}
```
输入样例:
```
4  5
abc
def
kkkkkk
defg
aaa
def
hjklm
abc
ckjggg
```
输出样例:
```
kkkkkk
defg
```

## 主观题

### Problem 1
设 `n` 为正整数，试确定下列各程序段中前置以记号 `@` 的语句的频度:

(1)
```c++
i=1; k=0;
while(i<=n-1){
  @ k += 10 * i;
    i++;
}
```

(2)
```c++
i=1; k=0;
do{
  @ k += 10 * i;
  i++;
}while(i<=n-1);
```

(3)
```c++
i=1; k=0;
while(i<=n-1){
  i++;
  @ k += 10 * i;
}
```

(4)
```c++
k=0;
for(i=1; i<=n; i++){
  for(j=i; j<=n; j++)
    @ k++;
}
```

(5)
```c++
for(i=1; i<=n; i++){
  for(j=1; j<=i; j++){
    for(k=1; k<=j; k++){
      @ x += delta;
    }
  }
}
```

### Problem 2
设顺序表 `va` 中的数据元素递增有序。试写一算法，将 `x` 插入到顺序表的适当位置上，以保持该表的有序性。

函数接口定义: `Status ListInsert(SqList &va, ElemType x);`

### Problem 3
多项式可以写为: f(x) = a<sub>0</sub> + a<sub>1</sub>x + a<sub>2</sub>x<sup>2</sup> + ... + a<sub>n</sub>x<sup>n</sup>

现给定一个多项式的阶数 `n` ，并将全体系数存放在数组 `a[]` 里。请写程序计算这个多项式在给定点 `x` 处的值。试分析你的算法的复杂性（含时间和空间复杂性）。