# week4 - 程序填空题和主观题参考答案

## 程序填空题
1. 1. `L->next = L`
   2. `p != L`
   3. `L->next == L`
   4. `L->next`
   5. `p != L && j < i`
   6. `j<i`
   7. `p->data`
   8. `p->next != L && j < i-1`
   9. `p->next`
   10. `p->next = s`
   11. `0`
   12. `p->next != L && j < i-1`
   13. `j<i-1`
   14. `q->next`
   15. `q->data`

## 主观题

### Problem 1
```c++
#include <cstdio>
#include <stack>

int main(){
	std::stack<char> s;
	char ch;
	bool found = false, flag = true;
	while((ch = getchar()) != '@'){
		if(found){
			if(!s.empty()){
				if(ch != s.top()){
					flag = false;
					break;
				}
				s.pop();
			}
		}else if(ch != '&'){
			s.push(ch);
		}else{
			found = true;
		}
	}
	if(flag && s.empty())
		printf("YES");
	else
		printf("NO");
	return 0;
}
```
### Problem 2
```c++
#include <cstdio>
#include <cstdlib>

typedef int ElemType;

struct node {
	ElemType data;
	struct node *next;
};

typedef struct{
	struct node *rear;
}Queue;

bool InitQueue(Queue &src){
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = -1;
	head->next = head;
	src.rear = head;
	return true;
}

bool EnQueue(Queue &src, ElemType e){
	struct node *ins = (struct node*)malloc(sizeof(struct node));
	ins->data = e;
	ins->next = src.rear->next;
	src.rear->next = ins;
	src.rear = src.rear->next;
	return true;
}

bool DeQueue(Queue &src, ElemType &e){
	struct node *head = src.rear->next;
	struct node *out = head->next;
	if(head->next != head){
		e = out->data;
		head->next = out->next;
		free(out);
		return true;
	}else{
		e = -1;
		return false;
	}
}

int main(){
	Queue s;
	InitQueue(s);
	for(int i=0; i<10; i++){
		ElemType e = i;
		EnQueue(s, e);
	}
	for(int i=0; i<10; i++){
		ElemType e;
		DeQueue(s, e);
		printf("%d\n", e);
	}
	return 0;
}
```
### Problem 3
```c++
#include <cstdio>
#include <cstdlib>

#define QUEUE_LEN 100
typedef int ElemType;

typedef struct{
	ElemType base[QUEUE_LEN];
	int rear, length; 
}Queue;

bool InitQueue(Queue &src){
	src.rear = QUEUE_LEN-1;
	src.length = 0;
	return true;
}

bool EnQueue(Queue &src, ElemType e){
	if(src.length < QUEUE_LEN){
		src.rear = (src.rear+1) % QUEUE_LEN;
		src.base[src.rear] = e;
		src.length++;
		return true;
	}else{
		return false;
	}
}

bool DeQueue(Queue &src, ElemType &e){
	if(src.length > 0){
		e = src.base[(src.rear - src.length + 1 + QUEUE_LEN) % QUEUE_LEN];
		src.length--;
		return true;
	}else{
		e = -1;
		return false;
	}
}

int main(){
	Queue s;
	InitQueue(s);
	for(int i=0; i<10; i++){
		ElemType e = i;
		EnQueue(s, e);
		printf("After EnQueue(s, %d), s.length = %d\n", i, s.length);
	}
	for(int i=0; i<10; i++){
		ElemType e;
		DeQueue(s, e);
		printf("After DeQueue(s, e) and get e = %d, s.length = %d\n", e, s.length);
	}
	return 0;
}
```