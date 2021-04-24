/**
 * 队列
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 50
#define ElemType int
// 顺序队列
typedef struct SqQueue {
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

// 初始化
void InitQueue(SqQueue *Q){
    Q->rear = Q->front = 0;
}

// 判空
bool isEmpty(SqQueue Q){
    bool flag = false;
    if (Q.front == Q.rear){
        flag = true;
    }
    return flag;
}

// 入队
bool EnQueue(SqQueue *Q, ElemType x){
    bool flag = false;
    // 判断是满
    if ( (Q->rear+1)%MaxSize == Q->front ) ;
    else {
        Q->data[Q->rear] = x;
        Q->rear = (Q->rear+1)%MaxSize;
        flag = true;
    }

    return flag;
}

// 出队
bool DeQueue(SqQueue *Q, ElemType *x){
    bool flag = false;
    // 判断是空
    if (Q->rear == Q->front) ;
    else {
        (*x) = Q->data[Q->front];
        Q->front = (Q->front + 1)%MaxSize;
        flag = true;
    }
    return flag;
}



// 链式存储
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct LinkQueue{
    LinkNode *front, *rear;
}LinkQueue;

// 初始化
void InitQueue2(LinkQueue *Q){
    Q->front = Q->rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;   // init to NULL;
}

// 判空
bool IsEmpty2(const LinkQueue Q){
    bool flag = false;
    if (Q.front == Q.rear) flag = true;
    else ;
    return flag;
}

// 进队
void EnQueue2(LinkQueue *Q, ElemType x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}

// 出队
bool DeQueue2(LinkQueue *Q, ElemType *x){
    bool flag = false;
    // 判断队列空
    if (Q->front == Q->rear) ;
    else {
        LinkNode *p = Q->front->next;
        (*x) = p->data;
        Q->front->next = p->next;
        if (Q->rear == p){
            Q->rear = Q->front;
        }
        free(p);
        flag = true;
    }
    return flag;
}




int main(int argc, const char *argv[])
{
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    printf("Node is %p", p->next);
    return 0;
}
