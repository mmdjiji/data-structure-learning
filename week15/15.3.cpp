#include <cstdio>
#include <cstring>

void getnextval(char *p, int *nextval){
	nextval[0] = -1;
	nextval[1] = 0;
	int i = 1, j = 0;
	while (i < p[0]){
		if (j == 0 || p[i] == p[j]){
			i++; j++;
			if(p[i] != p[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}else{
			j = nextval[j];
		}
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
	int nextval[80];
	scanf("%s%s", s1+1, s2+1);
	s1[0] = strlen(s1+1);
	s2[0] = strlen(s2+1);
	getnextval(s1, nextval);
	for(int i=1; i<=s1[0]; i++){
		printf("%3d", nextval[i]);
	}
	printf("\n%3d", KMP(s2, s1, nextval));
	return 0;
}
