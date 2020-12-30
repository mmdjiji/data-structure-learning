#include <cstdio>
#include <cstdlib>

struct node{
	int id, m;
	struct node *next;
};
struct node *create(int i, int m){
	struct node *retval;
	retval = (struct node *)malloc(sizeof(struct node));
	retval->id = i;
	retval->m = m;
	return retval;
}
int main(){
	int n, m, in, last;
	struct node *head = create(0, 0), *temp = head, *prev;
	scanf("%d", &n);
	last = n;
	for(int i=1; i<=n; i++){
		scanf("%d", &in);
		temp->next = create(i, in);
		temp = temp->next;
	}
	prev = temp;
	temp->next = head->next;
	temp = prev->next;
	free(head);
	
	m = temp->m;
	while(last > n/2){
		for(int i=0; i<m-1; i++){
			prev = prev->next;
			temp = prev->next;
		}
		prev->next = temp->next;
		m = temp->m;
		free(temp);
		temp = prev->next;
		last--;
	}
	head = temp;
	for(int i=0; i<last; i++){
		if(temp->id < head->id) head = temp;
		temp = temp->next;
	}
	temp = head;
	for(int i=0; i<last; i++){
		printf("%3d", temp->id);
		temp = temp->next;
	}
	return 0;
}
