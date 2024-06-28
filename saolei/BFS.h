#include"all.h"

typedef struct Node
{
    int xy[2];
    struct Node* next;
} Node;// 定义节点结构体

typedef struct 
{
    Node* front;
    Node* rear;
} Queue;// 定义队列结构体

void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}// 初始化队列

int isEmpty(Queue* q)
{
    return q->front==NULL;
}//检查队列是否为空
 
void enQueue(Queue* q,int* xy)
{
    Node* Newnode = (Node*)malloc(sizeof(Node));
    Newnode->xy[0]=xy[0];
    Newnode->xy[1]=xy[1];
    Newnode->next=NULL;

    if(q->front==NULL)
    {
        q->front=q->rear=Newnode;
    }
    else
    {
        q->rear->next=Newnode;
        q->rear=Newnode;
    }
}

int* deQueue(Queue *q)
{
    int *xy;
    xy=q->front->xy;
    Node* freen=q->front;
    q->front=q->front->next;
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    free(freen);
    return xy;
}
