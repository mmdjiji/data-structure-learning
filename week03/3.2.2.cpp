#include <cstdio>
#include <cstdlib>
#include <cmath>

bool flag[10000];

typedef struct {
	int data, prev, next;
} node;

int headAddr, delAddr = -1;
node list[100000];

bool delNode(int &delTemp, int &addr){
	int theNext = list[addr].next;
	if(theNext == -1){
		list[list[addr].prev].next = -1;
	}else{ //obviously list[addr].prev != -1
		list[list[addr].prev].next = list[addr].next;
		list[list[addr].next].prev = list[addr].prev;
	}
	list[delTemp].next = addr;
	list[addr].next = -1;
	delTemp = addr;
	if(delAddr == -1) delAddr = addr;
	addr = theNext;
	return true;
}

bool printNode(int addr){
	printf("%05d ", addr);
	printf("%d ", list[addr].data);
	if(list[addr].next != -1){
		printf("%05d", list[addr].next);
	}else{
		printf("-1");
	}
	printf("\n");
	return true;
}

bool printList(int addr){
	while(list[addr].next != -1){
		printNode(addr);
		addr = list[addr].next;
	}
	printNode(addr);
	return true;
}

bool setPrev(int addr){
	int prev = -1;
	while(list[addr].next != -1){
		list[addr].prev = prev;
		prev = addr;
		addr = list[addr].next;
	}
	list[addr].prev = prev;
	return true;
}

bool judgeNode(int &delTemp, int &addr){
	if(flag[abs(list[addr].data)]){
		delNode(delTemp, addr);
		return true;
	}else{
		flag[abs(list[addr].data)] = true;
		return false;
	}
}

int main(){
	int delTemp = -1, n;
	scanf("%d %d", &headAddr, &n);
	
	for(int addr, data, next, i=0; i<n; i++){
		scanf("%d %d %d", &addr, &data, &next);
		list[addr].data = data;
		list[addr].next = next;
	}
	if(n == 1){
		printList(headAddr);
		return 0;
	}
	setPrev(headAddr);
	int addr = headAddr;
	while(list[addr].next != -1){
		if(!judgeNode(delTemp, addr))
			addr = list[addr].next;
	}
	judgeNode(delTemp, addr);
	printList(headAddr);
	printList(delAddr);
	return 0;
}
