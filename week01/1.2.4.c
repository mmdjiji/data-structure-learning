#include <stdio.h>

int main(){
	int i, K, this_sum=0, max_sum=0, tmp;
	scanf("%d", &K);
	for(i=0; i<K; i++){
		scanf("%d", &tmp);
		this_sum += tmp;
		if(this_sum < 0) this_sum = 0;
		if(this_sum > max_sum) max_sum = this_sum;
	}
	printf("%d", max_sum); 
	return 0;
}
