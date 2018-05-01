#include<stdio.h>
#include<time.h>
#include <stdlib.h>

//辅助数组
 int temp[100];
//-----------------------
void combineArr(int arrL[],int ln,int arrR[],int rn){

    int i = 0;
    int j = 0;
    int k=0;
    while(i<ln&&j<rn){

        if(arrL[i]<=arrR[j]){
            temp[k++] = arrL[i++];
        }else{
            temp[k++] = arrR[j++];
        }
    }
    while(i<ln){
        temp[k++] = arrL[i++];
    }

    while(j<rn){
        temp[k++] = arrR[j++];
    }

    for(int d = 0;d<k;++d){
        arrL[d] = temp[d];
    }
}


void conflationSort(int arr[],int l,int r){

    if(r>l){
        int mid = (l+r)/2;
        conflationSort(arr,l,mid);
        conflationSort(arr,mid+1,r);
        combineArr(&arr[l],mid-l+1,&arr[mid+1],r-mid);
    }
}
int main()
{ int N;
  printf("请输入要求的数据量：");
  scanf("%d",&N);
clock_t start2=clock();
  for(int c=0;c<N;++c)
  { 
	  int arr[100];
	for(int a=0;a<100;a++)
		arr[a]=rand()%10;
        conflationSort(arr,0,99);
  }clock_t diff2=clock()-start2;
  printf("合并排序%dms",diff2);
  printf("\n");
  return 0;}