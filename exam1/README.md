# exam1

参考答案在 [ANSWERS.md](ANSWERS.md) 中。

<!-- TOC -->

- [客观题](#客观题)
- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
  - [Problem 2](#problem-2)
  - [Problem 3](#problem-3)
  - [Problem 4](#problem-4)
  - [Problem 5](#problem-5)
- [主观题](#主观题)
  - [Problem 1](#problem-1-1)
  - [Problem 2](#problem-2-1)

<!-- /TOC -->

## 客观题

1. 在存储数据时，通常不仅要存储数据元素的值，而且还要存储  
  A. 数据的处理方法  
  B. 数据元素之间的关系  
  C. 数据元素的类型  
  D. 数据的存储方法

2. 数据结构中数据元素之间逻辑关系被称为  
  A. 数据的存储结构  
  B. 数据的物理结构  
  C. 数据的逻辑结构  
  D. 数据的线性结构

3. 计算机算法必须具备输入、输出和 () 5个特性。  
  A. 确定性、有穷性和稳定性  
  B. 可行性、确定性和有穷性  
  C. 可行性、可移植性和可扩充性  
  D. 易读性、健壮性和正确性

4. 下面程序段的时间复杂性的量级为  
  A. O(i×j×k)  
  B. O(n×j×k)  
  C. O(n×m×k)  
  D. O(n×m×w)
  ```c++
  for(i=1;i<=n; i++)
   for(j=1;j<=m; j++){
        c[i][j]=0;
        for(k=1;k<=w;k++)
           c[i][j]+=a[i][k]*b[k][j];
  }
  ```

5. 算法分析的主要任务是分析  
  A. 算法是否具有较好的可读性  
  B. 算法的执行时间和问题规模之间的关系  
  C. 算法的功能是否符合设计要求  
  D. 算法中是否存在语法错误

6. 数据在计算机的存储器中表示时，逻辑上相邻的两个元素对应的物理地址也是相邻的，这种存储结构称之为  
  A. 逻辑结构  
  B. 线性链表  
  C. 链式存储结构  
  D. 顺序存储结构

7. 线性表的基本运算 `ListInsert(&L,i,e)` 表示在线性表 `L` 中第 `i` 个位置上插入一个元素 `e` ，若 `L` 的长度为 `n` ，则 `i` 的合法取值是  
  A. `1≤i≤n`  
  B. `1≤i≤n+1`  
  C. `0≤i≤n-1`  
  D. `0≤i≤n`

8. 链表不具有的特点是  
  A. 可随机访问任一元素  
  B. 不必事先估计存储空间  
  C. 所需存储空间与线性表程度成正比  
  D. 插入、删除不需要移动元素

9. 非空单链表中，若指针 `p` 所指结点是尾结点，则 () 表达式为真。  
  A. `p->next==NULL`  
  B. `p==NULL`  
  C. `p->next!=NULL`  
  D. `p->next==p`

10.  在一个双链表中，删除 `*p` 结点之后的一个结点的操作是 () 。  
  A. `p->next=p->next->next; p->next->next->prior=p;`  
  B. `p->next->prior=p; p->next=p->next->next;`  
  C. `p->next=p->next->next; p->next->prior=p;`  
  D. `p->next->next=p->next; p->next->prior=p;`

11.  若某线性表中最常用的操作是取第i个元素和找第i个元素的前趋元素，则采用 () 存储方式最节省运算时间。  
  A. 双链表  
  B. 单循环链表  
  C. 单链表  
  D. 顺序表

12. 对于长度为 `n(n≥1)` 的双链表 `L` ，在 `p` 所指结点之前插入一个新结点的算法的时间复杂度为  
  A. `O(1)`  
  B. `O(n)`  
  C. `O(n​²)`  
  D. `O(nlogn)`

13. () 属于物理结构。  
  A. 线性表  
  B. 线性链表  
  C. 栈  
  D. 树

14. 经过下列栈运算后， `StackEmpty(S)` 的值是  
  A. `a`  
  B. `b`  
  C. `0`  
  D. `1`
  ```c++
  InitStack(S);
  Push(S, a);
  Push(S, b);
  Pop(S, x);
  Pop(S, y);
  ```

15. 设一个栈的输入序列为 `A` 、 `B` 、 `C` 、 `D` ，得到的输出序列不可能是  
  A. `ABCD`  
  B. `DCBA`  
  C. `ACDB`  
  D. `DABC`

16. 栈和队列的不同点是  
  A. 都是线性表  
  B. 都不是线性表  
  C. 栈只能在同一端进行插入删除操作，而队列在不同端进行插入删除操作  
  D. 栈可以采用顺序结构，队列只能采用链式结构

17. 当利用大小为N的一维数组顺序存储一个循环队列时，该队列的最大长度为  
  A. `N-2`  
  B. `N-1`  
  C. `N`  
  D. `N+1`

18. 现采用大小为 `10` 的数组实现一个循环队列。设在某一时刻，队列为空且此时 `front` 和 `rear` 值均为 `5` 。经过若干操作后， `front` 为 `8` ， `rear` 为 `2` ，问：此时队列中有 () 个元素。  
  A. `4`  
  B. `5`  
  C. `6`  
  D. `7`

19.  元素 `a,b,c,d,e` 依次加入初始为空的栈中，若元素进栈后可停留，可出栈，直到所有元素都出栈，则在所有可能的出栈序列中，以元素 `d` 开头的序列个数是  
  A. `5`  
  B. `6`  
  C. `3`  
  D. `4`

20. 对于链队，在进行删除操作时  
  A. 仅修改头指针  
  B. 仅修改尾指针  
  C. 头、尾指针都要修改  
  D. 头、尾指针可能都要修改

## 程序填空题

### Problem 1
本题目要求删除顺序表的第i个元素。
```c++
 typedef   struct {
  ElemType   *elem;    //存储空间基址
  int        length;   //当前长度
  int        listsize; //当前分配的存储容量(以sizeof(ElemType)为单位)
 }SqList;

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {  
ElemType *p,*q;
if (i<1 || i>L.length) return ERROR;  // i值不合法
  p = ____1____ ;   // p为被删除元素的位置
  e = *p;           
  q =  ____2____ ;  // 表尾元素的位置
  for (  ; ____3____ ; ++p)   
      ____4____ ;   // 被删除元素之后的元素左移
    ____5____ ;  
  return OK;
}
```

### Problem 2
本题目要求实现带头结点链队列的出队操作。
```c++
typedef struct Node
{    ElemType data;
    struct Node *next;
}Node,*Ptr;
typedef struct
{    Ptr front;
    Ptr rear;
}LinkQueue;

Status DeQueue(LinkQueue &Q, QElemType &e)
{//若队列不空,则删除Q的队头元素,用e返回其值,
  //并返回OK;  否则返回ERROR
  QueuePtr p;
  if( ____1____ ) return ERROR;
  p = Q.front->next;  
  e = p->data;
  Q.front->next = ____2____;
  if(Q.rear==p) ____3____;
  free(p);
  return OK;
}
```

### Problem 3
本题目要求在非递减有序的顺序表L中插入元素x，插入后仍然有序。
```c++
typedef struct {
    ElemType  elem[100];
    int length;   // 当前长度    
}SqList;

Status ListInsert(SqList &L, ElemType x)  
{ 
  if (  L.length>=100  ) 
       return ERROR;
  for(i=1; i<=L.length; i++) 
       if( ____1____ ) break;
  for(j=L.length; j>=i; j--)   
      ____2____ ;         
  ____3____ ;      //插入
  ____4____ ;
return OK;
}
```

### Problem 4
文章中假设只能出现方括号，本题目要求检查一行字符中方括号是否匹配。
例如 `x[ y+ z]=t[[c+ y]];` 是匹配的。 `x[ y+z]=t[[c+y];` 是不匹配的

```c++
Status match( )
{    SqStack S;
    SElemType ch[80],t;
    int i=0;
    InitStack(S);
    scanf("%s",ch);
    while (ch[i]!= '\0')
      { if ( ch[i]== '[' )
          ____1____;
        else  if (ch[i]== ']')
                { if( ____2____ ) return ERROR;
                 ____3____;
                 if (t!= '[' ) return ERROR;
                }
        i++;
     }
   if( ____4____ ) return ERROR; else return  OK;
}
```

### Problem 5
已知线性表 `La` 和 `Lb` 的元素按值非递增排列，归并 `La` 和 `Lb` 得到新的线性表 `Lc` , `Lc` 的元素按值非递减排列

输入示例:
```
7 5 3 1
8 6 4 3 2
```
输出示例:
```
1 2 3 3 4 5 6 7 8
```
```c++
void MergeList(List La, List Lb, List &Lc)
{  int i,j,La_len,Lb_len;
   ElemType ai,bj;
  InitList(Lc);
  i=j=1;
  La_len= ListLength(La);   Lb_len= ListLength(Lb);
  while( ____1____ )
   { GetElem(La,i,ai);   GetElem(Lb,j,bj);
      if(ai>=bj) {  ____2____ ; i++;  }
      else{ ____3____ ;  j++; }
   }
  while(i<=La_len)
   {  ____4____ }
  while(j<=Lb_len)
   {  ____5____ }
}
```

## 主观题

### Problem 1
写一算法，删除顺序表中所有值小于 `max` 且大于 `min` (若表中存在这样的元素)的数据元素，返回删除元素的个数。
函数原型定义如下:
```c++
typedef int ElemType;
int Delete(SqList &L, ElemType min, ElemType max);
```
### Problem 2
利用栈和队列的基本操作，将队列中值介于 `min` 和 `max` 之间的元素从队列中删除，并逆序存放到原队列 `Q` 中:
```c++
void change(Queue &Q, ElemType min, ElemType max);
```