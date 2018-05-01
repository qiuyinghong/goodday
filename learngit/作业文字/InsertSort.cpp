#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000000

/*插入排序*/  
;void InsertSort(int R[],int n)  
{  
    int i,j,tmp;  
    for(i=2;i<=n;i++)  
    {  
        tmp=R[i];  
        j=i-1;  
        while(j>=1 && R[j]>tmp)  
        {  
            R[j+1]=R[j];  
            j--;  
        }  
        R[j+1]=tmp;  
    }  
}   
int main()
{ int N;
  printf("请输入要求的数据量：");
  scanf("%d",&N);
  clock_t start=clock();
  for(int i=0;i<N;++i)
  { 
	  int arr[100];
	for(int a=0;a<100;a++)
		arr[a]=rand()%10;
        InsertSort(arr,100);

  }clock_t diff=clock()-start;
  printf("插入排序%dms",diff);
  printf("\n");
  return 0;}
