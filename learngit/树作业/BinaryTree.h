#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

typedef struct TreeNode{
  char data;
  struct TreeNode *lchild;
  struct TreeNode *rchild;
}TREENODE;

int NodeNum=0;
int LeafNum=0;
char ch[]={'a','b','c','d','e','f',' ',' ','g'};
int inc=0;

int CreateBiTree(TREENODE **T)
{
  char i;
  if(ch[inc++]==' ')
	  *T=NULL;
  else
  {
   printf("%c\n",ch[inc-1]);
   if(!(*T = (TREENODE *)malloc(sizeof(TREENODE))))
   return -1;
   (*T)->data=ch[inc-1];
   printf("%c\n",(*T)->data);
   CreateBiTree(&((*T)->lchild));
   CreateBiTree(&((*T)->rchild));
  }
  return 1;
}

int PreOderTraverse(TREENODE *T)
{
if(T)
{
  printf("%c",T->data);
  PreOderTraverse(T->lchild);
  PreOderTraverse(T->rchild);
}
return 1;
}


int InOderTraverse(TREENODE *T)
{
 if(T)
 {
   InOderTraverse(T->lchild);
   printf("%c",T->data);
   InOderTraverse(T->rchild);
 }
 return 1;
}

int BackOderTraverse(TREENODE *T)
{
 if(T)
 {
  BackOderTraverse(T->lchild);
  BackOderTraverse(T->rchild);
  printf("%c",T->data);
 }
 return 1;
}

int value(TREENODE *T)  
{  
    if(T==NULL)  
        return 0;  
    if(T->data <='9'&&T->data >='0')  
        return (T->data-'0');  
    else  
    {  
        switch(T->data)            //因为这一步的T->data必为运算符，则必有左右孩子节点且不空  
        {  
            case'+':  return value(T->lchild) + value(T->rchild); break;  
            case'-':  return value(T->lchild) - value(T->rchild); break;  
            case'*':  return value(T->lchild) * value(T->rchild); break;  
            case'/':  return value(T->lchild) / value(T->rchild); break;  
        }  
    }  
}  

int main()
{
 return 0;
}
