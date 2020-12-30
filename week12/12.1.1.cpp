#include <stdio.h>
#include <stdlib.h>

#define OK (1)
#define ERROR (-1)
typedef int Status;
typedef struct ch
{ char zifu;  //�ַ�
  int count;   //����
}TElemType;

//- - - - -�������Ķ�������洢��ʾ- - - - -
typedef  struct  BiTNode
{  TElemType     data;              //��Ҫ���� TElemType, Ϊchar����
   struct BiTNode  *lchild, *rchild;   //���Һ���ָ��
} BiTNode, *BiTree;

/* ����������д�� */
Status InsertBiTree(BiTree &T,char ch){
    if(T){
        if(T->data.zifu == ch){
            T->data.count++;
        }else{
            if(T->data.zifu > ch){
                InsertBiTree(T->lchild, ch);
            }else{
                InsertBiTree(T->rchild, ch);
            }
        }
    }else{
        T = new BiTNode;
        T->lchild = T->rchild = NULL;
        T->data.zifu = ch;
        T->data.count = 1;
    }
    return OK;
}

Status InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);
        printf("%c:%d\n", T->data.zifu, T->data.count);
        InOrderTraverse(T->rchild);
        return OK;
    }
    return ERROR;
}

int main( )
{ BiTree tree=NULL;
  int i;
  char s[100];
  scanf("%s",s);
  for(i=0; s[i]; i++)
     InsertBiTree(tree,s[i]);
  InOrderTraverse(tree);
  return 0;
}
