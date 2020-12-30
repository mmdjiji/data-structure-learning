#include <cstdio>

void QuickSort(int *s, int l, int r){
    if(l<r){
        int i=l, j=r, x=s[l];
        printf("%4d", x);
        while(i<j){
            while(i<j && s[j]>=x) j--;
            if(i<j) s[i++]=s[j];
            while(i<j && s[i]<=x) i++;
            if(i<j) s[j--]=s[i];
        }
        s[i]=x;
        QuickSort(s, l, i-1);
        QuickSort(s, i+1, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    QuickSort(arr, 0, n-1);
    printf("\n");
    for(int i=0; i<n; i++)
        printf("%4d", arr[i]);
    return 0;
}
