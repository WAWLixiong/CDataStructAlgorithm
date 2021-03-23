//
// Created by zzlion on 2021/3/23.
//

#include "queue_link.h"

Status InitQueue(LinkQueue *q) {
    // 计算的是QNode的字节, 而不是QueuePtr的字节, 可以测试一下两个是否一样(实测,指针小一点)
    (*q).rear = (*q).front = (QueuePtr) malloc(sizeof(QNode));
    if (!(*q).rear) {
        // 一般不需要判断内存溢出, 因为太小了
        exit(OVERFLOW);
    }
    (*q).rear->next = NULL;
    (*q).front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue *q) {
    while ((*q).front) {
        // 或者不定义p, 直接用(*q).rear来存放, 因为要销毁了也没有作用了
        QNode *p = (*q).front->next;
        free((*q).front);
        (*q).front = p;
    }
    return OK;
}

int QueueLength(LinkQueue q) {
    QueuePtr p = q.front;
    int count = 0;
    while(p->next){
        count++;
        p = p->next;
    }
    return count;
}

ElemType GetHead(LinkQueue q) {
    if (q.front == q.rear) {
        return ERROR; // 队空
    }
    return q.front->next->data;
}

Status EnQueue(LinkQueue *q, ElemType e) {
    QueuePtr ptr = (QueuePtr) malloc(sizeof(QNode));
    if (!ptr) {
        exit(OVERFLOW);
    }
    ptr->data = e;
    ptr->next = NULL;
    (*q).rear->next = ptr;
    return OK;
}

Status Dequeue(LinkQueue *q, ElemType *e) {
    if ((*q).front == (*q).rear) {
        return ERROR; // 队空
    }
    QueuePtr p = (*q).front->next;
    // *e = (*q).front->next->data; // 初始时指向的NULL;
    *e = p->data; // 初始时指向的NULL;
    (*q).front->next = p->next;
    if((*q).rear == p) { // 删没了
        (*q).rear = (*q).front; // 没有
    }
    free(p);
    return OK;
}
