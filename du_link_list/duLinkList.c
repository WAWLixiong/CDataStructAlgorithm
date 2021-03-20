//
// Created by zzlion on 2021/3/16.
//

#include "duLinkList.h"
#include "stdlib.h"
#include <stdio.h>

// 初始化
void initDuList_L(DuLinkList *L) {
    *L = (DuLNode *) malloc(sizeof(DuLNode));
    (*L)->next=NULL;
    (*L)->prior=NULL;
}


// 判断是否为空
int DuListIsEmpty(DuLinkList L) {
    return 0;
}

// 销毁
Status DestroyDuList_L(DuLinkList L) {
    return OK;
}

// 清空 (空链表 即链表只保留了头指针和头结点, 其余结点删除)
Status ClearDuList_L(DuLinkList L) {
    return OK;
}

// 长度(不计头结点)
int CountDuList_L(DuLinkList L) {
    return 0;
}

// 获取指定位置的数据
Status GetElem_DuL(DuLinkList L, int i, ElemType *e) {
    return OK;
}

// 查找某个值 并返回结点
DuLNode *LocateElem_DuL(DuLinkList L, ElemType e) {
    DuLNode * a;
    return a;
}

// 查找某个值 并返回位置
int LocateElem_DuL_site(DuLinkList L, ElemType e) {
    return 0;
}

// 在第i个结点前插入值为e的新结点
Status ListInert_DuL(DuLinkList L, int i, ElemType e) {
    DuLNode * p = L->next;
    int site = 1;
    while(p && site < i) {
        p = p->next;
        ++site;
    }
    // 这个条件可以放在while循环之前， 因为它是执行的先决条件
    if(!p || site > i) {
        return ERROR;
    }
    DuLNode * node = (DuLNode *)malloc(sizeof(DuLNode));
    node->data = e;
    node->prior = p->prior;
    p->prior->next = node;
    node->next = p;
    p->prior = node;
    return OK;
}

// 删除第i个元素,删除的元素存放到e
Status ListDelete_DuL(DuLinkList L, int i, ElemType *e) {
    // 双向链表不需要找到前驱(单链需要)，
    // 直接找到本身那个结点就可以直接删除了, 也不需要中间变量
    DuLNode * p = L->next;
    int site=1;
    while(p && site < i) {
        p = p->next;
        ++site;
    }
    if(!p || site > i) {
        return ERROR;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    *e = p->data;
    free(p);
    return OK;
}

// 建立双链表-头插法--这个就相当于直接更改L的指向就可以, 省略实现代码
Status DuListInster_Head(DuLinkList L, ElemType e) {

    return OK;
}

// 建立双向链表-头插法-插入n个元素, 越来越长的尾巴, 有个指针始终指向头部
Status DuListInster_H(DuLinkList L, int n) {
    DuLNode * p = L;
    for(int i = 1; i <= n; i++){
        DuLNode * node = (DuLNode *) malloc(sizeof(DuLNode));
        printf("%s", "please input a char\n");
        scanf("%c", &(node->data)); // 优先级问题， 需要加括号
        node->next = p->next;
        node->prior = p;
        p->next = node;
    }
    return OK;
}

// 建立双向链表-在最末尾插入元素
Status DuListInster_Tail(DuLinkList L, ElemType e) {
    DuLNode * node;
    DuLNode * p = L;
    while(p && p->next){
        p=p->next;
    }
    if(!p){
        return ERROR;
    }
    node = (DuLNode *) malloc(sizeof(DuLNode));
    node->data = e;
    node->next=NULL;
    node->prior=p;
    p->next = node;
    return OK;
}

// 建立单链表-尾插法-插入n个元素, 越来越长的头部, 有个指针始终指向尾部
Status DuListInster_T(DuLinkList L, int n) {
    DuLNode * r = L;
    for(int i = 1; i <= n; i++){
        DuLNode * node = (DuLNode *) malloc(sizeof(DuLNode));
        printf("%s", "please input a char\n");
        scanf("%c", &(node->data)); // 优先级问题， 需要加括号
        node->next=NULL;
        r->next=node;
        node->prior=r;
        r=node;
    }
    return OK;
}
