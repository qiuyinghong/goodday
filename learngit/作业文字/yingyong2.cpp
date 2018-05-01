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
  
    printf("请输入数组元素的个数：");  
    scanf("%d",&number);  
    a = (double *)malloc(number*sizeof(double));  
  
    printf("请输入%d个数组元素的值：\n",number);  
    for(i = 0;i < number;i++)  
    {  
        printf("请输入第%d个数组元素：",i);  
        fflush(stdin);  
        scanf("%lf",a+i);  
    }  
  
    printf("请输入您需要查找的第几个最大的数：");  
    scanf("%d",&k);  
  
    selectkmax(a,number,k);  
    return 0;  
}  
  
int selectkmax(double a[],int n,int k)  
{  
    sqencing(a,n);  
    printf("数组元素中第%d大的元素是：%4.2f",k,a[k - 1]);  
  
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