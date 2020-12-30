#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

struct node{
    int index;
    struct node *next;
};
typedef struct{
    char data[10];
    struct node *firstarc;
    int indegree;
}Table;

int main(){
    int n, arcs;
    scanf("%d %d", &n, &arcs);
    Table table[n];
    
    for(int i=0; i<n; i++){
        scanf("%s", table[i].data);
        table[i].firstarc = NULL;
        table[i].indegree = 0;
    }
    
    for(int i=0; i<arcs; i++){
        char temp[10];
        scanf("%s", temp);
        for(int j=0, dst; j<n; j++){
            if(strcmp(table[j].data, temp) == 0){
                struct node *ins = new struct node;
                scanf("%s", temp);
                for(int k=0; k<n; k++){
                    if(strcmp(table[k].data, temp) == 0){
                        dst = k;
                        break;
                    }
                }
                ins->index = dst;
                ins->next = table[j].firstarc;
                table[j].firstarc = ins;
                table[dst].indegree++;
                break;
            }
        }
    }
    
    std::stack<int> todo;
    for(int i=0; i<n; i++){
        if(table[i].indegree == 0){
            todo.push(i);
            table[i].indegree--;
        }
    }
    
    int count = 0;
    while(!todo.empty()){
        int cur = todo.top(); todo.pop();
        printf("%s ", table[cur].data);
        struct node *temp = table[cur].firstarc, *todel;
        while(temp){
            if(!(--table[temp->index].indegree))todo.push(temp->index);
            todel = temp;
            temp = temp->next;
            free(todel);
        }
        table[cur].firstarc = NULL;
        count++;
    }
    
    if(count < n) printf("error");
    return 0;
}
