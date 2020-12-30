#include <cstdio>
#include <cstdlib>

struct node {
	int n;
	struct node *next;
};
struct node *create(int n){
	struct node *retval;
	retval = (struct node *)malloc(sizeof(struct node));
	retval->n = n;
	return retval;
}
int main(){
    int in, k, flag = 1;
	struct node *head = NULL, *temp = NULL;
    scanf("%d", &k);
	while(scanf("%d", &in) != EOF && in >= 0){
		temp = create(in);
		temp->next = head;
		head = temp;
	}
	for(int i=0; i<k-1; i++){
		if(temp->next != NULL){
			temp = temp->next;
		}else{
			flag = 0;
			break;
		}
	}
	if(flag){
		printf("%d", temp->n);
	}else{
		printf("NULL");
	}
    return 0;
}
