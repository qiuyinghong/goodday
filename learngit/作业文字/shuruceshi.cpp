#include<stdio.h>
#include<time.h>
#include <stdlib.h>
void insertSort(int arr[], int len)
{
    int i, j, key;
    for(i = 1; i < len; ++i){
        key = arr[i];
        for(j = i-1; j >=0; --j){
            if(arr[j] > key)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = key;
    }
}


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


//��������
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
  clock_t start=clock();
  for(int i=0;i<N;++i)
  { 
	  int arr[100];
	for(int a=0;a<100;a++)
		arr[a]=rand()%10;
        insertSort(arr,100);

  }clock_t diff=clock()-start;
  printf("��������%dms",diff);
  printf("\n");
  
  clock_t start1=clock();
  for(int b=0;b<N;++b)
  { 
	  int arr[100];
	for(int a=0;a<100;a++)
		arr[a]=rand()%10;
        quickSort(arr,0,99);

  }clock_t diff1=clock()-start1;
  printf("��������%dms",diff1);
  printf("\n");

clock_t start2=clock();
  for(int c=0;c<N;++c)
  { 
	  int arr[100];
	for(int a=0;a<100;a++)
		arr[a]=rand()%10;
        conflationSort(arr,0,99);
  }clock_t diff2=clock()-start2;
  printf("�ϲ�����%dms",diff2);
  printf("\n");

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
