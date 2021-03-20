//
// Created by zzlion on 2021/3/16.
//

#ifndef DATASTRUCTALGORITHM_DULINKLIST_H
#define DATASTRUCTALGORITHM_DULINKLIST_H

#endif //DATASTRUCTALGORITHM_DULINKLIST_H

#include "../common.h"

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

// 初始化
void initDuList_L(DuLinkList *L);

// 判断是否为空
int DuListIsEmpty(DuLinkList L);

// 销毁
Status DestroyDuList_L(DuLinkList L);

// 清空 (空链表 即链表只保留了头指针和头结点, 其余结点删除)
Status ClearDuList_L(DuLinkList L);

// 长度(不计头结点)
int CountDuList_L(DuLinkList L);

// 获取指定位置的数据
Status GetElem_DuL(DuLinkList L, int i, ElemType *e);

// 查找某个值 并返回结点
DuLNode *LocateElem_DuL(DuLinkList L, ElemType e);

// 查找某个值 并返回位置
int LocateElem_DuL_site(DuLinkList L, ElemType e);

// 在第i个结点前插入值为e的新结点
Status ListInert_DuL(DuLinkList L, int i, ElemType e);

// 删除第i个元素,删除的元素存放到e
Status ListDelete_DuL(DuLinkList L, int i, ElemType *e);

// 建立单链表-头插法
Status DuListInster_Head(DuLinkList L, ElemType e);

// 建立单链表-头插法-插入n个元素
Status DuListInster_H(DuLinkList L, int n);

// 建立单链表-尾插法
Status DuListInster_Tail(DuLinkList L, ElemType e);

// 建立单链表-尾插法-插入n个元素
Status DuListInster_T(DuLinkList L, int n);
