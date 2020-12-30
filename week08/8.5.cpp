#include <cstdio>
#include <cstring>
#include <queue>

struct node {
	char data[12];
	int childnum = 0;
	struct node *children[10];
};

struct node *wrapper(char *data){
	struct node *retval = new struct node;
	strcpy(retval->data, data);
	return retval;
}

void traverse(struct node *src, int depth){
	if(src){
		for(int i=0; i<depth; i++)
			printf("%-12s", "|-");
		printf("%-12s\n", src->data);
		for(int i=0; i<src->childnum; i++){
			traverse(src->children[i], depth+1);
		}
	}
}

int main(){
	char ch, buffer[12];
	
	std::queue<struct node *> todo;
	
	strcpy(buffer, "|-*/");
	struct node *root = wrapper(buffer);
	
	while(scanf("%c", &ch) != EOF){
		if(ch == '\n' || ch == '('){
			//nothing to do
		}else if(ch == '*'){
			scanf("%c", &ch);
			if(ch == '*'){
				break;
			}else if(ch == '/'){
				strcpy(buffer, "*/");
				scanf("%s", buffer+2);
				
				// the folder under root
				root->children[root->childnum++] = wrapper(buffer);
				todo.push(root->children[root->childnum-1]);
				
				while(!todo.empty()){
					struct node *cur = todo.front();
					todo.pop();
					
					int bufcnt = 0;
					while(scanf("%c", &ch) != EOF){
						if(ch == ' ' || ch == ')'){
							if(bufcnt > 0){
								buffer[bufcnt] = '\0';
								// the file/foder under cur
								cur->children[cur->childnum++] = wrapper(buffer);
								if(buffer[0] == '*'){
									// the folder under cur
									todo.push(cur->children[cur->childnum-1]);
								}
								bufcnt = 0;
							}
							if(ch == ')') break;
						}else if(ch != '(' && ch != '\n'){
							buffer[bufcnt++] = ch;
						}
					}
				}
			}
		}else{
			buffer[0] = ch;
			scanf("%s", buffer+1);
			// the file under root
			root->children[root->childnum++] = wrapper(buffer);
		}
	}
	
	traverse(root, 0);
	return 0;
}