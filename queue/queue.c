//
// Created by zzlion on 2021/3/22.
//

#include "queue.h"
#include "stdlib.h"


Status InitQueue(Queue *q) {
    (*q).base = (ElemType *) malloc(MAXSIZE * sizeof(ElemType)); // 分配数组空间
    if (!(*q).base) {
        exit(OVERFLOW); // 存储分配失败
    }
    (*q).front = (*q).rear = 0; // 头指针, 尾指针尾0, 队列为空
    return OK;
}

int QueueLength(Queue q) {
    return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

ElemType GetHead(Queue q) {
    if (q.front == q.rear) {
        return ERROR; //队空
    }
    return q.base[q.front]; // 返回队头指针元素的值, 队头指针不变
}

Status EnQueue(Queue *q, ElemType e) {
    if (((*q).rear + 1) % MAXSIZE == (*q).front) {
        return ERROR; // 队满
    }
    (*q).base[(*q).rear] = e;
    (*q).rear = ((*q).rear + 1) % MAXSIZE; // 队尾指针+1
    return OK;
}

Status Dequeue(Queue *q, ElemType *e) {
    if ((*q).rear == (*q).front) {
        return ERROR; // 队空
    }
    *e = (*q).base[(*q).front];
    (*q).front = ((*q).front + 1) % MAXSIZE;
    return OK;
}
