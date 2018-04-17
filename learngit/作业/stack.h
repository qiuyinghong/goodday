#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTBLE -1
#define OVERFLOW -2
#define STACK_INIT 100
#define STACKINCREMENT 10
#define size 10
typedef int ElemType;
typedef int Status;

typedef struct
{
  ElemType *base;
  ElemType *top;
  int stacksize;

}SqStack;


Status InitStack(SqStack &S)
{ 
  S.base = (ElemType*)malloc(size *sizeof(ElemType));
  if (!S.base)
	  exit(OVERFLOW);
  S.top=S.base;
  S.stacksize=size;
  return OK;
}

Status DestroyStack(SqStack &S)
{
  S.top=NULL;
  S.stacksize=0;
  free(S.base);
  return OK;

}

Status ClearStack(SqStack &S)
{
  S.top=S.base;
  return OK;

}

Status StackEmpty(SqStack S)
{ 
	if (S.top==S.base)
		return ERROR;
	else return TRUE;
}

Status StackLength(SqStack S)
{
  if (S.top==S.base)
	  return FALSE;
  else 
	  return(S.top-S.base);

}

Status GetTop(SqStack S,ElemType &e)
{
  if (S.top==S.base)
	  return FALSE;
  else 
	  e=*(S.top-1);
  return e;
}

Status Push(SqStack &S,ElemType &e)
{
  if(S.top-S.base>=size)
  {
     S.base=(ElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
	 if (!S.base)
	 {
	    return false;
	 }
	 S.top=S.base+size;
	 S.stacksize=S.stacksize+STACKINCREMENT;
  }
  *S.top=e;
  S.top++;
  return OK;

}

Status Pop(SqStack &S,ElemType &e)
{
  if(S.top==S.base)
	  return ERROR;
  else
  {
     S.top--;
	 e=*S.top;
	 return e;
  }
}

Status StackTraverse(SqStack S)
{
  if(S.base==NULL)
	  return ERROR;
  if(S.top==S.base)
	  printf("this is nothing");
  ElemType *p;
  p=S.top;
  while (p>S.base)
  {
  p--;
  printf("%d",*p);
  }
  return OK;
}

int main()
{
  SqStack S;
  printf("make a zhan\n");
  InitStack(S);
  int i,n;
  printf("input the length\n");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    printf("shu ru zhan de di%d ge yuansu\n",i);
	++S.top;
	scanf("%d",S.top-1);
  }
  printf("is it a empty zhan??\n");
  if(StackEmpty(S)==1)
	  printf("No\n");
  else 
	  printf("YES\n");
  printf("qiu chu zhan de changdu\n");
  int m;
  m=StackLength(S);
  printf("the length is:\n ");
  StackTraverse(S);
  printf("\n");
  printf("input the top:\n");
  int e;
  e=GetTop(S,e);
  printf("the top is:\n");
  printf("%d\n",e);
  printf("zhan ding cha ru yuan su\n");
  printf("qing shu ru yao cha ru de yuan su zhi:\n");
  scanf("%d",&e);
  Push(S,e);
  printf("xian zai zhan de yuan su shi:\n");
  StackTraverse(S);
  printf("\n");
	  printf("zhan ding shan chu yuan su\n");
  e=Pop(S,e);
	  printf("bei shan chu de yuan su shi :\n");
  scanf("%d",&e);
  printf("xian zai zhan de yuan su shi \n");
  StackTraverse(S);
  printf("\n");
  printf("qing kong zhan:\n");
  ClearStack(S);
  printf("xian zai de yuan su shi:\n");
  StackTraverse(S);
  printf("xiao hui zhan:\n");
  if(DestroyStack(S)==1)
	  printf("xiao hui cheng gong\n");
  else
	  printf("xiao hui shi bei\n");
  return 0;

}