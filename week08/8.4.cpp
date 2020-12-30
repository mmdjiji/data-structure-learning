#include <cstdio>

int main(){
    int n, p, q;
    scanf("%d", &n);
    int tree[n];
    for(int i=0; i<n; i++){
        scanf("%d", &tree[i]);
    }
    scanf("%d %d", &p, &q);
    if(tree[p-1] == 0){
        printf("ERROR: T[%d] is NULL", p);
    }else if(tree[q-1] == 0){
        printf("ERROR: T[%d] is NULL", q);
    }else{
        while(p != q){
            if(p > q) p /= 2;
            else q /= 2;
        }
        printf("%d %d", p, tree[p-1]);
    }
    return 0;
}