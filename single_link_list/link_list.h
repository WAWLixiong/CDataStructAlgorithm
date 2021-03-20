//
// Created by zzlion on 2021/3/4.
//

#ifndef DATASTRUCTALGORITHM_L_NODE_H
#define DATASTRUCTALGORITHM_L_NODE_H

#endif //DATASTRUCTALGORITHM_L_NODE_H

#include "../common.h"

typedef struct LNode {
    ElemType data;
    struct LNode * next; // 自己定义自己, 嵌套的定义
} LNode, * LinkList; // 通过struct Lnode定义新的类型Lnode, LinkList为指向struct Lnode的指针类型

// 定义链表L: LinkList L;
// 定义结点指针p: LNode * p 等价于 LinkList p;


// 初始化
void InitList_L(LinkList *L);

int ListEmpty(LinkList L);

// 销毁
Status DestroyList_L(LinkList L);

// 清空 (空链表 即链表只保留了头指针和头结点, 其余结点删除)
Status ClearList_L(LinkList L);

// 长度(不计头结点)
int CountList_L(LinkList L);

// 获取指定位置的数据
Status GetElem_L(LinkList L, int i, ElemType *e);

// 查找某个值 并返回结点
LNode * LocateElem_L(LinkList L, ElemType e);

// 查找某个值 并返回位置
int LocateElem_L_site(LinkList L, ElemType e);

// 在第i个结点前插入值为e的新结点
Status ListInert_L(LinkList L, int i, ElemType e );

// 删除第i个元素,删除的元素存放到e
Status  ListDelete_L(LinkList L, int i, ElemType *e);

// 建立单链表-头插法
Status ListInster_Head(LinkList L, ElemType e);

// 建立单链表-头插法-插入n个元素
Status ListInster_H(LinkList L, int n);

// 建立单链表-尾插法
Status ListInster_Tail(LinkList L, ElemType e);

// 建立单链表-尾插法-插入n个元素
Status ListInster_T(LinkList L, int n);

// 线性表合并
void unionLinkList(LinkList La, LinkList Lb);

// 有序链表表合并
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc);
