#include<stdio.h>
#include<time.h>
#include <stdlib.h>
//辅助数组
int temps[10][100];
//获取最大位数的位置 如8->1 , 17->2,7832->4 
int getMexExp(int arr[],int n){

    int maxN = arr[0];
    for(int i=1;i<n;++i){
        maxN = arr[i]>maxN?arr[i]:maxN;
    }
    int exps = 1;
    maxN = maxN/10;
    while(maxN!=0){
        maxN = maxN/10;
        exps++;
    }
    return exps;
}
//基数排序
void radixSort(int arr[],int n){
    //存每个桶中数的个数
    int countIndex[10] = {0};
    int exps = getMexExp(arr,n);
    int exp = 1;
    for(int e=0;e<exps;++e){
        //入桶
        for(int i=0;i<n;++i){
            int index = (arr[i]/exp)%10;
            temps[index][countIndex[index]++] = arr[i];
        }

        //取值，改变数组
        int k=0;
        for(int g=0;g<10;++g){
            //如果桶中数的个数大于0
            if(countIndex[g]>0){
                int n  = countIndex[g];
                //将数取出，改变数组
                for(int j =0;j<n;++j){
                    arr[k++] = temps[g][j];
                }
            }

        }
        //将桶中的数的个数重置为0
        for(int f=0;f<10;++f)
            countIndex[f] = 0;
        //位数改变
        exp *=10;
    }

}
int main()
{ int N;
  printf("请输入要求的数据量：");
  scanf("%d",&N);
clock_t start3=clock();
  for(int e=0;e<N;++e)
  { 
	  int arr[100];
	for(int a=0;a<100;a++)
		arr[a]=rand()%10;
        radixSort(arr,100);

  }clock_t diff3=clock()-start3;
  printf("基数排序%dms",diff3);
  printf("\n");



return 0;
}