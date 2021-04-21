/**
 * 线性表的顺序表
 * 的基本操作和定义
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MaxSize 50
#define ElemType int

typedef struct SqList {
    ElemType data[MaxSize]; // 顺序表的元素
    int length;             // 顺序表当前长度
}SqList;

/**
 *
 * 课后习题此处开始
 */

// 1
// 从表中删除具有最小值的元素并返回值为被删元素的值
// 空出位置由最后一个元素填补
// 顺序表如果空，则显示出错信息并退出运行
ElemType test1(SqList *L){
    ElemType result;
    int cnt = 0;
    // 如果顺序表不空
    if ( L->length > 0){
        result = L->data[0];
        for (int idx = 1; idx<L->length; idx++){
            result = result <= L->data[idx] ? result : L->data[idx];
            cnt = result <= L->data[idx] ? cnt : idx;
        }
        L->data[cnt] = L->data[L->length-1];
    }
    else {
        // 显示出错信息并退出运行

    }



    return result;
}





/**
 *
 * 课后习题此处结束
 */



// 在L中的i位置插入元素e
bool ListInsert(SqList *L, int i, ElemType e){
    bool flag = false;
    // 判断L是否满了
    if ( L->length+1 <= MaxSize ){
        // 判断i是否正常
        if ( i >= 0 && i<= L->length +1 ){
            // 进行插入操作
            for ( int temp = L->length; temp >= i; temp-- ){
                L->data[temp] = L->data[temp-1];
            }
            L->data[i-1] = e;
            L->length++;
            flag = true;
        }
        else ;
    }
    else  ;

    return flag;
}

// 初始化
bool InitList(SqList *L){
    bool flag = false;
    
    L->length = 0;
    flag = true;
    return flag;
}

// 在L中的i位置实现删除操作
bool ListDelete(SqList *L, int i, ElemType *e){
    bool flag = false;
    // 判断表空
    if (L->length >0){
        // 判断i的位置合理
        if ( i>0 && i<=L->length ){
            // 进行删除
            for ( int temp = i; temp<L->length; temp++){
                L->data[temp-1] = L->data[temp];
            }
            L->length--;
            flag = true;
        }
        else ;
    }
    else ;
    return flag;
}

// 在L中实现顺序按值查找
int LocateElem(SqList *L, ElemType e){
    int result = 0;
    for (int idx = 0; idx<L->length; idx++){
        if ( e == L->data[idx])
        {    
            result = idx+1;
            printf("Find!\n");
        }
        else ;
    }
    return result;
}


int main(int argc, const char *argv[]){

    SqList *L = (SqList *)malloc(sizeof(SqList));

{
    printf("ListInsert time ---\n");
    // 增加元素
    ElemType input;
    printf("type in ur input\n");
    scanf("%d", &input);
    // 合理运用短路效应
    while( input != -1 && ListInsert(L, L->length+1, input)&&input != -1 ){
        printf("type in ur input\n");
        scanf("%d", &input);
    }
}

    {
        printf("ListDelete time ---\n");
        // 删除元素
        ElemType *output = (ElemType *)malloc(sizeof(ElemType));
        int input;
        printf("L 's length is %d now\n", L->length);
        printf("type in ur input u wanna delete\n");
        scanf("%d", &input);
        while ( input != -1 && ListDelete(L, input, output) ){
            
            printf("L 's length is %d now\n", L->length);
            printf("type in ur input u wanna delete\n");
            scanf("%d", &input);
        }
        free(output);
    }

    {
        printf("ListLocate time ---\n");
        ElemType e;
        printf("input the Elem you wanna locate\n");
        scanf("%d", &e);
        printf("this is the location %d\n", LocateElem(L, e) ); 
    }

    {
        printf("ListOutput time ---\n");
        // 输出元素
        printf("Length is %d\n", L->length);
        for (int idx = 0; idx<L->length; idx++){
            printf("%d\n", L->data[idx]);
        }
    }

    {
        printf("test1 ---\n");
        printf("min is %d\n", test1(L) );
        // 输出元素
        printf("Length is %d\n", L->length);
        for (int idx = 0; idx<L->length; idx++){
            printf("%d\n", L->data[idx]);
        }
    }

    return 0;
}
