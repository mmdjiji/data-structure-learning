#include <cstdio>

int main(){
	double stack[100];
	char ch;
	int top = 0;
	double result = 0;
	double op1, op2;
	while((ch = getchar()) != '\n'){
		switch(ch){
			case '+':
				op2 = stack[--top];
				op1 = stack[--top];
				result = op1 + op2;
				stack[top++] = result;
				break;
			case '-':
				op2 = stack[--top];
				op1 = stack[--top];
				result = op1 - op2;
				stack[top++] = result;
				break;
			case '*':
				op2 = stack[--top];
				op1 = stack[--top];
				result = op1 * op2;
				stack[top++] = result;
				break;
			case '/':
				op2 = stack[--top];
				op1 = stack[--top];
				result = (double)op1 / op2;
				stack[top++] = result;
				break;
			case '%':
				op2 = stack[--top];
				op1 = stack[--top];
				result = (int)op1 % (int)op2;
				stack[top++] = result;
				break;
			default:
				stack[top++] = ch - '0';
				break;
		}
	}
	printf("%.2lf", stack[0]);
	return 0;
}
