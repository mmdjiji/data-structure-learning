#include <cstdio>
#include <cstdlib>

typedef char ElemType;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode *left, *right;
} BiTNode, *BiTree;

int maxDepth = 0;

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

void maxHeight(BiTree src, int depth){
    if(src){
        maxHeight(src->left, depth+1);
        maxHeight(src->right, depth+1);
        printf("%c", src->data);
        if(depth > maxDepth) maxDepth = depth;
    }
}

int main(){
	BiTree tree;
	createBiTree(tree);
    maxHeight(tree, 1);
    printf("\n%d\n", maxDepth);
	return 0;
}
