#include <cstdio>
#include <cstdlib>
#include <queue>

typedef char ElemType;

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

int main(){
    BiTree tree, cur;
    std::queue<BiTree> todo;
    createBiTree(tree);
    if(tree) todo.push(tree);
    while(!todo.empty()){
        cur = todo.front();
        todo.pop();
        printf("%c", cur->data);
        if(cur->left) todo.push(cur->left);
        if(cur->right) todo.push(cur->right);
    }
    return 0;
}