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
            if(0 == arr[pcur]){//若交换之后，pcur当前指向的元素为0，则继续将pcur指向的元素和pos0指向的元素进行交换
                swap(arr[pcur], arr[pos0]); 
                ++pos0;//交换之后，将pos0向前移动一位
            }           
            --pos2;//pos2向后移动一位
            while(arr[pos2] == 2)//若移动之后指向的元素还是2，则继续向前移动，直到指向第一个非2的元素
                --pos2;
        }   
        ++pcur;}
 	for(int i=0;i<7;i++)
printf("%d",arr[i]);
	return 0;
	
	}   




	
