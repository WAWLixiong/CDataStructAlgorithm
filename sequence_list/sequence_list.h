//
// Created by zzlion on 2021/3/2.
//

#ifndef DATASTRUCTALGORITHM_SEQUENCE_LIST_H
#define DATASTRUCTALGORITHM_SEQUENCE_LIST_H

#endif //DATASTRUCTALGORITHM_SEQUENCE_LIST_H

#include "../common.h"

typedef struct {
    ElemInt *elem;
    int length;
} SqList;

Status InitList_Sq(SqList *L);

void DestroyList(SqList L);

void ClearList(SqList L);

int GetLength(SqList L);

int IsEmpty(SqList L);

int GetElem(SqList L, int i, ElemInt e);

int LocateElem(SqList L, ElemInt e);

Status ListInsert_Sq(SqList *L, int i, ElemInt e);

Status ListDelete_Sq(SqList L, int i);

Status ListAppend_Sq(SqList *L, ElemInt e);

// 有序链表表合并
void MergeList_Sq(SqList La, SqList Lb, SqList *Lc);
