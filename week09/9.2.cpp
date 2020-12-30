#include <stdio.h>
#include <math.h>

typedef struct {
	int x, y;
}_point;

void swap(_point &p, _point &q) {_point temp = p; p = q; q = temp;}
int x2y2(_point src) {return src.x * src.x + src.y * src.y;}
int x2y2(_point src1, _point src2){return (src1.x-src2.x) * (src1.x-src2.x) + (src1.y-src2.y) * (src1.y-src2.y);}

int main(){
	int N, D, cmpd;
	double cmpv;
	scanf("%d %d", &N, &D);
	_point point[N];
	cmpd = 50-D;
	bool arrive[N]={0};
	for(int i=0; i<N; i++)
		scanf("%d %d", &point[i].x, &point[i].y);
	for(int i=0; i<N; i++)
		for(int j=0; j<N-i-1; j++)
			if(x2y2(point[j]) > x2y2(point[j+1]))
				swap(point[j], point[j+1]);
	
	cmpv = (D+7.5)*(D+7.5);
	for(int i=0; i<N; i++){
		if(x2y2(point[i]) <= cmpv){
			arrive[i] = true;
			if(abs(point[i].x) >= cmpd || abs(point[i].y) >= cmpd){
				printf("Yes");
				return 0;
			}
		}else break;
	}
	
	cmpv = D * D;
	for(int i=0; i<N; i++){
		if(arrive[i]){
			for(int j=0; j<N; j++){
				if(!arrive[j] && x2y2(point[i], point[j]) <= cmpv){
					arrive[j] = true;
					if(abs(point[j].x) >= cmpd || abs(point[j].y) >= cmpd){
						printf("Yes");
						return 0;
					}
				}
			}
		}
	}
	printf("No");
	return 0;
}