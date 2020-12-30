# week13

程序填空题及主观题参考答案在 [ANSWERS.md](ANSWERS.md) 中。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
  - [Problem 2](#problem-2)
  - [Problem 3](#problem-3)
- [主观题](#主观题)
  - [Problem 1](#problem-1-1)
  - [Problem 2](#problem-2-1)
  - [Problem 3](#problem-3-1)
  - [Problem 4](#problem-4)

<!-- /TOC -->

## 程序填空题

### Problem 1
本题目要求实现直接插入排序算法,请填空。
```c++
void InsertSort(SqList &L)
{ // 对顺序表L作直接插入排序
  int i,j;
  for(i=____1____;i<=L.length;++i)
    if LT(L.r[i].key,L.r[i-1].key) // "<",需将L.r[i]插入有序子表
    {
      L.r[0]=____2____; // 复制为哨兵
      for(j=i-1;LT(L.r[0].key,L.r[j].key);--j)
      ____3____ ; // 记录后移
    ____4____ ; // 插入到正确位置
    }
}
```

### Problem 2
本题目要求实现希尔排序算法,请填空。

输入格式:  
输入首先给出一个正整数 `N (≤500)` 表示待排序数据个数；接下来一行给出 `N` 个整数。整数间以空格分隔。

输出格式:  
在一行内按非递减顺序输出 `N` 个整数，整数间以空格分隔，但结尾不得有多余空格。

输入样例:
```
10
5 24 6 9 12 3 16 2 5 3
3 5 3 1
```
输出样例:
```
第1趟排序结果:
3 16 2 5 3 5 24 6 9 12
第2趟排序结果:
3 3 2 5 6 5 12 16 9 24
第3趟排序结果:
2 3 3 5 5 6 9 12 16 24
```
```c++
void ShellInsert(SqList &L,int dk)
{ // 对顺序表L作一趟希尔插入排序。
  int i,j;
  for(i=____1____;i<=L.length;++i)
    if LT(L.r[i].key,____2____)
    { // 需将L.r[i]插入有序增量子表
      L.r[0]=____3____; // 暂存在L.r[0]
      for(j= ____4____ ;j>0&&LT(L.r[0].key,L.r[j].key); ____5____ )
      ____6____ ; // 记录后移，查找插入位置
      ____7____ =L.r[0]; // 插入
    }
}
void ShellSort(SqList &L,int dlta[],int t)
{ // 按增量序列dlta[0..t-1]对顺序表L作希尔排序。算法10.5
  int k;
  for(k=0;k<t;++k)
  {
    ShellInsert(L,dlta[k]); // 一趟增量为dlta[k]的插入排序
    printf("第%d趟排序结果:\n",k+1);
    print(L);
  }
}
```

### Problem 3
本题目要求实现快速排序算法,请填空。
```c++
int Partition(SqList &L,int low,int high)
{ // 交换顺序表L中子表r[low..high]的记录，枢轴记录到位，并返回其
  // 所在位置，此时在它之前（后）的记录均不大（小）于它。算法10.6(b)
  KeyType pivotkey;
  L.r[0]= ____1____ ; 
  pivotkey=____2____ ; 
  while(low< high)
  { // 从表的两端交替地向中间扫描
    while( ____3____ )
      --high;
    L.r[low]=L.r[high]; 
    while( ____4____ )
      ++low;
    L.r[high]=L.r[low]; 
  }
  ____5____ ; 
  return  ____6____ ;
}

void QSort(SqList &L,int low,int high)
{ // 对顺序表L中的子序列L.r[low..high]作快速排序。算法10.7
  int pivotloc;
  if(low<high)
  { // 长度大于1
    pivotloc=Partition(L,low,high); // 将L.r[low..high]一分为二
    QSort( ____7____ ); // 对低子表递归排序，pivotloc是枢轴位置
    QSort( ____8____ ); // 对高子表递归排序
  }
}

void QuickSort(SqList &L)
{ // 对顺序表L作快速排序。算法10.8
  QSort(L,1,L.length);
}
```

## 主观题

### Problem 1
对关键字序列 `(503, 087, 512, 061, 908, 170, 897, 275, 653, 426)` 写出每一趟堆排序结束时的排序结果。

### Problem 2
对关键字序列 `(503, 087, 512, 061, 908, 170, 897, 275, 653, 426)` 写出每一趟堆归并序结束时的排序结果。

### Problem 3
对关键字序列 `(503, 087, 512, 061, 908, 170, 897, 275, 653, 426)` 写出每一趟基数排序结束时的排序结果。

### Problem 4
以下函数的输出结果是什么？
```c++
void demonstrate(){
  StrAssign(s, "THIS IS A BOOK");
  Replace(s, Substring(s, 3, 7), "ESE ARE");
  StrAssign(t, Concat(s, "S"));
  StrAssign(u, "XYXYXYXYXYXY");
  StrAssign(v, Substring(u, 6, 3));
  StrAssign(w, "W");
  Replace(u, v, w);
  printf("t=%s,v=%s,u=%s",t,v,u); // 注: 原题不规范，有改动
}
```