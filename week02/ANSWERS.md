# week2 - 程序填空题和主观题参考答案

## 程序填空题
1. 1. `(ElemType *)malloc(sizeof(LIST_INIT_SIZE*sizeof(ElemType)))`
   2. `0`
   3. `return L.length`
   4. `i<1||i>L.length`
   5. `L.elem[i-1]`
   6. `&L.elem[i-1]`
   7. `&L.elem[L.length]`
   8. `*p = *(p-1)`
   9. `L.length++`
   10. `i<=L.length && !(*compare)(*p++,e)`
   11. `return i`
2. 1. `InitList_Sq(Lc)`
   2. `La.length`
   3. `Lb.length`
   4. `(i<=La_len) && (j<=Lb_len)`
   5. `ListInsert_Sq(Lc, ++k, ai)`
   6. `ListInsert_Sq(Lc, ++k, bj)`
   7. `GetElem_Sq(La, i++, ai); ListInsert_Sq(Lc, ++k, ai);`
   8. `GetElem_Sq(Lb, j++, bj); ListInsert_Sq(Lc, ++k, bj);`
3. 1. `La.elem`
   2. `Lb.elem`
   3. `pa_last`
   4. `pb_last`
   5. `*pc++ = *pa++`
   6. `*pc++ = *pb++`
   7. `pa <= pa_last`
   8. `pb <= pb_last`

## 主观题

### Problem 1
(1): T(n) = n-1  
(2): T(n) = n-1  
(3): T(n) = n-1  
(4): T(n) = n(n+1)/2  
(5): T(n) = n(n+1)(n+2)/6

### Problem 2
```c++
Status ListInsert(SqList &va, ElemType x){
	if (va.length>=va.listsize) {
		ElemType *newbase = (ElemType *)realloc(va.elem, (va.listsize+LISTINCREMENT) * sizeof(ElemType));
		if(!newbase) return OVERFLOW;
		va.elem = newbase;
		va.listsize += LISTINCREMENT;
	}
	for(int i=1; i<=va.length; i++){
		if(x <= va.elem[i]){
			for(int j=va.length; j>=i; j--)
				va.elem[j] = va.elem[j-1];
			va.elem[i] = x;
		}else{
         va.elem[va.length+1] = x;
         break;
      }
	}
	va.length++;
	return OK;
}
```

### Problem 3
```c++
int ploynomial(int n, int *a, int x){
	int retval = a[0], tmpX = 1;
	for(int i=1; i<=n; i++){
		tmpX *= x;
		retval += a[i] * tmpX;
	}
	return retval;
}
```
时间复杂度: T(n) = O(n)  
空间复杂度: S(n) = O(n)