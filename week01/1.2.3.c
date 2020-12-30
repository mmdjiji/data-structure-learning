#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node* wrapper(int data){
	struct node *retval = (struct node*)malloc(sizeof(struct node));
	retval->data = data;
	retval->next = NULL; 
	return retval;
}

int main(){
	int input, todel;
	struct node *head = wrapper(0), *now = head, *prev;
	while(scanf("%d", &input) != EOF && input != 0){
		now->next = wrapper(input);
		now = now->next;
	}
	prev = head;
	now = prev->next;
	scanf("%d", &todel);
	while(now != NULL){
		if(todel == now->data){
			prev->next = now->next;
			free(now);
			now = prev->next;
		}else if(prev->next != NULL){
			prev = prev->next;
			now = prev->next;
		}else{
			break;
		}
	}
	now = head->next;
	while(now != NULL){
		printf("%d", now->data);
		if(now->next != NULL){
			now = now->next;
		}else{
			break;
		}
	}
	return 0;
}
