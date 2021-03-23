//
// Created by zzlion on 2021/3/22.
//

#ifndef DATASTRUCTALGORITHM_QUEUE_H
#define DATASTRUCTALGORITHM_QUEUE_H

#endif //DATASTRUCTALGORITHM_QUEUE_H
#include "../common.h"

typedef struct queue {
    ElemType *base; // 初始化的动态分配存储空间
    int front; //头指针, 若队列不空, 指向队列头元素
    int rear; //尾指针, 若队列不空, 指向队列尾元素的下一个位置
} Queue;

Status InitQueue(Queue *q);

int QueueLength(Queue q);

ElemType GetHead(Queue q);

Status EnQueue(Queue *q, ElemType e);

Status Dequeue(Queue *q, ElemType *e);