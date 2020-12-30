#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 101

struct node{
    int index, weight;
    struct node *next;
};
typedef struct{
    int data;
    struct node *firstarc;
}Table;

int main(){
	int n, m, ans=0, count=0;
	scanf("%d %d", &n, &m);
	Table table[MAXN] = {0};
	int indegree[MAXN] = {0};
    int ve[MAXN] = {0}, vl[MAXN];
	std::stack<int> topsort;
	int keypoint[MAXN], keynum=0;
	for(int i=0; i<MAXN; i++)
		table[i].firstarc = NULL;
	for(int i=1, p, q, r; i<=m; i++){
        scanf("%d %d %d", &p, &q, &r);
        table[i].data = i;
        struct node *ins = new struct node;
		ins->index = q;
		ins->weight = r;
		ins->next = table[p].firstarc;
		table[p].firstarc = ins;
		indegree[q]++;
	}
	while(true){
        bool flag = false;
        for(int i=1; i<=n; i++){
            if(indegree[i] == 0){
                indegree[i] = -1;
                flag = true;
                count++;
                topsort.push(i);
                for(struct node *temp = table[i].firstarc; temp; temp = temp->next){
                    if(temp->weight >= 0){
                        indegree[temp->index]--;
                        if(ve[i] + temp->weight > ve[temp->index]) ve[temp->index] = ve[i] + temp->weight;
                        if(ans < ve[temp->index]) ans = ve[temp->index];
                    }
                }
            }
        }
        if(!flag) break;
	}
	if(count == n){
        printf("%d\n", ans);
        int max = ve[0];
        for(int i=0; i<MAXN; i++)
        	if(max < ve[i]) max = ve[i];
		for(int i=0; i<MAXN; i++)
			vl[i] = max;
        while(!topsort.empty()){
            int i = topsort.top();
            topsort.pop();
            for(struct node *temp = table[i].firstarc; temp; temp = temp->next){
                if(temp->weight >= 0){
                    if(vl[i] > vl[temp->index] - temp->weight)
                        vl[i] = vl[temp->index] - temp->weight;
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(struct node *temp = table[i].firstarc; temp; temp = temp->next){
                if(temp->weight >= 0){
                    int ee = ve[i], el = vl[temp->index] - temp->weight;
                	if(ee == el)
						printf("%d->%d\n", i, temp->index);
                }
            }
        }
	}else{
        printf("0");
	}
	return 0;
}
