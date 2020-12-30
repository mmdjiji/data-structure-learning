#include <cstdio>
#include <map>
typedef long long ll;
int main(){
	int n; ll temp;
	scanf("%d", &n);
	std::map<ll, int> counter;
	for(int i=0; i<2*n; i++){
		scanf("%lld", &temp);
		counter[temp]++;
	}
	temp = 0;
	std::map<ll, int>::iterator maximum = counter.begin();
	for(std::map<ll, int>::iterator it = maximum; it != counter.end(); it++){
		if(it->second > maximum->second){
			maximum = it;
			temp = 1;
		}else if(it->second == maximum->second){
			if(it->first < maximum->first)
				maximum = it;
			temp++;
		}
	}
	printf("%lld %d", maximum->first, maximum->second);
	if(temp > 1) printf(" %d", temp);
	return 0;
}
