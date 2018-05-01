#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector> 
#include<iostream>
#include<time.h>
#include<stack>
#include<cstdlib>
#include<algorithm>

#define N 10000
#define MAX 100000000
using namespace std
#define MAXNUM 10;


/*��������*/  
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

/*�鲢����*/  
int tmp[],R[];  
int ans=0;//˳����������   
void Merge(int l,int m,int r)  
{  
    int i=l;  
    int j=m+1;  
    int k=l;  
      
    while(i<=m && j<=r)  
    {  
        if(R[i]>R[j])  
        {  
            tmp[k++]=R[j++];  
            ans+= m-i+l;      
        }  
        else  
        {  
            tmp[k++]=R[i++];      
        }     
    }  
    while(i<=m)  
        tmp[k++]=R[i++];  
    while(j<=r)  
        tmp[k++]=R[j++];  
    for(i=l;i<=r;i++)  
    {  
        R[i]=tmp[i];      
    }     
}  
  
void MergeSort(int l,int r)  
{  
    if(l<r)  
    {  
        int m=(l+r)>>1;  
        MergeSort(l,m);  
        MergeSort(m+1,r);  
        Merge(l,m,r);     
    }     
}   



/*��������ݹ�*/  
void QuickSort(int R[],int l,int r)  
{  
    int i,j,tmp;  
    i=l;  
    j=r;  
    if(i<j)  
    {  
        tmp=R[l];  
        while(i!=j)  
        {  
            while(i<j && R[j]>tmp) --j;  
            if(i<j)  
            {  
                R[i]=R[j];  
                ++i;      
            }  
            while(i<j && R[i]<tmp) ++i;  
            if(i<j)  
            {  
                R[j]=R[i];  
                --j;      
            }     
        }  
        R[i]=tmp;  
        QuickSort(R,l,i-1);  
        QuickSort(R,i+1,r);  
    }  
}   

/**ʹ��ջ�ķǵݹ��������**/
template<typename Comparable>
void quicksort2(vector<Comparable> &vec,int low,int high){
    stack<int> st;
    if(low<high){
        int mid=partition(vec,low,high);
        if(low<mid-1){
            st.push(low);
            st.push(mid-1);
        }
        if(mid+1<high){
            st.push(mid+1);
            st.push(high);
        }
        //��ʵ������ջ����ÿһ���������Ӵ�����βԪ���±꣬��һ��whileѭ��ʱȡ�������Χ������������н���partition����
        while(!st.empty()){
            int q=st.top();
            st.pop();
            int p=st.top();
            st.pop();
            mid=partition(vec,p,q);
            if(p<mid-1){
                st.push(p);
                st.push(mid-1);
            }
            if(mid+1<q){
                st.push(mid+1);
                st.push(q);
            }       
        }
    }
}






/*   �������� */

int GetNumInPos(int num,int pos)  
{  
    int temp = 1;  
    for (int i = 0; i < pos - 1; i++)  
        temp *= 10;  
  
    return (num / temp) % 10;  
}  
   
#define RADIX_10 10    //��������  
#define KEYNUM_31 10     //�ؼ��ָ���������Ϊ����λ��  
void RadixSort(int* pDataArray, int iDataNum)  
{  
    int *radixArrays[RADIX_10];    //�ֱ�Ϊ0~9�����пռ�  
    for (int i = 0; i < 10; i++)  
    {  
        radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));  
        radixArrays[i][0] = 0;    //indexΪ0����¼�������ݵĸ���  
    }  
      
    for (int pos = 1; pos <= KEYNUM_31; pos++)    //�Ӹ�λ��ʼ��31λ  
    {  
        for (int i = 0; i < iDataNum; i++)    //�������  
        {  
            int num = GetNumInPos(pDataArray[i], pos);  
            int index = ++radixArrays[num][0];  
            radixArrays[num][index] = pDataArray[i];  
        }  
  
        for (int a = 0, j =0; a < RADIX_10; i++)    //�ռ�  
        {  
            for (int k = 1; k <= radixArrays[a][0]; k++)  
                pDataArray[j++] = radixArrays[a][k];  
            radixArrays[a][0] = 0;    //��λ  
        }  
    }  
}  

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




int main(){
  return 0;
}



