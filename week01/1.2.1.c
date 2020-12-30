#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_MAXLEN 20
#define NAME_MAXLEN 20

struct node {
	char id[ID_MAXLEN];
	char name[NAME_MAXLEN];
	int grade;
	struct node *next;
};

struct node* wrapper(char *id, char *name, int grade){
	struct node *retval = (struct node*)malloc(sizeof(struct node));
	strncpy(retval->id, id, ID_MAXLEN);
	strncpy(retval->name, name, NAME_MAXLEN);
	retval->grade = grade;
	retval->next = NULL;
	return retval;
}

int main(){
	int i, N, temp, flag = 0;
	char id_buffer[ID_MAXLEN], name_buffer[NAME_MAXLEN];
	struct node *head, *now;
	scanf("%d", &N);
	if(N > 0){
		scanf("%s%s%d", id_buffer, name_buffer, &temp);
		head = wrapper(id_buffer, name_buffer, temp);
		now = head;
		for(i=0; i<N-1; i++){
			scanf("%s%s%d", id_buffer, name_buffer, &temp);
			now->next = wrapper(id_buffer, name_buffer, temp);
			now = now->next;
		}
		now = head;
		scanf("%s", id_buffer);
		while(now != NULL){
			if(strncmp(now->id, id_buffer, NAME_MAXLEN) == 0){
				printf("%d", now->grade);
				flag = 1;
				break;
			}
			if(now->next != NULL)
				now = now->next;
			else
				break;
		}
	}
	if(!flag)
		printf("not found!");
	return 0;
}
