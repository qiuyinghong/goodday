#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define MAX 100000000
//��������
void CountSort(int data[],int n)
{
     int i,j,count,*data_p,temp;
    data_p=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)//��ʼ��data_p
        data_p[i]=0;
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=0;j<n;j++)//ɨ�����������
            if(data[j]<data[i])//ͳ�Ʊ�data[i]ֵС��ֵ�ĸ���
                count++;
        if(data_p[count]!=0)//������ȷ�0�����ݣ�Ӧ����һλ������Ϊ0ʱ��������data_p����ʼ��Ϊ0���ʲ���Ӱ�졣
            count++;
        data_p[count]=data[i];//��ŵ�data_p�еĶ�Ӧλ��
    }
        //���ڼ�鵱�ж������ͬʱ�����
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
    for(i=0;i<n;i++)//������������ݸ��Ƶ�data��
        data[i]=data_p[i];
    free(data_p);//�ͷ�data_p
}
//�ж��Ƿ�����
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