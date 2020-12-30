#include <cstdio>
#include <stack>
char getLeft(char src){
    switch(src){
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
    }
    return '\0';
}
int main(){
    char ch; bool flag = true;
    std::stack<char> op;
    while(scanf("%c", &ch) != EOF){
        if(ch == '(' || ch == '[' || ch == '{'){
            op.push(ch);
        }else if(ch == '/'){
            ch = getchar();
            if(ch == '*'){
                op.push('<');
            }else{
                ungetc(ch, stdin);
            }
        }else if(ch == ')' || ch == ']' || ch == '}'){
            if(!op.empty() && op.top() == getLeft(ch)){
                op.pop();
            }else{
                flag = false;
                break;
            }
        }else if(ch == '*'){
            ch = getchar();
            if(ch == '/'){
                if(!op.empty() && op.top() == '<'){
                    op.pop();
                }else{
                    ch = '>';
                    flag = false;
                    break;
                }
            }else{
                ungetc(ch, stdin);
            }
        }
    }
    if(!op.empty()){
        printf("NO\n");
        if(op.top() == '<'){
            printf("/*");
        }else{
            printf("%c", op.top());
        }
        printf("-?");
    }else if(flag){
        printf("YES\n");
    }else{
        printf("NO\n?-");
        if(ch == '>'){
            printf("*/");
        }else{
            printf("%c", ch);
        }
    }
    return 0;
}
