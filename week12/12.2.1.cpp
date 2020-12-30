#include <cstdio>
#include <cstring>

#define HASHMAP_SIZE 18
#define PADDING_SIZE 3

typedef int static_hashmap[HASHMAP_SIZE];

int hash(int src){
	return src % 17;
}

bool eval(static_hashmap &map, int src, bool (*visit)(static_hashmap &map, int found, int src), bool neg = false){
	int newhash; 
	if(map[newhash = hash(src)] == (neg?(-1):src))
		return visit(map, newhash, src);
	for(int i=1; i<=HASHMAP_SIZE/2; i++){
		if(map[newhash = (hash(src) + i*i + PADDING_SIZE*HASHMAP_SIZE) % HASHMAP_SIZE] == (neg?(-1):src)){
			return visit(map, newhash, src);
		}else if(map[newhash = (hash(src) - i*i + PADDING_SIZE*HASHMAP_SIZE) % HASHMAP_SIZE] == (neg?(-1):src)){
			return visit(map, newhash, src);
		}
	}
	return false;
}

bool hash_select(static_hashmap &map, int found, int src){
	printf("%d\n", found);
	return true;
}

bool hash_delete(static_hashmap &map, int found, int src){
	map[found] = -1;
	return true;
}

bool hash_insert(static_hashmap &map, int found, int src){
	map[found] = src;
	return true;
}

int main(){
	static_hashmap hashMap;
	memset(hashMap, -1, sizeof(hashMap));
	
	int n, tmp;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		eval(hashMap, tmp, hash_insert, true);
	}
	scanf("%d", &tmp);
	if(!eval(hashMap, tmp, hash_select)) printf("-1\n");
	for(int i=0; i<2; i++){
		scanf("%d", &tmp);
		eval(hashMap, tmp, hash_delete);
	}
	scanf("%d", &tmp);
	eval(hashMap, tmp, hash_insert, true);
	for(int i=0; i<HASHMAP_SIZE; i++){
		if(hashMap[i] != -1){
			printf("%4d", hashMap[i]);
		}else{
			printf("****");
		}
	}
	return 0;
}
