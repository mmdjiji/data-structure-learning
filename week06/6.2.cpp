#include <cstdio>
#include <stack>

typedef struct {
	char data;
	int index;
} _operator;

const _operator operators[] = {
	{'+', 1},
	{'-', 1},
	{'*', 2},
	{'/', 2},
	{'%', 2}
};

int getIndex(char src){
	for(int i=0; i<sizeof(operators)/sizeof(operators[0]); i++)
		if(operators[i].data == src)
			return operators[i].index;
	return -1;
}

char pop(std::stack<char> &src){
	char retval = src.top();
	src.pop();
	return retval;
}

int main(){
	std::stack<char> result, opera;
	char ch;
	while((ch = getchar()) != '\n'){
		if(getIndex(ch) > 0){
			if(opera.empty() || opera.top() == '(' ){
				opera.push(ch);
			}else if(getIndex(ch) <= getIndex(opera.top())){
				result.push(opera.top());
				opera.pop();
				opera.push(ch);
			}else{
				opera.push(ch);
			}
		}else if(ch == '('){
			opera.push(ch);
		}else if(ch == ')'){
			while(!opera.empty() && opera.top() != '('){
				result.push(opera.top());
				opera.pop();
			}
			if(!opera.empty()) opera.pop();
		}else{
			result.push(ch);
		}
	}
	while(!opera.empty())
		result.push(pop(opera));
	while(!result.empty())
		opera.push(pop(result));
	while(!opera.empty())
		printf("%c", pop(opera));
	return 0;
}
