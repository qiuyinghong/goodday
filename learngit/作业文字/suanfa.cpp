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


/*插入排序*/  
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

/*归并排序*/  
int tmp[],R[];  
int ans=0;//顺带求逆序数   
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



/*快速排序递归*/  
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

/**使用栈的非递归快速排序**/
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
        //其实就是用栈保存每一个待排序子串的首尾元素下标，下一次while循环时取出这个范围，对这段子序列进行partition操作
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






/*   基数排序 */

int GetNumInPos(int num,int pos)  
{  
    int temp = 1;  
    for (int i = 0; i < pos - 1; i++)  
        temp *= 10;  
  
    return (num / temp) % 10;  
}  
   
#define RADIX_10 10    //整形排序  
#define KEYNUM_31 10     //关键字个数，这里为整形位数  
void RadixSort(int* pDataArray, int iDataNum)  
{  
    int *radixArrays[RADIX_10];    //分别为0~9的序列空间  
    for (int i = 0; i < 10; i++)  
    {  
        radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));  
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数  
    }  
      
    for (int pos = 1; pos <= KEYNUM_31; pos++)    //从个位开始到31位  
    {  
        for (int i = 0; i < iDataNum; i++)    //分配过程  
        {  
            int num = GetNumInPos(pDataArray[i], pos);  
            int index = ++radixArrays[num][0];  
            radixArrays[num][index] = pDataArray[i];  
        }  
  
        for (int a = 0, j =0; a < RADIX_10; i++)    //收集  
        {  
            for (int k = 1; k <= radixArrays[a][0]; k++)  
                pDataArray[j++] = radixArrays[a][k];  
            radixArrays[a][0] = 0;    //复位  
        }  
    }  
}  

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




int main(){
  return 0;
}



