#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
typedef struct node * PNode; /*定义队列的每个节点的类型*/
typedef struct node {
    int data;//每个节点中存放的数据
    PNode next;//下一节点
}Node;
 
typedef struct queue {
    PNode head;//队头
    PNode tail;//队尾
    int Length;//队列长度
}Queue;
 
Queue *InitQueue() { // 返回创建的新空队列
    Queue *queue = (Queue *)malloc(sizeof(Queue));  //创建存放队列
    queue->head = (Node *)malloc(sizeof(Node));  //创建头指针结点的存放空间
    queue->head->next = NULL;   //头指针指向空指针
    queue->tail = queue->head;  //令队列的尾指针为队列的头指针，这是为了在第一个元素入队时，头指针的字针能够指向第一个元素。
    queue->Length = 0;
    return queue;
}
 
void EnQueue(Queue *Q,int x) { // 将x送入队，每次都是在队尾加入新结点
    PNode newnode = (Node *)malloc(sizeof(Node));//产生新的结点
    newnode->data = x;  //新的结点数据域存放输入的x
    ++Q->Length;   //队列长度加一
    newnode->next = NULL;   //新产生的结点指向空指针
    Q->tail->next = newnode;  // 队尾指针指向新结点，当第一个元素x进来的时候，队尾指针相当于队头指针，那么也就是队头指针指向第一个进来的元素
    Q->tail = newnode; //接着就是队尾变成了刚刚进来的新结点
}
 
int IsFullQueue(Queue *Q) {
    return (Q->Length > 0);
}

bool IsEmptyQueue(Queue *Q)
{
  if(Q->head==Q->tail)
	  printf("队列为空...\n");
  return true;
}
 
int DeQueue(Queue *Q,int *x) { // 将x送出队
    PNode p;            //定义结点指针p
    if(IsFullQueue(Q)) {
        p = Q->head->next;   //  p的地址是头指针所指的下一个地址，也就是第一个元素的地址
        *x = p->data;   //访问p的地址，取该地址的数据域的数据
        Q->head->next = p->next;  //此时，将头指针指向p的下一个地址，即第二个元素。
        --Q->Length;  //队列长度减一
        free(p);   //释放p的空间，此时p的地址也就是队列里面结点的地址
        return 1;
    }
    return 0;
}
 
int GetLength(Queue *Q) { // 获取队列长度
    return Q->Length;
}
 
int GetHeadQueue(Queue *Q) { // 获取队头数据
    return Q->head->next->data;
}
 
void ClearQueue(Queue *Q) {
    Q->tail = Q->head;
    Q->Length = 0;
}
 
void DestroyQueue(Queue *Q) {
    PNode q,p = Q->head;
    while(p) {
        q = p;
        p = q->next;
        free(q);
    }
    Q->head = Q->tail = NULL;
    free(Q);
    Q = NULL;
}

void TraverseQueue(Queue *Q) {
    
    if (IsEmptyQueue(Q)) {
        exit(-1);
    } 
    PNode P = Q->head->next;    //从队列首节点开始遍历（非头节点，注意区分）
    printf("遍历队列结果为：");
    while (P != NULL) {
        printf("%d ", P->data);
        P = P->next;
    }
    printf("\n");
}





 
int main() {
    int i,n = 10,x;
    Queue *Q = InitQueue();//定义一个新的队列
    srand(time(0));  //用于rand()产生随机数的前提，播种，播下time（0），那么每次运行程序得到的种子不同，产生的随机数列也就不同。
    for(i = 0; i < n; ++i) {
        x = rand() % 100;//产生一个不大于100的随机数
        printf("%d ",x);
        EnQueue(Q,x);//x送进队列
    }
    printf("\n");
    while(IsFullQueue(Q)) {//判断没有空队列
        DeQueue(Q,&x);//出队列
        printf("%d ",x);
    }
    printf("\n");
    return 0;
}