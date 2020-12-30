#include <cstdio>
#define HASHMAP_SIZE 10

struct node{
    int data;
    struct node *next;
};
typedef node dynamic_hashmap[HASHMAP_SIZE];

int hash(int x){
    return x % HASHMAP_SIZE;
}

bool hash_init(dynamic_hashmap &map){
    for(int i=0; i<HASHMAP_SIZE; i++){
        map[i].data = i;
        map[i].next = NULL;
    }
}

bool hash_insert(dynamic_hashmap &map, int src){
    struct node *newNode = new struct node;
    newNode->data=src;
    newNode->next=map[hash(src)].next;
    map[hash(src)].next = newNode;
    return true;
}

bool hash_delete(dynamic_hashmap &map, int src){
    struct node *temp = &map[hash(src)], *todel;
    while(temp->next){
        if(temp->next->data == src){
            todel = temp->next;
            temp->next = todel->next;
            delete todel;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool hash_print(dynamic_hashmap map){
    for(int i=0; i<HASHMAP_SIZE; i++){
        struct node *temp = &map[i];
        printf("%d", temp->data);
        while(temp->next){
            printf("->%d", temp->next->data);
            temp = temp->next;
        }
        printf("^\n");
    }
}

int main(){
    int n, todo;
    scanf("%d", &n);
    dynamic_hashmap hashMap;
    hash_init(hashMap);
    for(int i=0; i<n; i++){
        scanf("%d", &todo);
        hash_insert(hashMap, todo);
    }
    scanf("%d", &todo);
    hash_delete(hashMap, todo);
    scanf("%d", &todo);
    hash_insert(hashMap, todo);
    hash_print(hashMap);
    return 0;
}
