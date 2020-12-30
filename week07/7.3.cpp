#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef char ElemType;

typedef struct TNode {
	ElemType data;
	struct TNode *left, *right;
} Node, *Tree;

void createTree(Tree &T, ElemType *preOrder, ElemType *midOrder, ElemType *midTail){
	if(midOrder == midTail){
		T = (Tree)malloc(sizeof(Node));
		T->data = *midOrder;
		T->left = NULL;
		T->right = NULL;
	}else{
		bool flag = false;
		while(*preOrder != '\0' && !flag){
			for(ElemType *i=midOrder; i<=midTail; i++){
				if(*i == *preOrder){
					T = (Tree)malloc(sizeof(Node));
					T->data = *i;
					T->left = NULL;
					T->right = NULL;
					if(i != midOrder)
						createTree(T->left, preOrder+1, midOrder, i-1);
					if(i != midTail)
						createTree(T->right, preOrder+1, i+1, midTail);
					flag = true;
					break;
				}
			}
			preOrder++;
		}
	}
}

void postPrint(Tree T){
	if(T){
		postPrint(T->left);
		postPrint(T->right);
		printf("%c", T->data);
	}
}

int counts(Tree T){
	static int sum = 0;
	if(T){
		sum++;
		counts(T->left);
		counts(T->right);
	}
	return sum;
}

int main(){
	ElemType preOrder[26], midOrder[26];
	Tree T;
	scanf("%s %s", preOrder, midOrder);
	createTree(T, preOrder, midOrder, midOrder + strlen(midOrder) - 1);
	postPrint(T);
	printf("\n%d", counts(T->left));
	return 0;
}