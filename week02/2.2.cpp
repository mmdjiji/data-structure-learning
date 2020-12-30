#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType[20];

/* 你的程序将嵌在这里 */
#define LIST_INIT_SIZE    30  //线性表存储空间的初始分配
#define LISTINCREMENT     10  //线性表存储空间的分配增量
typedef   struct {
	ElemType   *elem;    //存储空间基址
	int        length;   //当前长度
	int        listsize; //当前分配的存储容量(以sizeof(ElemType)为单位)
} SqList;
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
	strcpy(e, L.elem[i-1]);
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
			strcpy(*p, *(p-1));
	strcpy(*q, e);
	L.length++;
	return OK;
}
Status ListDelete_Sq(SqList &L, int i){
	ElemType *p, *q;
	if (i<1||i>L.length+1) return ERROR;
	p = &(L.elem[i-1]);
	q = L.elem + L.length - 1;
	for(p++; p<=q; p++)
		strcpy(*(p-1), *p);
	L.length--;
	return OK;
}
Status equal(ElemType x, ElemType  y) {
	return strcmp(x, y) == 0;
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
void chaji_Sq(SqList La, SqList Lb, SqList &Lc) {
	int todo;
	Lc = La;
	for(int i=1; i<=Lb.length; i++)
		if((todo = LocateElem_Sq(Lc, Lb.elem[i-1], equal)) != 0)
			ListDelete_Sq(Lc, todo);
}
Status DestroyList_Sq(SqList &L) {
	if (L.elem) return ERROR;
	free(L.elem);
	L.length = 0;
	L.listsize = 0;
	return OK;
}

int main() {
	int i,j,len;
	ElemType e;
	SqList La,Lb,Lc;
	int m,n;   //分别存放两个集合初始长度
	printf("input the length of two set:\n");
	scanf("%d%d",&m,&n);
	InitList_Sq(La);
	InitList_Sq(Lb);   //建立两个空集
	printf("input the first set:\n ");
	for(i=0; i<m; i++) { //建立第一个集合
		scanf(" %s",e);     //注意有空格
		ListInsert_Sq(La,i+1,e);
	}
	printf("input the second set:\n ");
	for(i=1; i<=n; i++) { //建立第二个集合
		scanf(" %s",e);      //注意有空格
		ListInsert_Sq(Lb,i,e);
	}
	chaji_Sq(La,Lb,Lc);  //计算集合La、Lb的差集Lc
	printf("the chaji set is:\n");
	len=ListLength_Sq(Lc);
	for(i=1; i<=len; i++) {
		GetElem_Sq(Lc,i,e);
		printf("%s\n",e);
	}
	DestroyList_Sq(La);
	DestroyList_Sq(Lb);
	DestroyList_Sq(Lc); //销毁3个集合（顺序表）
	return 0;
}
