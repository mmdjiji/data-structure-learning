#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define  OK  1
#define  ERROR  -1
#define  OVERFLOW -2
typedef int Status;

typedef struct
{ //项的表示,多项式的项作为LinkList的数据元素
  int    coef;                               // 系数COEFFICIENT
  int    expn;                               // 指数EXPONENT
}term, ElemType;  

typedef struct LNode	                         //结点类型
{ ElemType        data;	
 struct LNode    *next;
} *Link, *Position;
typedef  struct                                   //链表类型
{Link  head, tail;    //分别指向线性链表中的头结点和最后一个结点
 int   len;                       //指向线性链表中数据元素的个数
}LinkList;
typedef  LinkList  polynomial;   //用带表头结点的有序链表表示多项式

/* 请在这里填写答案 */
Status CreatePolyn(polynomial &src, int n) {
    src.head = NULL;
    for(int i=0; i<n; i++){
        Link in = new LNode;
        scanf("%d %d", &in->data.coef, &in->data.expn);
        in->next = src.head;
        src.head = in;
    }
    src.len = n;
    Link temp = new LNode;
    temp->data.coef = 0, temp->data.expn = -1;
    temp->next = src.head;
    src.head = temp;
    return OK;
}
Position GetHead(polynomial src){
    return src.head;
}
Position NextPos(polynomial src, Position current) {
    return current->next;
}
Status InsertElem(polynomial &src, ElemType insert){
	LNode *p = src.head;
	while(p->next){
		if(p->next->data.expn > insert.expn) break;
		p = p->next;
	}
	LNode *temp = new LNode;
	temp->data = insert;
	temp->next = p->next;
	p->next = temp;
	src.len++;
	return OK;
}
Status AddPolyn(polynomial &Pa, polynomial &Pb) {
	polynomial result;
	result.head = new LNode;
	result.tail = result.head;
	result.head->next = NULL;
	result.len = 0;
    LNode *outer = Pa.head;
    while(outer && outer->next){
    	LNode *inner = Pb.head;
    	bool flag = true;
    	while(inner && inner->next){
    		if(outer->next->data.expn == inner->next->data.expn){
    			ElemType temp;
    			temp.coef = outer->next->data.coef + inner->next->data.coef;
    			temp.expn = outer->next->data.expn;
				inner->next->data.coef = 0;
				flag = false;
    			if(temp.coef != 0){
    				InsertElem(result, temp);
    				break;
				}
			}
    		inner = inner->next;
		}
		if(flag && outer->next->data.coef != 0)
			InsertElem(result, outer->next->data);
    	outer = outer->next;
	}
	LNode *inner = Pb.head;
	while(inner && inner->next){
		if(inner->next->data.coef != 0)
			InsertElem(result, inner->next->data);
		inner = inner->next;
	}
    Pa = result;
}

int main()
{  polynomial  Pa,Pb;
   int m,n;
   Position ha,hb,qa,qb;
   term a;
   scanf("%d",&m);
   CreatePolyn(Pa, m);
   scanf("%d",&n);
   CreatePolyn(Pb, n);
   AddPolyn (Pa, Pb);
   if(Pa.len==0) { printf("0\n"); return 0;}
   ha=GetHead(Pa);       //ha和hb分别指向Pa和Pb的头结点
   qa=NextPos(Pa,ha);
   while(qa)
   { printf("%d,%d\n",qa->data.coef,qa->data.expn);
     ha=qa;
     qa = NextPos(Pa,ha);  
   }
    return 0;
}
