#include <cstdio>
#include <cstring>

int main(){
	int n, m, ans=0, count=0;
	scanf("%d %d", &n, &m);
	int matrix[n][n], indegree[n] = {0}, dis[n] = {0};
	memset(matrix, -1, sizeof(matrix));
	for(int i=0, p, q; i<m; i++){
		scanf("%d %d", &p, &q);
		scanf("%d", &matrix[p][q]);
		indegree[q]++;
	}
	while(true){
		bool flag = false;
		for(int i=0; i<n; i++){
			if(indegree[i] == 0){
				indegree[i] = -1;
				flag = true;
				count++;
				for(int j=0; j<n; j++){
					if(matrix[i][j] >= 0){
						indegree[j]--;
						if(dis[i] + matrix[i][j] > dis[j]) dis[j] = dis[i] + matrix[i][j];
						if(ans < dis[j]) ans = dis[j];
					}
				}
			}
		}
		if(!flag) break;
	}
	if(count == n){
		printf("%d", ans);
	}else{
		printf("Impossible");
	}
	return 0;
}
