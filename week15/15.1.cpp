#include <cstdio>
#include <cstring>

int main(){
	char s1[80], s2[80];
	scanf("%s%s", s1, s2);
	int index = 0, len = strlen(s1);
	bool flag = false;
	while(index < s2-s1){
		if(strncmp(s2+index, s1, len) == 0){
			printf("%3d", index+1);
			index += len;
			flag = true;
		}else{
			index++;
		}
	}
	if(!flag) printf("%3d", 0);
	return 0;
}
