# week15

程序填空题参考答案在 [ANSWERS.md](ANSWERS.md) 中，编程题参考答案为同目录下的 `.cpp` 文件。

<!-- TOC -->

- [程序填空题](#程序填空题)
  - [Problem 1](#problem-1)
- [编程题](#编程题)
  - [串的查找](#串的查找)
  - [模式匹配1](#模式匹配1)
  - [模式匹配2](#模式匹配2)

<!-- /TOC -->

## 程序填空题

### Problem 1
假设串采用堆分配存储表示，本题目要求实现串的基本操作。
```c++
// 串的堆分配存储
struct HString
{
  char *ch;         // 若是非空串,则按串长分配存储区,否则ch为NULL
  int length;      // 串长度
};
void InitString(HString &T)
{ // 初始化(产生空串)字符串T。另加
  T.length=0;
  T.ch=NULL;
}
Status StrAssign(HString &T,char *chars)
{ // 生成一个其值等于串常量chars的串T
  int i,j;
  if(T.ch)  
    free(T.ch); // 释放T原有空间
  i=strlen(chars); // 求chars的长度i
  if(!i)
  { // chars的长度为0
    T.ch=NULL;
    T.length=0;
  }
  else
  { 
    T.ch=____1____; // 分配串空间
    if(!T.ch) // 分配串空间失败
      exit(OVERFLOW);
    for(j=0;j<i;j++) // 拷贝串
      ____2____;
    T.length=____3____;
  }
  return OK;
}

Status StrCopy(HString &T,HString S)
{ // 初始条件: 串S存在。操作结果: 由串S复制得串T
  int i;
  if(T.ch)
    free(T.ch); // 释放T原有空间
  T.ch=____4____; // 分配串空间
  if(!T.ch) // 分配串空间失败
    exit(OVERFLOW);
  for(i=0;i<S.length;i++) // 拷贝串
    ____5____;
  T.length=____6____;
  return OK;
}

Status StrEmpty(HString S)
{ //若S为空串,则返回TRUE,否则返回FALSE
  if(____7____)
    return TRUE;
  else
    return FALSE;
}

int StrCompare(HString S,HString T)
{ // 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
  int i;
  for(i=0;____8____;++i)
    if(S.ch[i]!=T.ch[i])
      return ____9____ ;
  return S.length-T.length;
}

Status Concat(HString &T,HString S1,HString S2)
{ // 用T返回由S1和S2联接而成的新串
  int i;
  if(T.ch)
    free(T.ch); // 释放旧空间
  T.length=S1.length+S2.length;
  T.ch=____10____;
  if(!T.ch)
    exit(OVERFLOW);
  for(i=0;i<____11____;i++)
  ____12____
  for(i=0;i<S2.length;i++)
  ____13____;
  return OK;
}

Status SubString(HString &Sub, HString S,int pos,int len)
{ // 用Sub返回串S的第pos个字符起长度为len的子串。
  // 其中,1≤pos≤StrLength(S)且0≤len≤StrLength(S)-pos+1
  int i;
  if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
    return ERROR;
  if(Sub.ch)
    free(Sub.ch); // 释放旧空间
  if(!len) // 空子串
  {
    Sub.ch=NULL;     Sub.length=0;
  }
  else
  { 
    Sub.ch=____14____ ;
    if(!Sub.ch)
      exit(OVERFLOW);
    for(i=0;i<=len-1;i++)
      ____15____;
    Sub.length=____16____;
  }
  return OK;
}

int Index(HString S,HString T,int pos) // 算法4.1
{ // T为非空串。若主串S中第pos个字符之后存在与T相等的子串,
  // 则返回第一个这样的子串在S中的位置,否则返回0
  int n,m,i;
  HString sub;
  InitString(sub);
  if(pos>0)
  {
    n=StrLength(S);
    m=StrLength(T);
    i=pos;
    while(i<=____17____)
    {
    ____18____;
      if(____19____)
    ++i;
      else
        return i;
    }
  }
  return 0;
}

Status StrInsert(HString &S,int pos,HString T) // 算法4.4
{ // 1≤pos≤StrLength(S)+1。在串S的第pos个字符之前插入串T
  int i;
  if(pos<1||pos>S.length+1) // pos不合法
    return ERROR;
  if(T.length) // T非空,则重新分配空间,插入T
  {
    S.ch=____20____;
    if(!S.ch)
      exit(OVERFLOW);
    for(i=S.length-1;____21____;--i) // 为插入T而腾出位置
      ____22____=S.ch[i];
    for(i=0;i<T.length;i++)
      ____23____; // 插入T
    S.length+=T.length;
  }
  return OK;
}

Status StrDelete(HString &S,int pos,int len)
{ // 从串S中删除第pos个字符起长度为len的子串
  int i;
  if(S.length<pos+len-1)
    exit(ERROR);
  for(i=pos-1;____24____;i++)
S.ch[i]=____25____;
S.length=____26____;
S.ch=(char*)realloc(S.ch,S.length*sizeof(char));
  return OK;
}

Status Replace(HString &S,HString T,HString V)
{ // 初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关）
  // 操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串
  int i=1; // 从串S的第一个字符起查找串T
  if(StrEmpty(T)) // T是空串
    return ERROR;
  do
  {
    i=____27____; 
    if(i) 
    {
      StrDelete(S,i,StrLength(T)); // 删除该串T
      ____28____; // 在原串T的位置插入串V
      i+=____29____; // 在插入的串V后面继续查找串T
    }
  }while(i);
  return OK;
}
```

## 编程题

### 串的查找
利用串的最基本操作实现: 输入两个字符串 `s1` 和 `s2` ，输出 `s1` 在 `s2` 中所有不重叠的位置。假设串长不超过 `80` 。

输入格式:  
输入共2行，分别给出两个字符串 `s1` 和 `s2`

输出格式:  
输出若干个整数，每个整数输出格式为 `%3d`

输入样例:
```
aaaa
aaaaaaaaaaaaaa
```
输出样例:
```
  1  5  9
```

### 模式匹配1
利用未改进的KMP算法，在输出 `s1` 在 `s2` 中第一次出现的位置。假设串长不超过80。输入数据是两个字符串，输出数据是 `s1` 的 `NEXT` 数组的值和 `s1` 在 `s2` 中第一次出现的位置。找不到输出 `0` 。

输入格式:  
输入共2行,分别是 `s1` 和 `s2` 。

输出格式:  
输出也是两行，第一行输出 `NEXT` 数组的值，第二行是一个表示位置的整数。输出格式为 `%3d` 。

输入样例:
```
abacab
abacaabaccabacabaa
```
输出样例:
```
  0  1  1  2  1  2
 11
```

### 模式匹配2
利用改进的KMP算法，输出 `s1` 在 `s2` 中第一次出现的位置。假设串长不超过 `80` 。输入数据是两个字符串，输出数据是 `s1` 的 `NEXTVAL` 数组的值和 `s1` 在 `s2` 中第一次出现的位置。找不到输出 `0` 。

输入格式:
输入共2行,分别是 `s1` 和 `s2` 。

输出格式:
输出也是两行，第一行输出 `NEXT` 数组的值，第二行是一个表示位置的整数。输出格式为 `%3d` 。

输入样例:
```
aaaaab
aaaabaaaaaaaaab
```
输出样例:
```
  0  0  0  0  0  5
 10
```