#include <cstdio>

int bucket[1000000]={0};
int main(){
	int n, m, flag=0;
	scanf("%d %d", &n, &m);
	for(int i=0, in; i<n; i++){
		scanf("%d", &in);
		bucket[in]++;
	}
	for(int i=1000000; i>=0; i--){
		if(!flag && bucket[i]){
			printf("%d", i);
			flag = 1; m--; bucket[i]--;
			continue;
		}else{
			while(bucket[i]-- && m-- > 0)
				printf(" %d", i);
		}
	}
	return 0;
}
