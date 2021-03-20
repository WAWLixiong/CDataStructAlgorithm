//
// Created by zzlion on 2021/3/2.
//

#include "sequence_list.h"
#include <stdlib.h>

#define MAXSIZE 100

Status InitList_Sq(SqList *L) {
    ElemInt elem[MAXSIZE];
    (*L).elem = elem;
    if (!(*L).elem) {
        exit(OVERFLOW);
    }
    (*L).length = 0;
    return OK;
};

void DestroyList(SqList L) {
    if (L.elem) {
        // C语言中的malloc/free对应 C++中的 new/delete
        free(L.elem);
    }
};


void ClearList(SqList L) {
    L.length = 0;
}


int GetLength(SqList L) {
    return (L.length);
}

int IsEmpty(SqList L) {
    if (L.length == 0) {
        return 1;
    }
    return 0;
}

int GetElem(SqList L, int i, ElemInt e) {
    if (i < 1 || i > L.length) {
        return ERROR;
    }
    e = L.elem[i - 1];
    return OK;
}

int LocateElem(SqList L, ElemInt e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

Status ListInsert_Sq(SqList *L, int i, ElemInt e) {
    if (i < 1 || i > (*L).length + 1) {
        return ERROR;
    }
    if ((*L).length == MAXSIZE) {
        return ERROR;
    }
    for (int j = (*L).length; j > i; j--) {
        (*L).elem[j] = (*L).elem[j - 1];
    }
    (*L).elem[i - 1] = e;
    (*L).length++;
    return OK;
}

Status ListDelete_Sq(SqList L, int i) {
    if (i < 1 || i > L.length) {
        return ERROR;
    }
    for (int j = i; j < L.length; j++) {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return OK;
}


Status ListAppend_Sq(SqList *L, ElemInt e) {
    if ((*L).length == MAXSIZE) {
        return ERROR;
    }
    *(L->elem + (*L).length) = e;
    return OK;
}


// 有序顺序表合并
void MergeList_Sq(SqList La, SqList Lb, SqList *Lc) {
    /*
     * 算法分析
     * 时间复杂度 O(len(La) + len(Lb))
     * 空间复杂度 O(len(La) + len(Lb))
     */
    ElemInt *pa = La.elem; // 指针pa 指向La表的第一个元素
    ElemInt *pb = Lb.elem; // 指针pb 指向Lb表的第一个元素
    int a_len = La.length;
    int b_len = Lb.length;
    Lc->length = a_len + b_len; // 新表长度为带合并两表的长度之和
    ElemInt *pc = Lc->elem; // 指针pc 指向新表的第一个元素
    ElemInt *pa_last = pa + La.length - 1;
    ElemInt *pb_last = pb + Lb.length - 1;

    while (pa <= pa_last && pb <= pb_last) { // 两个表都非空
        if (*pa <= *pb) { // 依次"摘取"两表中值较小的结点
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    while(pa<=pa_last) {
        *pc++ = *pa++; // Lb表已经到达表尾, 将La中剩余元素加入Lc
    }
    while(pb<=pb_last) {
        *pc++ = *pb++; // La表已经到达结尾, 将Lb中剩余元素加入Lc
    }

    /*
        for (int i = 0; i < a_len; i++) {
            for (int j = 0; j < b_len; j++) {
                if (!(*elem_a) && (*elem_p) || (*elem_a) && (*elem_p) && *elem_a > *elem_p) {
                    (*Lc).elem[site] = *elem_p;
                    site++;
                } else if ((!(*elem_p)) && (*elem_a) || (*elem_a) && (*elem_p) && *elem_a <= *elem_p) {
                    (*Lc).elem[site] = *elem_a;
                    site++;
                } else {
                    return;
                }
            }
        }
    */
}

/*
 *
 * 所有所有可能的情况为
 *
 * m1 > n1       n1
 * m1 = n1       n1
 * m2 n1         n1
 *
 * m1 < n1       m1
 * m1 n2         m1
 * m2 n2 结束     null
 *
 * m1=a有值
 * m2=a无值
 *
 * n1=b有值
 * n2=b无值
 *
 * m  n
 * m1 n1
 * m1 n2
 * m2 n1
 * m2 n2 结束
 *
 *
 * m1 n1 有分为
 * m1 > n1
 * m1 = n1
 * m1 < n1
 *
 * 所有所有可能的情况为
 *
 * m1 > n1       n1
 * m1 = n1       n1
 * m2 n1         n1
 *
 * m1 < n1       m1
 * m1 n2         m1
 * m2 n2 结束     null
 *
 */