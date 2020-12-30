#include <cstdio>
#include <queue>

typedef struct {
    char left, right;
}Tree;

int main(){
    char n, root, cur;
    scanf("%d", &n);
    Tree tree[n];
    bool flag[n], space = false;
    for(int i=0; i<n; i++){
        scanf(" %c %c", &tree[i].left, &tree[i].right);
        if(tree[i].left != '-') tree[i].left -= '0';
        if(tree[i].right != '-') tree[i].right -= '0';
        flag[i] = false;
    }
    for(int i=0; i<n; i++){
        if(tree[i].left != '-') flag[tree[i].left] = true;
        if(tree[i].right != '-') flag[tree[i].right] = true;
    }
    for(int i=0; i<n; i++){
        if(!flag[i]) {
            root = i;
            break;
        }
    }
    std::queue<char> todo;
    todo.push(root);
    
    while(!todo.empty()){
        cur = todo.front();
        todo.pop();
        if(tree[cur].left == '-' && tree[cur].right == '-'){
            if(!space) space = true && printf("%d", cur) ;
            else printf(" %d", cur);
        }
        if(tree[cur].left != '-') todo.push(tree[cur].left);
        if(tree[cur].right != '-') todo.push(tree[cur].right);
    }
    return 0;
}