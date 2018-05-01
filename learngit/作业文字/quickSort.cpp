#include<stdio.h>
#include<time.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end){

    swap(&arr[start],&arr[end]);
    int value = arr[end];
    int index = start;
    for(int i=start;i<end;++i){
        if(arr[i]< value){
            swap(&arr[index++],&arr[i]);
        }
    }
    swap(&arr[index],&arr[end]);
    return index;
}

void quickSort(int arr[],int start,int end){

    if(end>start){
        int index = partition(arr,start,end);
        quickSort(arr, start,index-1);
        quickSort(arr, index+1,end);
    }

}

int main()
{ int N;
  printf("请输入要求的数据量：");
  scanf("%d",&N);
clock_t start1=clock();
  for(int b=0;b<N;++b)
  { 
	  int arr[100];
	for(int a=0;a<100;a++)
		arr[a]=rand()%10;
        quickSort(arr,0,99);

  }clock_t diff1=clock()-start1;
  printf("快速排序%dms",diff1);
  printf("\n");
  return 0;}