/**
 * 队列
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 50
// 顺序队列
typedef struct SqQueue {
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

// 初始化
void InitQueue(SqQueue *Q){

