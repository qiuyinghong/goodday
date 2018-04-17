#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include<stack.h>  
const int MAXSIZE = 100;  

  
int    table[] = {0,0,2,1,0,1,0,2};//查询运算符优先级表  
  
//函数说明：将中缀表达式转换为后缀表达式  
//参数说明：  
//sta：    转换过程需使用的栈空间  
//infix：  待转换的中缀表达式  
//suffix： 存储转换后的后缀表达式  
//length： 记录后缀表达式的长度  
void infix_to_suffix(Stack *sta, char *infix, int *suffix, int *length);  
  
//函数说明：将后缀表达式转换为结果直接返回  
//参数说明：  
//sta：    转换过程需使用的栈空间  
//suffix： 存储转换后的后缀表达式  
//length： 记录后缀表达式的长度  
int  suffix_to_result(Stack *sta, int *suffix, int length);  
  
  
int main()  
{  
    //这里将标准输入输出流重定向到文件中  
//  freopen("in.txt", "r", stdin);  
//  freopen("out.txt", "w", stdout);  
    Stack     sta;  
    int       length;  
    int       result;         //接受后缀表达式转换的结果  
    int       sstr[MAXSIZE];  //存储后缀表达式  
    char      istr[MAXSIZE];  //存储中缀表达式  
  
    printf("请输入以 + - * / 组成的四则运算\n（注意负数需要在两旁添加上括号）\n");  
    scanf("%s", istr);  
  
    init(&sta); //对栈空间初始化  
    infix_to_suffix(&sta, istr, sstr, &length);  
    init(&sta); //再次对栈空间初始化  
    result = suffix_to_result(&sta, sstr, length);  
  
    printf("%d\n", result);    
    return    0;  
}  
  
  
void infix_to_suffix(Stack *sta, char *infix, int *suffix, int *length)  
{  
    int    i;               //循环变量  
    int    b = 0;           //当数字是十位或以上的时候进行记录  
    int    j = 0;           //suffix数组的下标  
    int    priority = 0;    //记录栈顶元素的优先级  
  
    //for循环的第三表达式不进行i++，将其放在每一次的压栈后或直接输出到suffix进行i++  
    for (i = 0; i < strlen(infix); )  
    {  
        //如果是数字的话，直接放在suffix中,然后continue  
        if (infix[i] >= '0' && infix[i] <= '9')  
        {  
            b = 0;      //谨记每次都需重新赋值为零！  
  
            while (infix[i] >= '0' && infix[i] <= '9')  
            {  
                b = b * 10 + (infix[i] - '0');  
                i++;  
            }  
            suffix[j] = b;  
            j++;  
            continue;  
        }  
  
        //如果是右括号的话，将栈中在左括号以上的所有运算符弹出,然后continue  
        if (infix[i] == 41)  
        {  
            while (sta->data[sta->top] != 40)  
            {  
                suffix[j] = sta->data[sta->top];  
                sta->data[sta->top] = 0;  
                sta->top--;  
                j++;  
            }  
            sta->data[sta->top] = 0;  
            sta->top--;  
            //出栈后，须将新的栈顶元素的优先级记录下来  
            priority = table[sta->data[sta->top] % 10];  
            i++;  
            continue;  
        }  
  
        //如果是左括号的话，直接压栈  
        if (infix[i] == 40)  
        {  
            sta->top++;  
            sta->data[sta->top] = infix[i];  
            //压栈后，须将新的栈顶元素的优先级记录下来  
            priority = table[sta->data[sta->top] % 10];  
            i++;  
            continue;  
        }  
  
        //如果只是普通的运算符，则压栈  
        if (infix[i] >= 42 && infix[i] <= 47)  
        {  
            //首先比较栈顶元素的优先级是否比入栈元素优先级要大  
            //如果是大于的话，则从栈顶将元素依次出栈后，把待入栈的元素压栈  
            if (priority >= table[infix[i] % 10])  
            {  
                while (priority >= table[infix[i] % 10] && sta->data[sta->top] != 40)  
                {  
                    suffix[j] = sta->data[sta->top];  
                    sta->data[sta->top] = 0;  
                    sta->top--;  
                    //注意每次的出栈后，须将新的栈顶元素的优先级记录下来用作比较  
                    priority = table[sta->data[sta->top] % 10];  
                    j++;  
                }  
                sta->top++;  
                sta->data[sta->top] = infix[i];  
                //注意压栈后，须将新的栈顶元素的优先级记录下来  
                priority = table[sta->data[sta->top] % 10];  
                i++;  
            }  
            else   
            {  
                //这里主要处理负数的提取  
                if (infix[i] == 45 && sta->data[sta->top] == 40)  
                {  
                    b = 0;  
                    while (infix[i+1] >= '0' && infix[i+1] <= '9')  
                    {  
                        b = b * 10 + (infix[i+1] - '0');  
                        i++;  
                    }  
                    suffix[j] = b * -1;  
                    sta->data[sta->top] = 0;  
                    sta->top--;  
                    j++;  
                    i += 2;  
                    priority = table[sta->data[sta->top] % 10];  
                    continue;  
                }  
                sta->top++;  
                sta->data[sta->top] = infix[i];  
                //注意压栈后，须将新的栈顶元素的优先级记录下来  
                priority = table[sta->data[sta->top] % 10];  
                  
                i++;  
            }  
  
        }  
    }  
    //把栈中还存在的元素进行弹出  
    while (sta->top != -1)  
    {  
        suffix[j] = sta->data[sta->top];  
        sta->top--;  
        j++;  
    }  
    *length = j;  
}  
  
  
int suffix_to_result(Stack *sta, int *suffix, int length)  
{  
    int    i;  
    int    j;  
    int    result = 0;  
  
    for (i = 0; i < length; i++)  
    {  
        //循环遍历后缀表达式，数字就直接压栈，运算符就取栈顶两个元素出来计算，并将结果压栈  
        switch (suffix[i])  
        {  
        case 42:  
            result = sta->data[sta->top - 1] * sta->data[sta->top];  
            sta->top -= 1;  
            sta->data[sta->top] = result;  
            break;  
        case 43:  
            result = sta->data[sta->top - 1] + sta->data[sta->top];  
            sta->top -= 1;  
            sta->data[sta->top] = result;  
            break;  
        case 45:  
            result = sta->data[sta->top - 1] - sta->data[sta->top];  
            sta->top -= 1;  
            sta->data[sta->top] = result;  
            break;  
        case 47:  
            result = sta->data[sta->top - 1] / sta->data[sta->top];  
            sta->top -= 1;  
            sta->data[sta->top] = result;  
            break;  
        default:  
            sta->top++;  
            sta->data[sta->top] = suffix[i];  
            break;  
        }  
    }  
    return   result;  
}  