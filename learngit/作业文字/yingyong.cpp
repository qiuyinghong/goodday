#include<stdio.h>
#include <algorithm>
using namespace std;

int main(){ 
    int arr[7] = {0,1,2,1,2,0,2};
    int pos0=0, pos2=6, pcur=0;
    while(0 == arr[pos0])
        ++pos0;
    while(2 == arr[pos2])
        --pos2;
    pcur = pos0;
    while(pcur <= pos2){        
        if(0 == arr[pcur]){
            swap(arr[pcur], arr[pos0]);
            ++pos0;
        }
        else if(2 == arr[pcur]){            
            swap(arr[pcur], arr[pos2]);
            if(0 == arr[pcur]){//������֮��pcur��ǰָ���Ԫ��Ϊ0���������pcurָ���Ԫ�غ�pos0ָ���Ԫ�ؽ��н���
                swap(arr[pcur], arr[pos0]); 
                ++pos0;//����֮�󣬽�pos0��ǰ�ƶ�һλ
            }           
            --pos2;//pos2����ƶ�һλ
            while(arr[pos2] == 2)//���ƶ�֮��ָ���Ԫ�ػ���2���������ǰ�ƶ���ֱ��ָ���һ����2��Ԫ��
                --pos2;
        }   
        ++pcur;}
 	for(int i=0;i<7;i++)
printf("%d",arr[i]);
	return 0;
	
	}   




	
