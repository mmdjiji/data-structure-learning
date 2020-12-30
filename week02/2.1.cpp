#include <stdio.h>
#include <stdlib.h>

typedef  int ElemType;
#define LIST_INIT_SIZE    30  //���Ա�洢�ռ�ĳ�ʼ����
#define LISTINCREMENT     10  //���Ա�洢�ռ�ķ�������
typedef   struct {
	ElemType   *elem;    //�洢�ռ��ַ
	int        length;   //��ǰ����
	int        listsize; //��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
} SqList;

/* ��ĳ���Ƕ������ */
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
	int m,n;   //�ֱ����������ϳ�ʼ����
	ElemType e;
	SqList La,Lb,Lc;
	scanf("%d%d",&m,&n);
	InitList_Sq(La);
	InitList_Sq(Lb);  //���������ռ�

	for(i=1; i<=m; i++) { //������һ������
		scanf("%d",&e);
		ListInsert_Sq(La,i,e);
	}
	for(i=1; i<=n; i++) { //�����ڶ�������
		scanf("%d",&e);
		ListInsert_Sq(Lb,i,e);
	}

	union_Sq(La,Lb,Lc);  //���㼯��La��Lb�Ľ���Lc
	len=ListLength_Sq(Lc);
	for(i=1; i<=len; i++) { //���
		GetElem_Sq(Lc,i,e);
		printf("%4d",e);
	}
	return 0;
}
