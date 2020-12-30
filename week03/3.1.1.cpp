#include <stdio.h>
#include <stdlib.h>

typedef  char ElemType;
typedef  struct  LNode {
	ElemType       data;
	struct  LNode  *next;
} LNode, *LinkList;

/* 你的程序将嵌在这里 */
typedef int Status;
#define TRUE (1)
#define FALSE (0)
#define OK (1)
#define ERROR (-1)
#define OVERFLOW (-2)
Status InitList(LinkList &L) {
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	if(L != NULL)
		return OK;
	else
		return ERROR;
}
Status ListInsert(LinkList &L, int i, ElemType e) {
	LNode *temp = L, *newL = (LNode *)malloc(sizeof(LNode));
	newL->data = e;
	for(int j=0; j<i-1; j++) {
		if(temp->next != NULL) {
			temp = temp->next;
		}else{
			return ERROR;
		}
	}
	newL->next = temp->next;
	temp->next = newL;
	return OK;
}
int ListLength(LinkList &L) {
	LinkList temp = L;
	int retval=0;
	while(temp->next != NULL) {
		retval++;
		temp = temp->next;
	}
	return retval;
}
Status GetElem(LinkList &L, int i, ElemType &e) {
	LinkList temp = L;
	for(int j=0; j<i; j++) {
		if(temp->next != NULL) {
			temp = temp->next;
		}else{
			return ERROR;
		}
	}
	e = temp->data;
	return OK;
}
Status DestroyList(LinkList &L) {
	LinkList temp = L;
	LNode *todel;
	while(temp->next != NULL) {
		todel = temp;
		temp = temp->next;
		free(todel);
	}
	return OK;
}
Status jiaoji(LinkList &La, LinkList &Lb, LinkList &Lc) {
	if(!InitList(Lc)) return ERROR;
	LinkList outer = Lb, temp = Lc;
	while(outer->next != NULL){
		outer = outer->next;
		LinkList inner = La;
		while(inner->next != NULL){
			inner = inner->next;
			if(outer->data == inner->data){
				LNode *newL = (LNode *)malloc(sizeof(LNode));
				newL->data = outer->data;
				temp->next = newL;
				temp = temp->next;
			}
		}
	} 
	temp->next = NULL;
	return OK;
}

int main() {
	int i,j,len;
	ElemType e;
	LinkList La,Lb,Lc;
	int m,n;        //分别存放两个集合初始长度
	scanf("%d%d",&m,&n);
	getchar();
	InitList(La);
	InitList(Lb);           //建立两个空集
	for(i=1; i<=m; i++) {        //建立第一个集合
		scanf("%c",&e);
		ListInsert(La,i,e);
	}
	getchar();
	for(i=1; i<=n; i++) {         //建立第二个集合
		scanf("%c",&e);
		ListInsert(Lb,i,e);
	}
	jiaoji(La,Lb,Lc);             //计算集合La、Lb的交集Lc
	//输出结果
	len=ListLength(Lc);
	for(i=1; i<=len; i++) {
		GetElem(Lc,i,e);
		printf("%c",e);
	}
	//printf("\n");
	DestroyList(La);
	DestroyList(Lb);
	DestroyList(Lc);      //销毁3个集合
	return 0;
}
