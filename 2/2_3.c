/**
 * 线性表的链式表示
 * 一直有个疑问<!--这里*L用malloc申请后，需要free哪个)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElemType int

typedef struct LNode {      // 定义单链表结点类型
    ElemType data;          // 数据域
    struct LNode *next;     // 指针域
}LNode, *LinkList;


// 头插法建立单链表
LinkList List_HeadInsert(LinkList *L) {
    (*L) = (LinkList) malloc (sizeof(LNode));
    (*L) -> next = NULL;
    ElemType input;
    printf("now ,type ur input\n");
    scanf("%d", &input);
    while (input!=-1){
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = input;
        node->next = (*L)->next;
        (*L)->next = node;

        printf("now ,type ur input\n");
        scanf("%d", &input);
    }
    return *L;
}


// 尾插法建立单链表
LinkList List_TailInsert(LinkList *L){
    *L = (LinkList)malloc(sizeof(LNode));
    (*L) -> next = NULL;
    ElemType input;
    printf("now ,type ur input\n");
    scanf("%d", &input);
    LNode *tail = *L;
    while (input!=-1){
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = input;
        node->next = tail->next;
        tail->next = node;
        tail = node; 

        printf("now, type ur input\n");
        scanf("%d", &input);
    }
    tail->next = NULL;
    return *L;
}


// 按序号查找结点值
LNode *GetElem(const LinkList L, int i){
    LNode *p = 0;
    // 验证i的合理性
    if ( i>0 ){
        int j = 0;
        p = L;
        while ( p = p->next ){
            // j++;
            if ( i == ++j ){
                break;
            }
            else ;
        }
    }
    else if( i == 0){
        p = L;
    }
    else {
        printf("wrong\n");
    }
    return p;
}


// 按值查找结点
LNode *LocateElem(const LinkList L, ElemType e){
    LNode *p = L;
    while ( p = p->next ){
        if ( p->data == e)
        {
     //     printf("your wanna number %d is find\n", p->data);
            break;
        }
        else ;
    }
    return p;

}


int main(int argc, const char *argv[]){
    {
        // 头插法
        LinkList L = 0;
        List_HeadInsert(&L);
        printf("your first number is %d\n", L->next->data);

        /**
    {
        // 按序号查找
        int temp;
        printf("please input the number you wanna get?\n");
        scanf("%d", &temp);
        printf("the No.%d you wanna get is %d\n", temp, GetElem(L, temp)->data);
    }

    {
        // 按值查找
        int temp;
        printf("please inpur the elem you wanna get?按值查找\n");
        scanf("%d", &temp);
        printf("the elem: %d you wanna get is %d\n", temp, LocateElem(L, temp)->data);
    }
        */

    }



    /*
    {
        // 尾插法
        LinkList L2 = 0;
        List_TailInsert(&L2);
        printf("your first number is %d\n", L2->next->data);
    }
    */


    return 0;
}
