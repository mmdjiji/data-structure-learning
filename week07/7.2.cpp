#include <cstdio>
#include <cstdlib>

typedef char ElemType;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode *left, *right;
} BiTNode, *BiTree;

int vDepth = 0;

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

BiTree findNode(BiTree src, ElemType dst, int depth){
	BiTree retval;
	if(src){
		if(src->data == dst){
			vDepth = depth;
			return src;
		}
		if(retval = findNode(src->left, dst, depth+1)) return retval;
		if(retval = findNode(src->right, dst, depth+1)) return retval;
	}
	return NULL;
}

int main(){
	ElemType ancestor, son;
	BiTree tree, result;
	createBiTree(tree);
	scanf(" %c%c", &ancestor, &son); 
	result = findNode(tree, ancestor, 0);
	if(findNode(result, son, 0)){
		printf("%d", vDepth);
	}else{
		printf("NO");
	}
	return 0;
}
