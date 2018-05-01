#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define MAX 100000000
//计数排序
void CountSort(int data[],int n)
{
     int i,j,count,*data_p,temp;
    data_p=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)//初始化data_p
        data_p[i]=0;
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=0;j<n;j++)//扫描待排序数组
            if(data[j]<data[i])//统计比data[i]值小的值的个数
                count++;
        if(data_p[count]!=0)//对于相等非0的数据，应向后措一位。数据为0时，因数组data_p被初始化为0，故不受影响。
            count++;
        data_p[count]=data[i];//存放到data_p中的对应位置
    }
        //用于检查当有多个数相同时的情况
    i=0,j=n;
    while(i<j)
        {
        if(data_p[i]==0)
                {
            temp=i-1;
            data_p[i]=data_p[temp];
        }//of if
        i++;
    }//of  while
    for(i=0;i<n;i++)//把排序完的数据复制到data中
        data[i]=data_p[i];
    free(data_p);//释放data_p
}
//判断是否排序
bool isSorted(int arr[],int n){
    bool flag = true;
    for(int i=0;i<n-1;++i){
        if(arr[i+1]<arr[i]){
            flag = false;
            break;
        }
    }
    return flag;
}

int arr[N];

int main()
{
    srand((unsigned)time(NULL));
    for(int i =0;i < N;++i ){
        arr[i] =  rand()% MAX;
    }


    clock_t start_time=clock();
    {
        CountSort(arr,N);
    }

   clock_t end_time=clock();
    printf("Running time is: %lfms\n",static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000);
    printf("%s",isSorted(arr,N) == true ? "true":"false");
    printf("\n");
//    for(int i=0;i<N;++i){
//       printf("%d ",arr[i]);
//    }
    return 0;
}