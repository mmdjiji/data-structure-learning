#include <cstdio>
#include <cstring>
#include <queue>

struct node{
	int index;
	struct node *next;
};

typedef struct{
	char data[10];
	struct node *firstarc;
}Table;

int main(){
	int n, arcs;
	scanf("%d %d", &n, &arcs);
	Table table[n];
	bool visited[n]={0}, outputed[n]={0};
	for(int i=0; i<n; i++){
		scanf("%s", table[i].data);
		table[i].firstarc = NULL;
	}
	for(int i=0; i<arcs; i++){
		struct node *ins = new struct node;
		char srcNode[10], dstNode[10];
		scanf("%s %s", srcNode, dstNode);
		for(int j=0; j<n; j++){
			if(strcmp(dstNode, table[j].data) == 0){
				ins->index = j;
				break;
			}
		}
		for(int j=0; j<n; j++){
			if(strcmp(srcNode, table[j].data) == 0){
				ins->next = table[j].firstarc;
				table[j].firstarc = ins;
				break;
			}
		}
	}
	std::queue<int> todo;
	for(int i=0; i<n; i++){
		if(!visited[i]){
			todo.push(i);
			while(!todo.empty()){
				int cur = todo.front();
				todo.pop();
				visited[cur] = true;
				if(!outputed[cur]){
					outputed[cur] = true;
					printf("%s ", table[cur].data);
				}
				struct node *inner = table[cur].firstarc;
				while(inner != NULL){
					if(!outputed[inner->index]){
						outputed[inner->index] = true;
						printf("%s ", table[inner->index].data);
					}
					if(!visited[inner->index])
						todo.push(inner->index);
					inner = inner->next;
				}
			}
		}
	}
	return 0;
}