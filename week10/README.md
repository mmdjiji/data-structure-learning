# week10

程序填空题及主观题参考答案在 [ANSWERS.md](ANSWERS.md) 中，编程题参考答案为同目录下的 `.cpp` 文件。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
- [编程题](#编程题)
  - [有向图的广度优先遍历](#有向图的广度优先遍历)
  - [最小生成树](#最小生成树)
  - [列出连通集](#列出连通集)
- [主观题](#主观题)
  - [Problem 1](#problem-1-1)
  - [Problem 2](#problem-2)
  - [Problem 3](#problem-3)

<!-- /TOC -->

## 程序填空题

### Problem 1
有向网采用邻接表存储，本题目要求实现有向网的基本操作，请填空。
```c++
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ERROR 0
#define OK 1
typedef  int  Status;

 #define MAX_VERTEX_NUM 30 // 最大顶点个数
 enum GraphKind{DG,DN,AG,AN}; // {有向图,有向网,无向图,无向网}

 //图的邻接表存储表示
 typedef char VertexType[6];
 struct ArcNode
 {
   int adjvex; // 该弧所指向的顶点的位置
   ArcNode *nextarc; // 指向下一条弧的指针
   int info; // 网的权值
 }; // 表结点
 typedef struct
 {
   VertexType data; // 顶点信息
   ArcNode *firstarc; // 第一个表结点的地址,指向第一条依附该顶点的弧的指针
 }VNode,AdjList[MAX_VERTEX_NUM]; // 头结点
 struct ALGraph
 {
   AdjList vertices;
   int vexnum,arcnum; // 图的当前顶点数和弧数
   int kind; // 图的种类标志
 };

 int LocateVex(ALGraph G,VertexType u)
 { // 初始条件: 图G存在,u和G中顶点有相同特征
   // 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1
   int i;
   for(i=0;i<G.vexnum;++i)
     if(____1____)
       return i;
   return -1;
 }

 Status CreateGraph(ALGraph &G)
 { //采用头插法,构造有向网
   int i,j,k;
   int w; // 权值
   VertexType va,vb;
   ArcNode *p;
   G.kind=DN;
   printf("请输入图的顶点数,弧数: ");
   scanf("%d,%d",____2____);
   printf("\n请输入%d个顶点的值:\n",G.vexnum);
   for(i=0;i<G.vexnum;++i) // 构造顶点向量
   {
     scanf("%s",G.vertices[i].data);
     G.vertices[i].firstarc=____3____;
   }
   printf("请依次输入每条弧弧尾和弧头、权值(以空格作为间隔):\n");
   for(k=0;k<G.arcnum;++k) // 构造表结点链表
   {
     scanf("%s%s%d",va,vb,&w);
     i=____4____; // 弧尾
     j=____5____; // 弧头
     p=(ArcNode*)malloc(sizeof(ArcNode));
     p->adjvex=____6____;
     p->info=____7____;
     p->nextarc=____8____; // 插在表头
     G.vertices[i].firstarc=____9____;
   }
   return OK;
 }

 void DestroyGraph(ALGraph &G)
 { // 初始条件: 图G存在。操作结果: 销毁图G
   int i;
   ArcNode *p,*q;
   for(i=0;i<G.vexnum;++i)
   {
     p=____10____;
     while(p)
     {
       q=____11____;
       free(p);
       p=q;
     }
   }
     G.vexnum=0;
   G.arcnum=0;
 }

  Status PutVex(ALGraph &G,VertexType v,VertexType value)
 { // 初始条件: 图G存在,v是G中某个顶点
   // 操作结果: 对v赋新值value
   int i;
   i=____12____;
   if(i>-1) // v是G的顶点
   {
     ____13____;
     return OK;
   }
   return ERROR;
 }

 int FirstAdjVex(ALGraph G,VertexType v)
 { // 初始条件: 图G存在,v是G中某个顶点
   // 操作结果: 返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点,则返回-1
   ArcNode *p;
   int v1;
   v1=____14____; // v1为顶点v在图G中的序号
   p=____15____;
   if(p)
     return ____16____;
   else
     return -1;
 }

 int NextAdjVex(ALGraph G,VertexType v,VertexType w)
 { // 初始条件: 图G存在,v是G中某个顶点,w是v的邻接顶点
   // 操作结果: 返回v的(相对于w的)下一个邻接顶点的序号。
   //           若w是v的最后一个邻接点,则返回-1
   ArcNode *p;
   int v1,w1;
   v1=____17____; // v1为顶点v在图G中的序号
   w1=____18____; // w1为顶点w在图G中的序号
   p=G.vertices[v1].firstarc;
   while(____19____) // 指针p不空且所指表结点不是w
     p=p->nextarc;
   if(!p||!p->nextarc) // 没找到w或w是最后一个邻接点
     return -1;
   else
     return ____20____; // 返回v的(相对于w的)下一个邻接顶点的序号
 }

 void InsertVex(ALGraph &G,VertexType v)
 { // 初始条件: 图G存在,v和图中顶点有相同特征
   // 操作结果: 在图G中增添新顶点v(不增添与顶点相关的弧,留待InsertArc()去做)
   strcpy(G.vertices[G.vexnum].data,v); // 构造新顶点向量
   ____21____;
   ____22____; // 图G的顶点数加1
 }

 Status DeleteVex(ALGraph &G,VertexType v)
 { // 初始条件: 图G存在,v是G中某个顶点
   // 操作结果: 删除G中顶点v及其相关的弧
   int i,j;
   ArcNode *p,*q;
   j=____23____; // j是顶点v的序号
   if(j<0) // v不是图G的顶点
     return ERROR;
   p=____24____; // 删除以v为出度的弧
   while(p)
   {
     ____25____;
     p=p->nextarc;
     free(q);
     ____26____; // 弧或边数减1
   }
   ____27____; // 顶点数减1
   for(____28____;i<G.vexnum;i++) // 顶点v后面的顶点前移
     G.vertices[i]=G.vertices[i+1];
   for(i=0;i<G.vexnum;i++) // 删除以v为入度的弧且必要时修改表结点的顶点位置值
   {
     p=G.vertices[i].firstarc; // 指向第1条弧
     while(p) // 有弧
     {
       if(p->adjvex==j)
       {
         if(p==G.vertices[i].firstarc) // 待删结点是第1个结点
         {
           ____29____;
           free(p);
           p=____30____;
           G.arcnum--; // 弧数减1
         }
         else
         {
          ____31____;
           free(p);
           p=____32____;
           G.arcnum--; // 弧减1
         }
       }
       else
       {
         if(____33____)
           p->adjvex--; // 修改表结点的顶点位置值(序号)
         q=p;
         p=p->nextarc;
       }
     }
   }
   return OK;
 }

 Status InsertArc(ALGraph &G,VertexType v,VertexType w)
 { // 初始条件: 图G存在,v和w是G中两个顶点
   // 操作结果: 在G中增添弧<v,w>
   ArcNode *p;
   int w1,i,j;
   i=____34____; // 弧尾的序号
   j=____35____; // 弧头的序号
   if(i<0||j<0)
     return ERROR;
   G.arcnum++; // 图G的弧或边的数目加1
   printf("\n请输入弧%s→%s的权值: ",v,w);
   scanf("%d",&w1);
   p=(ArcNode*)malloc(sizeof(ArcNode));
   p->adjvex=____36____;
   p->info=____37____;
   p->nextarc=____38____; // 插在表头
   G.vertices[i].firstarc=____39____;
   return OK;
 }

 Status DeleteArc(ALGraph &G,VertexType v,VertexType w)
 { // 初始条件: 图G存在,v和w是G中两个顶点
   // 操作结果: 在G中删除弧<v,w>
   ArcNode *p,*q;
   int i,j;
   i=____40____; // i是顶点v(弧尾)的序号
   j=____41____; // j是顶点w(弧头)的序号
   if(i<0||j<0||i==j)
     return ERROR;
   p=G.vertices[i].firstarc; // p指向顶点v的第一条出弧
   while(____42____) // p不空且所指之弧不是待删除弧<v,w>
   { // p指向下一条弧
     q=p;
     p=p->nextarc;
   }
   if(____43____) // 找到弧<v,w>
   {
     if(p==G.vertices[i].firstarc) // p所指是第1条弧
       ____44____; // 指向下一条弧
     else
       ____45____; // 指向下一条弧
     free(p); // 释放此结点
     G.arcnum--; // 弧或边数减1
   }
   return OK;
 }

void Display(ALGraph G)
 { // 输出图的邻接矩阵G
   int i;
   ArcNode *p;
   printf("%d个顶点：\n",G.vexnum);
   for(i=0;i<G.vexnum;++i)
     printf("%s ",G.vertices[i].data);
   printf("\n%d条弧:\n",G.arcnum);
   for(i=0;i<G.vexnum;i++)
   {
     p=G.vertices[i].firstarc;
     while(p)
     {
        printf("%s→%s ",G.vertices[i].data,G.vertices[p->adjvex].data);
        printf(":%d ",p->info);
        p=p->nextarc;
        printf("\n");
     }
   }
 }

int main()
 {
   int i,j,k,n;
   ALGraph g;
   VertexType v1,v2;
   CreateGraph(g);
   Display(g);
   printf("删除一条弧，请输入待删除弧的弧尾 弧头：");
   scanf(" %s%s",v1,v2);
   DeleteArc(g,v1,v2);
   printf("\n修改顶点的值，请输入原值 新值: ");
   scanf(" %s%s",v1,v2);
   PutVex(g,v1,v2);
   printf("\n插入新顶点，请输入顶点的值: ");
   scanf("%s",v1);
   InsertVex(g,v1);
   printf("\n插入与新顶点有关的弧，请输入弧数: ");
   scanf("%d",&n);
   for(k=0;k<n;k++)
   {
     printf("\n请输入另一顶点的值: ");
     scanf("%s",v2);
     InsertArc(g,v2,v1);
   }
   printf("\n");
   Display(g);
   printf("删除顶点及相关的弧，请输入顶点的值: ");
   scanf("%s",v1);
   DeleteVex(g,v1);
   printf("\n");
   Display(g);
   DestroyGraph(g);
   return 0;
 }
```
输入输出示例:
```
请输入图的顶点数,弧数: 9,11
请输入9个顶点的值:
v1
v2
v3
v4
v5
v6
v7
v8
v9
请依次输入每条弧弧尾和弧头、权值(以空格作为间隔):
v1 v2 6
v1 v3 4
v1 v4 5
v2 v5 1
v3 v5 1
v4 v6 2
v5 v7 9
v5 v8 7
v6 v8 4
v7 v9 2
v8 v9 4
9个顶点：
v1 v2 v3 v4 v5 v6 v7 v8 v9
11条弧:
v1→v4 :5
v1→v3 :4
v1→v2 :6
v2→v5 :1
v3→v5 :1
v4→v6 :2
v5→v8 :7
v5→v7 :9
v6→v8 :4
v7→v9 :2
v8→v9 :4
删除一条边或弧，请输入待删除边或弧的弧尾 弧头：v5 v8
修改顶点的值，请输入原值 新值: v1 v0
插入新顶点，请输入顶点的值: v11
插入与新顶点有关的弧，请输入弧数: 3
请输入另一顶点的值: v5
请输入弧v5→v11的权值: 6
请输入另一顶点的值: v6
请输入弧v6→v11的权值: 3
请输入另一顶点的值: v7
请输入弧v7→v11的权值: 2
10个顶点：
v0 v2 v3 v4 v5 v6 v7 v8 v9 v11
13条弧:
v0→v4 :5
v0→v3 :4
v0→v2 :6
v2→v5 :1
v3→v5 :1
v4→v6 :2
v5→v11 :6
v5→v7 :9
v6→v11 :3
v6→v8 :4
v7→v11 :2
v7→v9 :2
v8→v9 :4
删除顶点及相关的弧，请输入顶点的值: v6
9个顶点：
v0 v2 v3 v4 v5 v7 v8 v9 v11
10条弧:
v0→v4 :5
v0→v3 :4
v0→v2 :6
v2→v5 :1
v3→v5 :1
v5→v11 :6
v5→v7 :9
v7→v11 :2
v7→v9 :2
v8→v9 :4
```

## 编程题

### 有向图的广度优先遍历
有向图采用邻接表结构，请根据输入建立链接表，输出广度优先遍历序列。顶点个数不超过30.

输入格式:  
输入共3部分，分别是图中顶点的个数、弧的条数和每一条弧。

输出格式:  
用 `%s ` 输出遍历序列（包含一个空格）中的顶点。

输入样例:
```
4 7
v1
v2
v3
v4
v1 v2
v1 v3
v3 v1
v3 v4
v4 v1
v4 v2
v4 v3
```
输出样例:
```
v1 v3 v2 v4 
```

### 最小生成树
用Prim算法从最后一个顶点出发计算无向图的最小生成树。无向图采用邻接矩阵方式存储，999表示无穷大。

输入格式:  
输入共3部分：图中顶点的个数、顶点信息和邻接矩阵。

输出格式:  
输出最小生成树中的边序列（用 `%s %s\n` 格式）

输入样例:
```
6
v1
v2
v3
v4
v5
v6
999 6 1 5 999 999
6 999 5 999 3 999
1 5 999 5 6 4
5 999 5 999 999 2
999 3 6 999 999 6
999 999 4 2 6 999
```
输出样例:
```
v6 v4
v6 v3
v3 v1
v3 v2
v2 v5
```

### 列出连通集
给定一个有 `N` 个顶点和 `E` 条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从 `0` 到 `N−1` 编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:
输入第1行给出2个整数 `N(0<N≤10)` 和 `E` ，分别是图的顶点数和边数。随后 `E` 行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

输出格式:
按照 {v<sub>1</sub> v<sub>2</sub> ... v<sub>k</sub>} 的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

输入样例:
```
8 6
0 7
0 1
2 0
4 1
2 4
3 5
```
输出样例:
```
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
```

## 主观题

### Problem 1
画出对长度为 `12` 的有序表进行折半查找的判定树，并求其等概率时查找成功的平均查找长度。

### Problem 2
已知如下所示长度为 `12` 的表 `(Dec, Nov, Oct, Sep, Aug, July, June, May, Apr, Mar, Feb, Jan)`

(1) 试按表中元素的顺序依次插入一棵初始为空的二叉排序树，画出插入完成之后的二叉排序树，并求其在等概率的情况下查找成功的平均查找长度。

(2) 按表中元素顺序构造一棵平衡二叉排序树，并求其在等概率情况下查成功时的平均查找长度。

### Problem 3
含 `12` 个结点的平衡二叉树的最大深度是多少？并画出一棵这样的树。