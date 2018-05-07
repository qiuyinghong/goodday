#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
  
typedef struct BTreeNode  
{  
    char data;  
    struct BTreeNode* lchild;  
    struct BTreeNode* rchild;  
} BTNode;  
  
int calcula(BTNode* T)  
{  
    if(T==NULL)  
        return 0;  
    if(T->data <='9'&&T->data >='0')  
        return (T->data-'0');  
    else  
    {  
        switch(T->data)            //��Ϊ��һ����T->data��Ϊ���������������Һ��ӽڵ��Ҳ���  
        {  
            case'+':  return calcula(T->lchild) + calcula(T->rchild); break;  
            case'-':  return calcula(T->lchild) - calcula(T->rchild); break;  
            case'*':  return calcula(T->lchild) * calcula(T->rchild); break;  
            case'/':  return calcula(T->lchild) / calcula(T->rchild); break;  
        }  
    }  
}  
  
char* input_cheak_str()            //�ַ�����̬�������⺯��  
{  
    printf("������һ�����������ʽ(һλ��������ֻ��+-*/������,����ո����):\n");  
    int ch_num=0;  
    char ch,*str;  
    str=(char*)malloc(sizeof(char));  
    while((ch=getchar())!='\n')    //���ð��������ַ����仯���ַ�����(�ڴ��㹻�������鳤��Ӱ��)  
    {  
        if(ch_num%2==1)            //�±�Ϊ�������ַ�ӦΪ�������  
        {  
            if(ch!='+' && ch!='-' && ch!='*' && ch!='/')  
            {  
                printf("��%d���ַ����벻�Ϸ�!ӦΪ��+-*/��֮һ",ch_num+1);  
                return '\0';  
            }  
        }  
        else                       //�±�Ϊż�����ַ�ӦΪ����  
        {  
            if(!(ch>='0' && ch<='9'))  
            {  
                printf("��%d���ַ����벻�Ϸ�!ӦΪ0��9����֮һ",ch_num+1);  
                return '\0';  
            }  
        }  
        str[ch_num]=ch;  
        str=(char*)realloc(str,(++ch_num+1)*sizeof(char));   //��ch_numΪ�ַ������±�,��realloc����Ϊ�ַ�����  
    }                                                        //���¿����鳤�Ȳ���Ϊ�±�+2,�൱�ڲ���Ϊnum++���num+1  
    if(str[ch_num-1]=='+' || str[ch_num-1]=='-' || str[ch_num-1]=='*' || str[ch_num-1]=='/')  
    {                                                        //�����һ���ַ�Ϊ����������벻�Ϸ�  
        printf("���һ���ַ����벻�Ϸ�!ӦΪ����!",ch_num+1);  
        return '\0';  
    }  
    str[ch_num]='\0';    //����β���ô�������  
    return str;  
}  
  
/*�����������㷨����˼·�ǽ���ȷ(����ʱ�������)��һλ�����������ŵļ򵥱��ʽ�ַ������ԼӼ���Ϊ�ֽ���(��Ϊ���ȼ���˳���) 
�����ʽ�ָ�����ɸ��Ӽ�����ٽ������ɵļӼ���ڵ���Ӽ�������ڵ㽻�����ӳ���������ÿ���Ӽ���ڵ㶼���������� 
*/  
  
//�������������ʾָ������ASItem,ASSign,���������֧��C99���޷��ñ����������鳤,��ֻ���ö���ָ���malloc����ָ������  
BTNode* creat_tree(char *str)  
{  
    int itemCount=0,ASCount=0,len=strlen(str),i; //AS��ΪaddSub�Ӽ���,ǰ��Ϊ�Ӽ������,����Ϊ�Ӽ����ż���,���������±�  
    BTNode **ASItem,**ASSign,*root,*p;           //ASItemָ�������żӼ���ڵ�ָ��,ASSignָ�������żӼ����Žڵ�ָ��  
    ASItem=(BTNode**)malloc((len/2+1)*sizeof(BTNode*));  
    ASSign=(BTNode**)malloc((len/2)*sizeof(BTNode*));   
    if(str[0]=='\0')                             //�Ӽ����Žڵ�����Ϊ�Ӽ���ڵ���+1.��itemCount==ASCount+1  
        return NULL;  
    for(i=0;i<len/2;i++)               //ָ�������ÿ�  
        ASSign[i]=NULL;  
    for(i=0;i<len/2+1;i++)  
        ASItem[i]=NULL;  
    for(i=0;i<len;i++)                 //��ȡstr�ַ�����  
    {  
        if(str[i]<='9' && str[i]>='0')  
        {  
            p=(BTNode*)malloc(sizeof(BTNode));  
            p->data=str[i];  
            p->lchild=p->rchild=NULL;  
        }  
        else if(str[i]=='+'||str[i]=='-')  
        {  
            ASItem[itemCount++]=p;     //��p�ڵ����Ӽ�������  
            p=(BTNode*)malloc(sizeof(BTNode));  
            p->data=str[i];  
            ASSign[ASCount++]=p;  
        }   //���Ӽ����Žڵ�ָ�����ASSign����,���з��Žڵ�ĺ��ӱز�Ϊ���Ҵ������̲�������亢�ӽڵ�,�������ÿ�  
        else                           //str[i]����Ϊ�˳������  
        {  
            root=(BTNode*)malloc(sizeof(BTNode));  
            root->data=str[i];         //��*,/��Ϊ���ݴ�����ڵ�������  
            root->lchild=p;            //pһ��Ϊ���ֻ�*,/�ڵ�(�����ѹ���õ�)  
            p=(BTNode*)malloc(sizeof(BTNode));  
            p->data=str[++i];          //��ʱpΪ��ǰ�ڵ����һ���ڵ�,��ʱstr[++i]��Ϊ����,����һ�����ʵ�str��Ϊ����  
            p->lchild=p->rchild=NULL;  
            root->rchild=p;            //���ڵ���Һ������ϴ˽ڵ�  
            p=root;                    //�������ڵ㹹����ϣ�����p  
        }  
    }  
    ASItem[itemCount]=p;  
    ASSign[0]->lchild=ASItem[0];       //��һ�����Žڵ���������һ����ڵ�  
    ASSign[0]->rchild=ASItem[1];  
    for(i=1;i<ASCount;i++)             //�ԼӼ������Žڵ���Ϊ�������ڵ㣬�Ӽ���֮�����Ľڵ�Ϊ�������ڵ�ĺ��ӽڵ�  
    {                                  //�Ӽ����Žڵ�����Ϊ�Ӽ���ڵ���+1.��itemCount==ASCount+1,���ﹹ��ʱASCount������һ��  
        ASSign[i]->lchild=ASSign[i-1]; //����һ���ڵ�����ļӼ����Žڵ����Ӷ�����һ�����Žڵ�  
        ASSign[i]->rchild=ASItem[i+1]; //�Һ��Ӷ�����ڵ�  
    }  
    return ASSign[ASCount-1];  
}  
  
int main ()  
{  
    printf("%d\n",calcula(creat_tree(input_cheak_str())));  
    return 0;  
}  