#include <cstdio>
#include <cstring>

void getnext(char *p, int *next){
	next[0] = -1;
	int i = 1, j = 0;
	while (i < p[0]){
		if (j == 0 || p[i] == p[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
}

int KMP(char *s, char *t, int *next) {
	int i = 1, j = 1;
	while (i <= s[0] && j <= t[0]){
		if (j == 0 || s[i] == t[j]) {
			i++; j++;
        }else{
            j = next[j];
    	}
    }
    if (j > t[0])
       return i - t[0];
    else 
       return 0;
}

int main(){
	char s1[80], s2[80];
	int next[80];
	scanf("%s%s", s1+1, s2+1);
	s1[0] = strlen(s1+1);
	s2[0] = strlen(s2+1);
	getnext(s1, next);
	for(int i=1; i<=s1[0]; i++){
		printf("%3d", next[i]);
	}
	printf("\n%3d", KMP(s2, s1, next));
	return 0;
}
