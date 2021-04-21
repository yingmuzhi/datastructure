#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MaxSize 50
#define ElemType int
// 顺序栈
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;


