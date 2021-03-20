//
// Created by zzlion on 2021/3/4.
//
#include "../common.h"
#include "link_list.h"
#include "stdlib.h"
#include <stdio.h>


void InitList_L(LinkList *L) {
    // L = new LNode; // C++
    // 生成新节点作为头结点, 头指针L指向头结点
    // 将头结点的指针域置空
    *L = (LinkList) malloc(sizeof(LNode)); // *L 取出指针内的东西, 即LinkList
    (*L)->next = NULL; // 优先级的问题， 需要加括号
}

int ListEmpty(LinkList L) {
    if (L->next) {
        return 0;
    } else {
        return 1;
    }
}

Status DestroyList_L(LinkList L) {
    // p指针 指向上次头指针指向的位置
    LNode *p;
    while (L) {
        p = L;
        L = L->next;
        // delete p; C++
        free(p);
    }
    return OK;
}

Status ClearList_L(LinkList L) {
    LNode *p, *q;
    p = L->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
    return OK;
}

int CountList_L(LinkList L) {
    LNode *p;
    p = L->next;
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}


Status GetElem_L(LinkList L, int i, ElemType *e) {
    /*
     * 获取指定位置的数据
     */
    LNode *p;
    p = L->next; // 首元结点
    int j = 1;
    while (p && j < i) {
        // 向后扫描, 直到p指向第i个元素或p为空
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    *e = p->data;
    return OK;

}


LNode *LocateElem_L(LinkList L, ElemType e) {
    /*
     * 查找某个值 并返回结点
     */
    /*
     * 算法分析:
     * 最好情况: 第一个结点就是
     * 最坏情况: 最后一个
     * 查找复杂读: O(n)
     */
    LNode *p = L->next;
    //    while (p->data != e) { //没有考虑到最后一个结点, 程序异常退出
    while (p && p->data != e) {
        p = p->next;
    }
    if (p == NULL) {
        return NULL; // 其实也就是返回p
    } else {
        return p;
    }
    //老师的实现方式
    /*
        while (p && p->data != e) {
            p = p->next;
        }
        return p;
    */
}

int LocateElem_L_site(LinkList L, ElemType e) {
    /*
     *  查找某个值 并返回位置
     */
    /*
     * 算法分析:
     * 最好情况: 第一个结点就是
     * 最坏情况: 最后一个
     * 查找复杂读: O(n)
     */
    LNode *p = L->next;
    int site = 1;
    while (p && p->data != e) {
        site++;
        p = p->next;
    }
    if (p) {
        return site;
    } else {
        return 0;
    }

}

Status ListInert_L(LinkList L, int i, ElemType e) {
    /*
     * 在第i个结点前插入值为e的新结点
     */
    /*
     * 算法分析:
     * 因为链表不需要移动元素, 需要修改指针, 一般情况下时间复杂度O(1)
     * 但是, 如果要在单链表中进行前插或删除操作, 由于要从头查找前驱结点,
     * 所耗时间复杂度为O(n)
     */
    // 在第i个结点前插入值为e的新结点
    // 如果i大于链表长度了(即从长度+1开始), 返回错误码
    LNode *p = L; // 了解代码逻辑, 可以确认p初始位置
    int site = 1;
    LNode *s = (LNode *) malloc(sizeof(struct LNode)); // 为什么必须初始化内存
    while (site != i && p) {
        site++;
        p = p->next;
    }
    if (site == i && p) {
        s->next = p->next;
        p->next = s;
        s->data = e;
    } else {
        return ERROR;
    }
    return OK;
    // 老师的方法
    /*
        LNode *pointer = L;
        int j = 0;
        while (p && j < i - 1) { // 寻找第i-1个结点, p指向i-1结点
            pointer = pointer->next;
            ++j;
        }
        if (!p || j > i - 1) { // i大于表长+1或者小于1, 插入位置非法
            return ERROR;
        }
        LNode *newLNode; //生成新结点, 将结点s的数据域置为e
        newLNode->data = e;
        newLNode->next = pointer->next;
        pointer->next = newLNode;
        return OK;
    */
}


Status ListDelete_L(LinkList L, int i, ElemType *e) {
    /*
     * 删除第i个元素,删除的元素存放到e; 关键是找到前驱元素
     */
    /*
     * 算法分析:
     * 因为链表不需要移动元素, 需要修改指针, 一般情况下时间复杂度O(1)
     * 但是, 如果要在单链表中进行前插或删除操作, 由于要从头查找前驱结点,
     * 所耗时间复杂度为O(n)
     */
    LNode *p = L;
    LNode *q;
    int j = 0;
    // 找到删除结点i-1的结点, p指向i-1结点
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    // 删除位置不合理
    if (!(p->next) || j > i - 1) {
        return ERROR;
    }
    q = p->next; // 临时保存被删除结点的地址以备释放
    p->next = q->next; // 改变删除节点前驱结点的指针域
    *e = q->data; // 保存删除结点的数据域
    free(q); // 释放删除结点的空间
    return OK;
}


Status ListInster_Head(LinkList L, ElemType e) {
    LNode *p;
    p = (LNode *) malloc(sizeof(struct LNode));
    p->next = L->next;
    L->next = p;
    p->data = e;
    return OK;
}


Status ListInster_H(LinkList L, int n) {
    /*
     *  建立单链表-插入n个元素
     */
    /*
     * 算法分析:
     * 时间复杂度为O(n)
     */
    // L经过初始化以后已经指向了NULL
    for (int i = n; i > 0; i--) {
        LNode *p;
        p = (LNode *) malloc(sizeof(struct LNode));
        printf("%s", "please input a char\n");
        scanf("%d", &(p->data)); // -> 优先级高于 &, 可以省略括号
        p->next = L->next;
        L->next = p;
    }
    return OK;
}


Status ListInster_Tail(LinkList L, ElemType e) {
    LNode *p = L;
    while(p->next){
        p++;
    }
    LNode *node = (LNode *) malloc(sizeof(struct LNode));
    node->data = e;
    node->next = NULL;
    p->next = node;
    return OK;
}


Status ListInster_T(LinkList L, int n) {
    /*
     * 算法分析:
     * 时间复杂度O(n)
     */
    LNode *r;
    r = L; // 尾指针用来向后移动

    for (int i = n; i > 0; i--) {
        LNode *p;
        p = (LNode *) malloc(sizeof(struct LNode));
        printf("%s", "please input a char\n");
        scanf("%d", &(p->data)); // -> 优先级高于 &, 可以省略括号
        p->next = NULL;
        r->next = p; // 插入到表尾
        r = p; // r指向新的尾结点
    }
    return OK;
}

void unionLinkList(LinkList La, LinkList Lb) {
    /*
     * 线性表合并
     */
    /*
     * 算法分析
     * 时间复杂度： O(Lb的长度)*O(La的长度)
     */
    int La_len = CountList_L(La);
    int Lb_len = CountList_L(Lb);
    ElemType e;
    for (int i = 1; i <= Lb_len; i++) {
        GetElem_L(Lb, i, &e);
        if (!LocateElem_L(La, e)) {
            ListInert_L(La, ++La_len, e);
        }
    }
}

void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc) {
    /*
     * 非递减有序链表合并为非递减有序链表
     */
    /*
     * 算法分析
     * 时间复杂度: O(len(La) + len(Lb))
     * 空间复杂度: O(1)
     */
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    LNode *pc = *Lc = La; // 用La的头结点作为Lc的头结点
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next= pa ? pa : pb;
    free(Lb);
}
