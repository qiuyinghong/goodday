#include<stdio.h>
#include<time.h>
#include <stdlib.h>
//��������
int temps[10][100];
//��ȡ���λ����λ�� ��8->1 , 17->2,7832->4 
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
//��������
void radixSort(int arr[],int n){
    //��ÿ��Ͱ�����ĸ���
    int countIndex[10] = {0};
    int exps = getMexExp(arr,n);
    int exp = 1;
    for(int e=0;e<exps;++e){
        //��Ͱ
        for(int i=0;i<n;++i){
            int index = (arr[i]/exp)%10;
            temps[index][countIndex[index]++] = arr[i];
        }

        //ȡֵ���ı�����
        int k=0;
        for(int g=0;g<10;++g){
            //���Ͱ�����ĸ�������0
            if(countIndex[g]>0){
                int n  = countIndex[g];
                //����ȡ�����ı�����
                for(int j =0;j<n;++j){
                    arr[k++] = temps[g][j];
                }
            }

        }
        //��Ͱ�е����ĸ�������Ϊ0
        for(int f=0;f<10;++f)
            countIndex[f] = 0;
        //λ���ı�
        exp *=10;
    }

}
int main()
{ int N;
  printf("������Ҫ�����������");
  scanf("%d",&N);
clock_t start3=clock();
  for(int e=0;e<N;++e)
  { 
	  int arr[100];
	for(int a=0;a<100;a++)
		arr[a]=rand()%10;
        radixSort(arr,100);

  }clock_t diff3=clock()-start3;
  printf("��������%dms",diff3);
  printf("\n");



return 0;
}