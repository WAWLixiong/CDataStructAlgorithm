//
// Created by zzlion on 2021/3/19.
//

#include "stack.h"
#include "stdlib.h"

Status InitStack(SqStack *sqStack) {
    sqStack->base = (SElemType *) malloc(sizeof(SElemType) * MAXSIZE);
    if(!sqStack->base){
        exit(OVERFLOW);
    }
    sqStack->top = sqStack->base;
    sqStack->stacksize = 0;
    return OK;
}

Status DestroyStack(SqStack *sqStack) {
    // 释放内存空间
    if(sqStack->base){
        free(sqStack->base);
        sqStack->stacksize=0;
        sqStack->base = sqStack->top = NULL;
    }
    return OK;
}

Status StackEmpty(SqStack sqStack) {
    if(sqStack.base == sqStack.top){
        return TRUE;
    }
    return FALSE;
}

long StackLength(SqStack sqStack) {
    // 指针计算是long类型
    return sqStack.top - sqStack.base;
}

SElemType GetTop(SqStack sqStack) {
    // 即弹出第一个栈顶
    if(sqStack.top == sqStack.base){
        // 栈空
        return ERROR;
    }
    return *--sqStack.top;
}

Status ClearStack(SqStack *sqStack) {
    // 直接将top指针指向base
    if(sqStack->base){
        sqStack->top=sqStack->base;
    }
    return OK;
}

Status Push(SqStack *sqStack, SElemType e) {
    if(sqStack->top - sqStack->base == sqStack->stacksize){
        // 栈满
        return ERROR;
    }
    *sqStack->top++ = e;
    return OK;
}

Status Pop(SqStack *sqStack, SElemType *e) {
    if(sqStack->top == sqStack->base){
        // 栈空
        return ERROR;
    }
    *e = *--sqStack->top;
    return OK;
}
