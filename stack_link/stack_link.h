//
// Created by zzlion on 2021/3/20.
//

#ifndef DATASTRUCTALGORITHM_STACK_H
#define DATASTRUCTALGORITHM_STACK_H

#endif //DATASTRUCTALGORITHM_STACK_H

#include "../common.h"

typedef struct StackNode{
    SElemType data;
    struct StackNode *next; // 嵌套的定义, 自己定义自己
} StackNode, *LinkStack;

Status InitStack(LinkStack linkStack);

Status DestroyStack(LinkStack linkStack);

Status StackEmpty(LinkStack linkStack);

long StackLength(LinkStack linkStack);

SElemType GetTop(LinkStack linkStack);

Status ClearStack(LinkStack linkStack);

Status Push(LinkStack *linkStack, SElemType e);

Status Pop(LinkStack *linkStack, SElemType *e);
