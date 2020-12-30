# week1 - 程序填空题和主观题参考答案

## 程序填空题
1. 1. `pScore = malloc(m*n*sizeof(int))`
   2. `pScore, m, n, &row, &col`
   3. `&p[i*n+j]`
   4. `*pRow = 0`
   5. `*pCol = 0`
   6. `p[i*n+j] > max`

## 主观题

### Problem 1
```
in f1, x=2
after f1, n=1
in f2, x=2
after f2, n=2
```

### Problem 2
散列表，参考如下程序
```c++
#include <iostream>
#include <cstring>
#include <cstdlib>

#define HASH_MAX 50

struct node *list[HASH_MAX];

int hash(char* src) {
	int retval = 0, buf;
	for(int i=0; i<strlen(src); i++){
		buf = src[i];
		while(buf<0) buf += HASH_MAX;
		retval = (retval + buf) % HASH_MAX;
	}
	return retval;
}

typedef struct {
	char name[50];
	int extra;
}book;

struct node {
	book data;
	struct node *next;
};

int initList() {
	for(int i=0; i<HASH_MAX; i++) {
		list[i] = (struct node*)malloc(sizeof(struct node));
		if(list[i] != NULL) {
			list[i]->next = NULL;
		}else{
			return (-1);
		}
	}
	return 1;
}

int insertList(char *src, int extra){
	int index = hash(src);
	struct node *ptr;
	ptr = list[index];
	ptr->next = (struct node*)malloc(sizeof(struct node));
	if(ptr->next != NULL){
		ptr = ptr->next;
		strcpy(ptr->data.name, src);
		ptr->data.extra = extra;
		ptr->next = NULL;
		return 1;
	}
	return (-1);
}

int selectList(char *src){
	int index = hash(src);
	struct node *ptr;
	ptr = list[index];
	while(ptr->next != NULL){
		ptr = ptr->next;
		if(strcmp(ptr->data.name, src) == 0){
			return ptr->data.extra;
		}
	}
	return (-1);
}

int main(){
	initList();
	char test[] = "数据结构与算法";
	insertList(test, 1191002009);
	std::cout<<selectList(test);
	return 0;
}
```