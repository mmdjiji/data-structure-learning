# exam1 - 参考答案

## 客观题
1. B
2. C
3. B
4. D
5. B
6. D
7. B
8. A
9. A
10. C
11. D
12. A
13. B
14. D
15. D
16. C
17. B
18. A
19. D
20. D

## 程序填空题
1. 1. `L.elem + i - 1`
   2. `L.elem + L.length - 1`
   3. `p<q`
   4. `*p = *(p+1)`
   5. `L.length--`
2. 1. `Q.rear == Q.front`
   2. `p->next`
   3. `Q.rear = Q.front`
3. 1. `L.elem[i-1] > x`
   2. `L.elem[j] = L.elem[j-1]`
   3. `L.elem[i-1] = x`
   4. `L.length++`
4. 1. `Push(S, ch[i])`
   2. `StackEmpty(S)`
   3. `Pop(S, t)`
   4. `!StackEmpty(S)`
5. 1. `i <= La_len && j <= Lb_len`
   2. `ListInsert(Lc, 1, ai)`
   3. `ListInsert(Lc, 1, bj)`
   4. `GetElem(La,i,ai); ListInsert(Lc, 1, ai); i++;`
   5. `GetElem(Lb,j,bj); ListInsert(Lc, 1, bj); j++;`

## 主观题

### Problem 1
```c++
int Delete(SqList &L, ElemType min, ElemType max){
	int retval = 0;
	for(int i=0; i<L.length; i++){
		if(L.elem[i] < max && L.elem[i] > min){
			for(int j=i; j<L.length-1; j++){
				L.elem[j] = L.elem[j+1];
			}
			retval++;
			L.length--;
			i--;
		}
	}
	return retval;
}
```
### Problem 2
```c++
void change(Queue &Q, ElemType min, ElemType max){
	SqStack S;
	ElemType tmp;
	InitStack(S);
	while(QueueLength(Q) > 0){
		DeQueue(Q, tmp);
		if(tmp < min || tmp > max){
			Push(S, tmp);
		}
	}
	while(!StackEmpty(S)){
		Pop(S, tmp);
		EnQueue(Q, tmp);
	}
}
```