//
// Created by zzlion on 2021/3/19.
//

#ifndef DATASTRUCTALGORITHM_STACK_H
#define DATASTRUCTALGORITHM_STACK_H

#endif //DATASTRUCTALGORITHM_STACK_H

#include "../common.h"

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;


Status InitStack(SqStack *sqStack);

Status DestroyStack(SqStack *sqStack);

Status StackEmpty(SqStack sqStack);

long StackLength(SqStack sqStack);

SElemType GetTop(SqStack sqStack);

Status ClearStack(SqStack *sqStack);

Status Push(SqStack *sqStack, SElemType e);

Status Pop(SqStack *sqStack, SElemType *e);
