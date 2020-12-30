#include <stdio.h>
#include <stdlib.h>

typedef  int ElemType;
#define LIST_INIT_SIZE    30  //线性表存储空间的初始分配
#define LISTINCREMENT     10  //线性表存储空间的分配增量
typedef   struct {
	ElemType   *elem;    //存储空间基址
	int        length;   //当前长度
	int        listsize; //当前分配的存储容量(以sizeof(ElemType)为单位)
} SqList;

/* 你的程序将嵌在这里 */
#define OK (1)
#define ERROR (-1)
#define OVERFLOW (-2)
typedef int Status;
Status InitList_Sq(SqList &L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem)return ERROR;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
int ListLength_Sq(SqList L) {
	return L.length;
}
Status GetElem_Sq(SqList L, int i, ElemType &e) {
	if(i<1 || i>L.length+1) return ERROR;
	e = L.elem[i-1];
	return OK;
}
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	ElemType *p, *q;
	if (i<1||i>L.length+1) return ERROR;
	if (L.length>=L.listsize) {
		ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize+LISTINCREMENT) * sizeof(ElemType));
		if(!newbase) return OVERFLOW;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = &L.elem[i-1];
	if(L.length>=1)
		for(p=&L.elem[L.length]; p>=q; --p)
			*p = *(p-1);
	*q=e;
	L.length++;
	return OK;
}
Status equal(ElemType x, ElemType  y) {
	return x == y;
}
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType,ElemType)) {
	int i;
	ElemType *p;
	i = 1;
	p = L.elem;
	while(i<=L.length && !(*compare)(*p++,e)) ++i;
	if (i<=L.length) return i;
	else return 0;
}
void union_Sq(SqList La, SqList Lb, SqList &Lc) {
	Lc = La;
	for(int i=0; i<Lb.length; i++)
		if(LocateElem_Sq(Lc, Lb.elem[i], equal) == 0)
			ListInsert_Sq(Lc, Lc.length+1, Lb.elem[i]);
}

int main() {
	int i,j,len;
	int m,n;   //分别存放两个集合初始长度
	ElemType e;
	SqList La,Lb,Lc;
	scanf("%d%d",&m,&n);
	InitList_Sq(La);
	InitList_Sq(Lb);  //建立两个空集

	for(i=1; i<=m; i++) { //建立第一个集合
		scanf("%d",&e);
		ListInsert_Sq(La,i,e);
	}
	for(i=1; i<=n; i++) { //建立第二个集合
		scanf("%d",&e);
		ListInsert_Sq(Lb,i,e);
	}

	union_Sq(La,Lb,Lc);  //计算集合La、Lb的交集Lc
	len=ListLength_Sq(Lc);
	for(i=1; i<=len; i++) { //输出
		GetElem_Sq(Lc,i,e);
		printf("%4d",e);
	}
	return 0;
}
