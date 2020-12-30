#include <cstdio>
#include <cstdlib>
#include <stack>

typedef char ElemType;

std::stack<ElemType> path;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode *left, *right;
} BiTNode, *BiTree;

bool createBiTree(BiTree &src){
	ElemType in;
	scanf("%c", &in);
	if(in == '*'){
		src = NULL;
	}else{
		src = (BiTNode *)malloc(sizeof(BiTNode));
		src->data = in;
		createBiTree(src->left);
		createBiTree(src->right);
	}
	return true;
}

bool getpath(BiTree T, ElemType target){
	if(!T) return false;
	path.push(T->data);
	if(T->data == target) return true;
	bool ret = false;
	if(T->left) ret = getpath(T->left, target);
	if(!ret && T->right) ret = getpath(T->right, target);
	if(!ret) path.pop();
	return ret;
}

int main(){
	BiTree tree;
	ElemType target;
	createBiTree(tree);
	scanf(" %c", &target);
	getpath(tree, target);
	printf("the path is:");
	if(!path.empty()){
		printf("%c", path.top());
		path.pop();
	}
	while(!path.empty()){
		printf("<-%c", path.top());
		path.pop();
	}
	return 0;
}