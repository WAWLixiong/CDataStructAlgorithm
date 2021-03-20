//
// Created by zzlion on 2021/3/20.
//

#include "stack_link.h"
#include "stdlib.h"

Status InitStack(LinkStack linkStack) {
    linkStack = (StackNode *) malloc(sizeof(struct StackNode));
    linkStack = NULL;
    return OK;
}

Status DestroyStack(LinkStack linkStack) {
    // 释放每个结点
    while(linkStack != NULL){
        StackNode *p = linkStack;
        linkStack = linkStack->next;
        free(p);
    }
    return OK;
}

Status StackEmpty(LinkStack linkStack) {
    if(linkStack->next == NULL){
        return TRUE;
    }
    return FALSE;
}

long StackLength(LinkStack linkStack) {
    long count = 0;
    while(linkStack != NULL){
        linkStack = linkStack->next;
        count++;
    }
    return count;
}

SElemType GetTop(LinkStack linkStack) {
    if(linkStack == NULL){
        // 判断指针与NULL比较, 判断数值与0比较
        return ERROR;
    }
    return linkStack->data;
}

Status ClearStack(LinkStack linkStack) {
    while(linkStack != NULL){
        linkStack->data = 0; // 先置为0吧
        linkStack = linkStack->next;
    }
    return OK;
}

Status Push(LinkStack *linkStack, SElemType e) {
    StackNode * node;
    node = (StackNode *) malloc(sizeof(struct StackNode));
    node->data = e;
    node->next = *linkStack;
    *linkStack = node;
    return OK;
}

Status Pop(LinkStack *linkStack, SElemType *e) {
    /*
     * 怎么判断要传入值, 还是指针?
     * 如果改变变量的位置 则需要指针
     * 如果知识使用变量的值, 只需要传入变量的值即可
     */
    if(linkStack == NULL){
        // 判断指针与NULL比较, 判断数值与0比较
        return ERROR;
    }
    *e = (*linkStack)->data;
    StackNode * p = *linkStack;
    *linkStack = (*linkStack)->next;
    free(p);
    return OK;
}