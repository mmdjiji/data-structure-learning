#include <cstdio>
#include <queue>

#define MAXN 10

int N, E;
bool matrix[MAXN][MAXN]={0}, dfs_visited[MAXN]={0}, bfs_visited[MAXN]={0};
std::queue<int> todo;

void dfs(int src){
	bool flag = false;
	if(!dfs_visited[src]){
		dfs_visited[src] = true;
		printf("{ %d ", src);
		flag = true;
	}
	for(int i=0; i<N; i++){
		if(matrix[src][i] && !dfs_visited[i]){
			printf("%d ", i);
			dfs_visited[i] = true;
			dfs(i);
		}
	}
	if(flag){
		printf("}\n");
	}
}

void bfs(int src){
	bool flag = false;
	if(!bfs_visited[src]){
		bfs_visited[src] = true;
		todo.push(src);
		printf("{ %d ", src);
		flag = true;
	}
	while(!todo.empty()){
		int node = todo.front();
		todo.pop();
		for(int i=0; i<N; i++){
			if(matrix[node][i] && !bfs_visited[i]){
				printf("%d ", i);
				bfs_visited[i] = true;
				todo.push(i);
			}
		}
	}
	if(flag){
		printf("}\n");
	}
}

int main(){
	scanf("%d %d", &N, &E);
	for(int i=0, p, q; i<E; i++){
		scanf("%d %d", &p, &q);
		matrix[p][q] = matrix[q][p] = true;
	}
	for(int i=0; i<N; i++)
		dfs(i);
	for(int i=0; i<N; i++)
		bfs(i);
	return 0;
}