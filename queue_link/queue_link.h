//
// Created by zzlion on 2021/3/23.
//

#ifndef DATASTRUCTALGORITHM_QUEUE_LINK_H
#define DATASTRUCTALGORITHM_QUEUE_LINK_H

#endif //DATASTRUCTALGORITHM_QUEUE_LINK_H

#include "../common.h"
#include "stdlib.h"

typedef struct Qnode {
    ElemType data;
    struct Qnode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front; // 头指针
    QueuePtr rear; // 尾指针
} LinkQueue;

Status InitQueue(LinkQueue *q);

Status DestroyQueue(LinkQueue *q);

int QueueLength(LinkQueue q);

ElemType GetHead(LinkQueue q);

Status EnQueue(LinkQueue *q, ElemType e);

Status Dequeue(LinkQueue *q, ElemType *e);
