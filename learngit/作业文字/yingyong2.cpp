#include <stdio.h>  
#include <malloc.h>  
  
void sqencing(double a[],int n);  
int selectkmax(double a[],int n,int k);  
  
int main()  
{  
    int number = 0;  
    int i = 0;  
    int k = 0;  
    double *a = NULL;  
  
    printf("����������Ԫ�صĸ�����");  
    scanf("%d",&number);  
    a = (double *)malloc(number*sizeof(double));  
  
    printf("������%d������Ԫ�ص�ֵ��\n",number);  
    for(i = 0;i < number;i++)  
    {  
        printf("�������%d������Ԫ�أ�",i);  
        fflush(stdin);  
        scanf("%lf",a+i);  
    }  
  
    printf("����������Ҫ���ҵĵڼ�����������");  
    scanf("%d",&k);  
  
    selectkmax(a,number,k);  
    return 0;  
}  
  
int selectkmax(double a[],int n,int k)  
{  
    sqencing(a,n);  
    printf("����Ԫ���е�%d���Ԫ���ǣ�%4.2f",k,a[k - 1]);  
  
    return 0;  
}  
  
void sqencing(double a[],int n)  
{  
    int i = 0;  
    int j = 0;  
    int k = 0;  
    double temp = 0;  
  
    for(i = 0;i < n - 1;i++)  
    {  
        k = i;  
        for(j = i + 1;j < n;j++)  
        {  
            if(a[j] > a[k])  
            {  
                k = j;  
            }  
        }  
        temp = a[k];  
        a[k] = a[i];  
        a[i] = temp;  
    }  
}  