#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include<stack.h>  
const int MAXSIZE = 100;  

  
int    table[] = {0,0,2,1,0,1,0,2};//��ѯ��������ȼ���  
  
//����˵��������׺���ʽת��Ϊ��׺���ʽ  
//����˵����  
//sta��    ת��������ʹ�õ�ջ�ռ�  
//infix��  ��ת������׺���ʽ  
//suffix�� �洢ת����ĺ�׺���ʽ  
//length�� ��¼��׺���ʽ�ĳ���  
void infix_to_suffix(Stack *sta, char *infix, int *suffix, int *length);  
  
//����˵��������׺���ʽת��Ϊ���ֱ�ӷ���  
//����˵����  
//sta��    ת��������ʹ�õ�ջ�ռ�  
//suffix�� �洢ת����ĺ�׺���ʽ  
//length�� ��¼��׺���ʽ�ĳ���  
int  suffix_to_result(Stack *sta, int *suffix, int length);  
  
  
int main()  
{  
    //���ｫ��׼����������ض����ļ���  
//  freopen("in.txt", "r", stdin);  
//  freopen("out.txt", "w", stdout);  
    Stack     sta;  
    int       length;  
    int       result;         //���ܺ�׺���ʽת���Ľ��  
    int       sstr[MAXSIZE];  //�洢��׺���ʽ  
    char      istr[MAXSIZE];  //�洢��׺���ʽ  
  
    printf("�������� + - * / ��ɵ���������\n��ע�⸺����Ҫ��������������ţ�\n");  
    scanf("%s", istr);  
  
    init(&sta); //��ջ�ռ��ʼ��  
    infix_to_suffix(&sta, istr, sstr, &length);  
    init(&sta); //�ٴζ�ջ�ռ��ʼ��  
    result = suffix_to_result(&sta, sstr, length);  
  
    printf("%d\n", result);    
    return    0;  
}  
  
  
void infix_to_suffix(Stack *sta, char *infix, int *suffix, int *length)  
{  
    int    i;               //ѭ������  
    int    b = 0;           //��������ʮλ�����ϵ�ʱ����м�¼  
    int    j = 0;           //suffix������±�  
    int    priority = 0;    //��¼ջ��Ԫ�ص����ȼ�  
  
    //forѭ���ĵ������ʽ������i++���������ÿһ�ε�ѹջ���ֱ�������suffix����i++  
    for (i = 0; i < strlen(infix); )  
    {  
        //��������ֵĻ���ֱ�ӷ���suffix��,Ȼ��continue  
        if (infix[i] >= '0' && infix[i] <= '9')  
        {  
            b = 0;      //����ÿ�ζ������¸�ֵΪ�㣡  
  
            while (infix[i] >= '0' && infix[i] <= '9')  
            {  
                b = b * 10 + (infix[i] - '0');  
                i++;  
            }  
            suffix[j] = b;  
            j++;  
            continue;  
        }  
  
        //����������ŵĻ�����ջ�������������ϵ��������������,Ȼ��continue  
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
            //��ջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼����  
            priority = table[sta->data[sta->top] % 10];  
            i++;  
            continue;  
        }  
  
        //����������ŵĻ���ֱ��ѹջ  
        if (infix[i] == 40)  
        {  
            sta->top++;  
            sta->data[sta->top] = infix[i];  
            //ѹջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼����  
            priority = table[sta->data[sta->top] % 10];  
            i++;  
            continue;  
        }  
  
        //���ֻ����ͨ�����������ѹջ  
        if (infix[i] >= 42 && infix[i] <= 47)  
        {  
            //���ȱȽ�ջ��Ԫ�ص����ȼ��Ƿ����ջԪ�����ȼ�Ҫ��  
            //����Ǵ��ڵĻ������ջ����Ԫ�����γ�ջ�󣬰Ѵ���ջ��Ԫ��ѹջ  
            if (priority >= table[infix[i] % 10])  
            {  
                while (priority >= table[infix[i] % 10] && sta->data[sta->top] != 40)  
                {  
                    suffix[j] = sta->data[sta->top];  
                    sta->data[sta->top] = 0;  
                    sta->top--;  
                    //ע��ÿ�εĳ�ջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼���������Ƚ�  
                    priority = table[sta->data[sta->top] % 10];  
                    j++;  
                }  
                sta->top++;  
                sta->data[sta->top] = infix[i];  
                //ע��ѹջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼����  
                priority = table[sta->data[sta->top] % 10];  
                i++;  
            }  
            else   
            {  
                //������Ҫ����������ȡ  
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
                //ע��ѹջ���뽫�µ�ջ��Ԫ�ص����ȼ���¼����  
                priority = table[sta->data[sta->top] % 10];  
                  
                i++;  
            }  
  
        }  
    }  
    //��ջ�л����ڵ�Ԫ�ؽ��е���  
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
        //ѭ��������׺���ʽ�����־�ֱ��ѹջ���������ȡջ������Ԫ�س������㣬�������ѹջ  
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