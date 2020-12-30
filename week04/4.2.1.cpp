#include <cstdio>

typedef struct node{
	int coef;
	int expn;
} node;

void swap(node &p, node &q) {node temp; temp = p; p = q; q = temp;}

int main() {
	int n, coef, expn, flag = 1;
	scanf("%d", &n);
	node list[n];
        if(n == 0) {
            printf("0 0");
            return 0;
        }
	for(int i=0; i<n; i++){
		scanf("%d %d", &coef, &expn);
		list[i].coef = coef * expn;
		list[i].expn = expn - 1;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			if(list[j].expn < list[j+1].expn){
				swap(list[j], list[j+1]);
			}
		}
	}
	
	for(int i=n-1; i>0; i--){
		if(list[i].coef){
			printf("%d %d ", list[i].coef, list[i].expn);
			flag = 0;
		}
	}
	if(list[0].coef)
		printf("%d %d", list[0].coef, list[0].expn);
	else if(flag)
		printf("0 0");
	return 0;
}
