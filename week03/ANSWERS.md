# week3 - 程序填空题和主观题参考答案

## 程序填空题
1. 1. `struct LNode *`
   2. `(LinkList)malloc(sizeof(LNode))`
   3. `NULL`
   4. `p = p->next; ++j;`
   5. `p->next`
   6. `p->next = s`
   7. `L->next`
   8. `p && !compare(p->data, e)`
   9. `return i`
   10. `return ERROR`
   11. `p = L->next`
   12. `j = 1`
   13. `j++; p = p->next;`
   14. `p->data`
   15. `L->next == NULL`
   16. `L->next`
   17. `len++; p = p->next;`
   18. `p->next && j<i-1`
   19. `p->next`
   20. `p->next = q->next`
   21. `q->data`
2. 1. `La->next`
   2. `Lb->next`
   3. `pa && pb`
   4. `pc->next = pa; pc = pa; pa = pa->next;`
   5. `pc->next = pb; pc = pb; pb = pb->next;`
   6. `pa?pa:pb`

## 主观题

### Problem 1
```c++
#include <iostream>
#include <cstdlib>

typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node *next;
} LNode, *LinkList;

LNode *create(ElemType src){
	LNode *retval = (LNode *)malloc(sizeof(LNode));
	retval->data = src;
	retval->next = NULL;
	return retval;
}

// delete src element in range of (mink, maxk)
bool delRange(LinkList src, ElemType mink, ElemType maxk){
	LNode *temp = src, *del;
	while(temp->next != NULL){
		if(temp->next->data > mink && temp->next->data < maxk){
			del = temp->next;
			temp->next = del->next;
			free(del);
		}else{
			temp = temp->next;
		}
	}
	return true;
}

bool dispList(LinkList src){
	LNode *temp = src;
	while(temp->next != NULL){
		temp = temp->next;
		std::cout<<temp->data<<" ";
	}
	std::cout<<std::endl;
	return true;
}

int main(){
	LinkList p = create(-1); // head node
	LNode *temp = p; // temporary pointer
	
	// generate some element for testing
	for(ElemType i=1; i<=100; i++){
		temp->next = create(i);
		temp = temp->next;
	}
	
	// demo for testing
	ElemType mink, maxk;
	std::cout<<"Guide: please input the range (mink, maxk) as format `mink maxk`:";
	std::cin>>mink>>maxk;
	std::cout<<"Before run delRange(p, mink, maxk):"<<std::endl; 
	dispList(p);
	delRange(p, mink, maxk);
	std::cout<<"After runned delRange(p, mink, maxk):"<<std::endl; 
	dispList(p);
	return 0;
}
```
### Problem 2
```c++
#include <iostream>
#include <cstdlib>

typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node *next;
} LNode, *LinkList;

LNode *create(ElemType src){
	LNode *retval = (LNode *)malloc(sizeof(LNode));
	retval->data = src;
	retval->next = NULL;
	return retval;
}

bool dispList(LinkList src){
	LNode *temp = src;
	while(temp->next != NULL){
		temp = temp->next;
		std::cout<<temp->data<<" ";
	}
	std::cout<<std::endl;
	return true;
}

bool reverse(LinkList &src){
	LNode *temp = src->next, *n3xt, *prev = NULL, *head = src;
	while(temp->next != NULL){
		n3xt = temp->next;
		temp->next = prev;
		prev = temp;
		temp = n3xt;
	}
	temp->next = prev;
	head->next = temp;
	src = head;
	return true;
}

int main(){
	LinkList p = create(-1); // head node
	LNode *temp = p; // temporary pointer
	
	// generate some element for testing
	for(ElemType i=1; i<=100; i++){
		temp->next = create(i);
		temp = temp->next;
	}
	
	// demo for testing
	std::cout<<"Before run reverse(p):"<<std::endl; 
	dispList(p);
	reverse(p);
	std::cout<<"After runned reverse(p):"<<std::endl; 
	dispList(p);
	return 0;
}
```
### Problem 3
```c++
#include <iostream>
#include <cstdlib>

typedef char ElemType;

typedef struct node {
	ElemType data;
	struct node *next;
} LNode, *LinkList;

LNode *create(ElemType src){
	LNode *retval = (LNode *)malloc(sizeof(LNode));
	retval->data = src;
	retval->next = NULL;
	return retval;
}

bool dispList(LinkList src){
	LNode *temp = src, *head = src;
	if(temp->data == -1) temp = temp->next;
	while(temp && temp->next != head){
		std::cout<<temp->data<<" ";
		temp = temp->next;
	}
	if(temp)
		std::cout<<temp->data<<" "; 
	std::cout<<std::endl;
	return true;
}

bool category(LinkList p, LinkList &L1, LinkList &L2, LinkList &L3){
	// L1: A-Za-z, L2: 0-9, L3: others
	LNode *temp = p->next;
	L1 = create(-1), L2 = create(-1), L3 = create(-1);
	LNode *l1 = L1, *l2 = L2, *l3 = L3;
	while(p){
		if((p->data >= 'A' && p->data <= 'Z') || (p->data >= 'a' && p->data <= 'z')){
			l1->next = create(p->data);
			l1 = l1->next;
		}else if(p->data >= '0' && p->data <= '9'){
			l2->next = create(p->data);
			l2 = l2->next;
		}else{
			l3->next = create(p->data);
			l3 = l3->next;
		}
		p = p->next;
	}
	l1->next = L1->next;
	L1 = L1->next;
	l2->next = L2->next;
	L2 = L2->next;
	l3->next = L3->next;
	L3 = L3->next;
	return true;
}

int main(){
	LinkList p = create(-1); // head node
	LNode *temp = p; // temporary pointer
	LinkList L1, L2, L3;
	
	// generate some element for testing
	for(ElemType i=32; i<=126; i++){
		temp->next = create(i);
		temp = temp->next;
	}
	
	// demo for testing
	std::cout<<"L1: A-Za-z, L2: 0-9, L3: others"<<std::endl;
	std::cout<<"Before run category(p, L1, L2, L3):"<<std::endl;
	std::cout<<"p:"<<std::endl;
	dispList(p);
	category(p, L1, L2, L3);
	std::cout<<"After runned category(p, L1, L2, L3):"<<std::endl; 
	std::cout<<"L1:"<<std::endl;
	dispList(L1);
	std::cout<<"L2:"<<std::endl;
	dispList(L2);
	std::cout<<"L3:"<<std::endl;
	dispList(L3);
	return 0;
}
```