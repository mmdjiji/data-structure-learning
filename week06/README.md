# week6

程序填空题及主观题参考答案在 [ANSWERS.md](ANSWERS.md) 中，编程题参考答案为同目录下的 `.cpp` 文件。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
  - [Problem 2](#problem-2)
- [编程题](#编程题)
  - [6.1 计算后缀表达式的值](#61-计算后缀表达式的值)
  - [6.2 中缀表达式转换为后缀表达式](#62-中缀表达式转换为后缀表达式)
  - [6.3 符号配对](#63-符号配对)
- [主观题](#主观题)
  - [Problem 1](#problem-1-1)
  - [Problem 2](#problem-2-1)
  - [Problem 3](#problem-3)
  - [Problem 4](#problem-4)

<!-- /TOC -->

## 程序填空题

### Problem 1
本题目要求实现循环队列的基本操作，请填空。
```c++
//–––––循环队列──队列的顺序存储结构–––––
#define MAXQSIZE   100      //最大队列长度
typedef  struct
{____1____ base;   //初始化的动态分配存储空间
 ____2____ front;  //头指针,若队列不空,指向队列头元素
 ____3____ rear;   //尾指针,若队列不空,指向队列尾元素的下一个位置
}SqQueue;
Status InitQueue(SqQueue &Q)
{//  构造一个空队列Q
  Q.base = ____4____;
  if (!Q.base)  exit(OVERFLOW);  //存储分配失败
  Q.front = ____5____;
  Q.rear = ____6____;
  return OK;
}
int QueueLength(SqQueue Q)
{//返回Q的元素个数,即队列的长度
  return ____7____ ;
}
Status EnQueue(SqQueue &Q,QElemType e)
{// 插入元素e为Q的新的队尾元素
   if( ____8____ )   //队列满
        return ERROR;                                      
   ____9____=e;
   ____10____;
   return OK;
}
Status DeQueue(SqQueue &Q, QElemType &e)
{// 删除队头元素，送给变量e
  if( ____11____ ) return ERROR;   //队列空
  e= ____12____ ;
  ____13____;
  return OK;
}
Status QueueEmpty(SqQueue Q)
{ if( ____14____ ) return TRUE;
  return FALSE;
}
```

### Problem 2
```c++
typedef  int  Status;
typedef char QElemType;

//–––––队列的链式存储结构–––––
typedef  struct QNode
{QElemType     data;
 struct QNode   *next;
}QNode, *QueuePtr;

typedef struct
{  ____1____  front;      //队头指针
   ____2____  rear;       //队尾指针
}LinkQueue;

Status InitQueue(LinkQueue &Q)
{// 构造一个空队列Q
 Q.front = Q.rear = ____3____ ;
 if(!Q.front) exit(OVERFLOW);     //存储分配失败
 ____4____;
 return OK;
}

Status DestroyQueue(LinkQueue &Q)
{// 销毁队列Q
while(Q.front)
 { Q.rear = Q.front->next;
   ____5____;
   Q.front = ____6____;
 }
return OK;
}

int QueueLength(LinkQueue Q)
{//返回Q的元素个数,即队列的长度
  QueuePtr p;
  int len=0;
  p=____7____;
  while(____8____)
  {
      len++;
     ____9____;
  }
  return len;
}
Status EnQueue(LinkQueue &Q, QElemType e)
{// 插入元素e为Q的新的队尾元素
  QueuePtr p;
  p = (QueuePtr)malloc(sizeof(QNode));
  if(!p)  exit(OVERFLOW);        //存储分配失败
  p->data = e;   p->next = NULL;
  ____10____;  
  Q.rear =____11____ ;
  return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{//若队列不空,则删除Q的队头元素,用e返回其值,
//并返回OK;  否则返回ERROR
  QueuePtr p;
  if( ____12____ ) return ERROR;
  p = Q.front->next; 
  e = ____13____;
  ____14____;
  if(____15____)Q.rear = Q.front;
  free(p);
  return OK;
}

Status QueueEmpty(LinkQueue Q)
{ if( ____16____ ) return TRUE;
  return FALSE;
}
```

## 编程题

### 6.1 计算后缀表达式的值
输入一行字符表示后缀表达式，表达式中运算对象是个位数字，运算符有 `+` , `-` , `*` , `/` , `%` ，都是双目运算符，表达式结果用浮点数记录。

输入格式:  
输入在一行中给出一个后缀表达式。

输出格式:  
输出后缀表达式的值，保留小数点后2位。

输入样例:
```
62/3*
```
输出样例:
```
9.00
```

### 6.2 中缀表达式转换为后缀表达式
输入一行字符表示中缀表达式，表达式中运算对象是单个字母或个位数字，运算符有 `+` , `-` , `*` , `/` , `%` ，中缀表达式中可以有圆括号。运算对象是变量和常数，变量用一个字母表示，常量是个位整数。

输入格式:  
输入在一行中给出一个中缀表达式。

输出格式:  
输出对应的后缀表达式。

输入样例:
```
(a+b)*c
```
输出样例:
```
ab+c*
```

### 6.3 符号配对
请编写程序检查C语言源程序中下列符号是否配对：`/*` 与 `*/` 、 `(` 与 `)` 、 `[` 与 `]` 、 `{` 与 `}` 。

输入格式:
输入为一个C语言源程序。当读到某一行中只有一个句点.和一个回车的时候，标志着输入结束。程序中需要检查配对的符号不超过100个。

输出格式:
首先，如果所有符号配对正确，则在第一行中输出 `YES` ，否则输出 `NO` 。然后在第二行中指出第一个不配对的符号：如果缺少左符号，则输出 `?-右符号` ；如果缺少右符号，则输出 `左符号-?` 。

输入样例1:
```c++
void test()
{
    int i, A[10];
    for (i=0; i<10; i++) /*/
        A[i] = i;
}
.
```
输出样例1:
```
NO
/*-?
```
输入样例2:
```c++
void test()
{
    int i, A[10];
    for (i=0; i<10; i++) /**/
        A[i] = i;
}]
.
```
输出样例2:
```
NO
?-]
```
输入样例3:
```c++
void test()
{
    int i
    double A[10];
    for (i=0; i<10; i++) /**/
        A[i] = 0.1*i;
}
.
```
输出样例3:
```
YES
```

## 主观题

### Problem 1
已知:  
森林的先序次序访问序列为: `ABCDEFGHIJKL`  
森林的中序次序访问序列为: `CBEFDGAJIKLH`  
画出对应的森林。

### Problem 2
学生成绩分布情况如下表所示，现有 `10000` 个学生成绩数据，需要由百分制成绩转换为五分制数据，利用哈夫曼树(要求画出类似书上图6.27(b)的表格)，设计最好的比较判断逻辑结构，并算出最少需要多少次比较。
|**分数段**|0\~59|60\~69|70\~79|80\~89|90\~100|
|-|-|-|-|-|-|
|**比例**|0.05|0.15|0.40|0.30|0.10|
|**五分制**|不及格|及格|中|良|优|

### Problem 3
试编写算法，对一棵以孩子-兄弟链表表示的树，计算其叶子节点的个数。

### Problem 4
两棵二叉树 `T1` 和 `T2` 是等价的，是指 `T1` 和 `T2` 具有相同的形态(结构)，且对应节点中包含相同的数据信息。写一算法，判断两棵二叉树是否等价。