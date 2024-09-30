#ifndef BFS_H

#define BFS_H
#include<stdio.h>
#include<stdlib.h>

#endif

typedef struct Node
{
    int lc[2];
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
 
void enQueue(Queue* q,int* lc)// 入队
{
    Node* Newnode = (Node*)malloc(sizeof(Node));
    Newnode->lc[0]=lc[0];
    Newnode->lc[1]=lc[1];
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

int* deQueue(Queue *q)// 出队
{
    int *lc = (int *)malloc(sizeof(int) * 2);
    lc[0]=q->front->lc[0];
    lc[1] = q->front->lc[1];
    Node* freen=q->front;
    q->front=q->front->next;
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    free(freen);
    return lc;
}
