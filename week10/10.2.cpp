#include <cstdio>

typedef char Node[6];
const int inf = 999;

typedef struct {
	int value, from;
} _dis;

int main(){
	int n, whomin;
	scanf("%d", &n);
	Node nodes[n];
	bool matrix[n][n];
	bool ins[n]={0};
	_dis dis[n];
	
	for(int i=0; i<n; i++)
		scanf("%s", nodes[i]);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &matrix[i][j]);
	
	for(int i=0; i<n; i++){
		dis[i].value = matrix[n-1][i];
		dis[i].from = n-1;
	}
	ins[n-1] = true;
	for(int i=0; i<n-1; i++){
		int minimum = inf;
		for(int j=0; j<n; j++){
			if(!ins[j] && dis[j].value < minimum){
				minimum = dis[j].value;
				whomin = j;
			}
		}
		ins[whomin] = true;
		printf("%s %s\n", nodes[dis[whomin].from], nodes[whomin]);
		for(int j=0; j<n; j++){
			if(!ins[j] && dis[j].value > matrix[whomin][j]){
				dis[j].value = matrix[whomin][j];
				dis[j].from = whomin;
			}
		}
	}
	return 0;
}