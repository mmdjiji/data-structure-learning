#include <cstdio>

int count = 0;
void swap(int &p, int &q){
	p^=q; q^=p; p^=q;
	count++;
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	int left=0, right=n-1;
	while(left < right){
		for(int i=left; i<right; i++)
			if(arr[i] > arr[i+1])
				swap(arr[i], arr[i+1]); 
		right--;
		for(int i=right; i>left; i--)
			if(arr[i]<arr[i-1])
				swap(arr[i], arr[i-1]);
		left++;
	}
	printf("%4d\n", count);
	for(int i=0; i<n; i++)
		printf("%4d", arr[i]);
	return 0;
}
