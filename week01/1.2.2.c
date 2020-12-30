#include <stdio.h>

#define LEN_ARRAY 40

int swap(int *p, int *q){*p^=*q;*q^=*p;*p^=*q;}

int findMean(int *arr){
	int i, retval = 0;
	for(i=0; i<LEN_ARRAY; i++)
		retval += arr[i];
	retval /= LEN_ARRAY;
	return retval;
}

int findMedian(int *arr){
	int i, j;
	for(i=0; i<LEN_ARRAY-1; i++){
		for(j=0; j<LEN_ARRAY-i-1; j++){
			if(arr[j+1] > arr[j]){
				swap(&arr[j+1], &arr[j]);
			}
		}
	}
	if(LEN_ARRAY % 2 == 0){
		return (arr[LEN_ARRAY / 2 - 1] + arr[LEN_ARRAY / 2]) / 2;
	}else{
		return arr[LEN_ARRAY / 2];
	}
}

int findMode(int *arr){
	int i, bucket[10] = {0}, max_value, max_i;
	for(i=0; i<LEN_ARRAY; i++)
		bucket[arr[i]-1]++;
	max_i = 0;
	max_value = bucket[0];
	for(i=1; i<10; i++){
		if(bucket[i] > max_value){
			max_value = bucket[i];
			max_i = i;
		}
	}
	return max_i+1;
}

int main(){
	int i, arr[LEN_ARRAY];
	for(i=0; i<LEN_ARRAY; i++)
		scanf("%d", &arr[i]);
	printf("Mean value=%d\nMedian value=%d\nMode value=%d\n",
		findMean(arr), findMedian(arr), findMode(arr));
	return 0;
}
