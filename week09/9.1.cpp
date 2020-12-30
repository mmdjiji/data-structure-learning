#include <iostream>
#include <cstdio>
#include <string>
#define MAXLEN 30

int n;
bool visited[MAXLEN] = {0}, adj[MAXLEN][MAXLEN];
std::string nodes[MAXLEN];

void traverse(int src){
	for(int i=0; i<n; i++){
		if(adj[src][i] && !visited[i]){
			visited[i] = true;
			std::cout<<nodes[i]<<" ";
			traverse(i);
		}
	}
}
int main(){
	std::cin>>n;
	for(int i=0; i<n; i++)
		std::cin>>nodes[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &adj[i][j]);
	for(int i=0; i<n; i++){
		if(!visited[i]){
			std::cout<<nodes[i]<<" ";
			visited[i] = true;
			traverse(i);
		}
	}
	return 0;
}