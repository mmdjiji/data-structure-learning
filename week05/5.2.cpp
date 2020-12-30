#include <cstdio>
#include <stack> 

typedef struct {
	int x, y, v;
} pos;

int main(){
	bool flag = false;
	int m, n;
	pos entrance, exit;
	std::stack<pos> maze;
	
	int map[20][20];
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
			map[i][j] = 1;
	scanf("%d %d", &m, &n);
	scanf("%d %d", &entrance.x, &entrance.y);
	scanf("%d %d", &exit.x, &exit.y);
	
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			scanf("%d", &map[i][j]);
	
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
			if(map[i][j] == 1) map[i][j] = -1;
	
	pos curpos = entrance;
	int curstep = 1;
	do{
		if(map[curpos.x][curpos.y] == 0){
			map[curpos.x][curpos.y] = curstep++;
			pos e = curpos;
			e.v = 1;
			maze.push(e);
			if(curpos.x == exit.x && curpos.y == exit.y){
				flag = true;
				break;
			}
			curpos.y++;
			curpos.v = 1;
		}else{
			if(!maze.empty()){
				pos e = maze.top();
				maze.pop();
				while(e.v == 4 && !maze.empty()){
					map[e.x][e.y] = -1;
					e = maze.top();
					maze.pop();
					curstep--;
				}
				if(e.v < 4){
					e.v++;
					maze.push(e);
					if(e.v == 2){
						e.x++;
					}else if(e.v == 3){
						e.y--;
					}else if(e.v == 4){
						e.x--;
					}
					curpos = e;
				}
			}
		}
	}while(!maze.empty());
	
	if(flag){
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++)
				printf("%3d", (map[i][j]==-1)?0:map[i][j]);
			printf("\n");
		}
	}else{
		printf("NO");
	}
	
	return 0;
}
