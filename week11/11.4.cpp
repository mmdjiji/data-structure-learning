#include <cstdio>
#include <cstring>

typedef char _node[20];
int main(){
	int n;
	scanf("%d", &n);
	_node node[n], src, dst;
	int matrix[n][n], dis[n], srci, dsti;
	memset(dis, 999, sizeof(dis));
	for(int i=0; i<n; i++){
		scanf("%s", node[i]);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(matrix[i][j] > matrix[i][k] + matrix[k][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
	
	scanf("%s %s", src, dst);
	for(int i=0; i<n; i++){
		if(strcmp(src, node[i]) == 0){
			srci = i;
			break;
		}
	}
	for(int i=0; i<n; i++){
		if(strcmp(dst, node[i]) == 0){
			dsti = i;
			break;
		}
	}
	printf("%d", matrix[srci][dsti]);
	return 0;
}
