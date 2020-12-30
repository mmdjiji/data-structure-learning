#include <cstdio>
#include <cstdlib>
#include <cmath>

typedef struct Node {
	int id, power;
	char data;
	struct Node *left, *right;
} Node, *Tree;

typedef struct {
	int id;
	char data;
} Ret;

void swap(Tree &p, Tree &q) {Tree temp = p; p = q; q = temp;}

void show(int src){
	int len = log10(src);
	int diff = (int)pow(10, len);
	for(int i=0; i<len; i++){
		diff /= 10;
		printf("%d", src/diff%10);
	}
}

void traverse(Tree T, int src, Ret* result){
	if(T){
		if(T->data != '^'){
			result[T->id].data = T->data;
			result[T->id].id = src;
		}
		traverse(T->left, src * 10, result);
		traverse(T->right, src * 10 + 1, result);
	}
}

Tree findMin(Tree *T, int &n){
	int min = T[0]->power, imin = 0;
	Tree retval;
	for(int i=1; i<n; i++){
		if(T[i]->power < min){
			min = T[i]->power;
			imin = i;
		}
	}
	retval = T[imin];
	for(int i=imin; i<n-1; i++)
		T[i] = T[i+1];
	n--;
	return retval;
}

int main(){
	int n, m;
	scanf("%d", &n);
	m = n;
	Tree T[n];
	Ret result[n];
	for(int i=0; i<n; i++){
		T[i] = new Node;
		T[i]->left = NULL;
		T[i]->right = NULL;
		T[i]->id = i;
		scanf("%d", &(T[i]->power));
	}
	for(int i=0; i<n; i++)
		scanf(" %c", &(T[i]->data));
	if(m == 1) {
		printf("%c:0\n",T[0]->data);
	}else{
		while(m > 1){
			int min;
			Tree temp = new Node;
			temp->data = '^';
			temp->left = findMin(T, m);
			temp->right = findMin(T, m);
			temp->power = temp->left->power + temp->right->power;
			T[m++] = temp;
		}
		traverse(T[0], 1, result);
		for(int i=0; i<n; i++){
			printf("%c:", result[i].data);
			show(result[i].id);
			printf("\n");
		}
	}
	return 0;
}