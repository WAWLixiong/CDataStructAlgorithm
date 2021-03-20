#include <stdio.h>
#include <stdlib.h>
#include "single_link_list/link_list.h"
#include "du_link_list/duLinkList.h"
#include "sequence_list/sequence_list.h"

void testSingleLinst() {
    LinkList L;
    InitList_L(&L);

    /*
        // 头插法
        ListInster_Head(L, 'g');
        ListInster_Head(L, 'f');
        ListInster_Head(L, 'e');
        ListInster_Head(L, 'd');
        ListInster_Head(L, 'c');
        ListInster_Head(L, 'b');
        ListInster_Head(L, 'a');
    */

    /*
        // 头插法
        ListInster_H(L, 5);
        int ret = CountList_L(L);
        printf("%d", ret);
    */

    // 尾插法
    ListInster_T(L, 5);
    int ret = CountList_L(L);
    printf("%d", ret);

    /*
        int ret = CountList_L(L);
        printf("%d\n", ret);
    */

    /*
        ElemType g;
        GetElem_L(L, 10, &g);
        printf("%c\n", g);
    */

    /*
        struct LNode *h;
        h = LocateElem_L(L, 'm');
        printf("%c\n", h->data);
    */

    /*
        int ret = ListInert_L(L, 20, 'n');
        printf("%d\n", ret);
        ElemType j;
        GetElem_L(L, 3, &j);
        printf("%c\n", j);
    */

    /*
        ElemType o;
        int ret = ListDelete_L(L, 2, &o);
        printf("%d\n", ret);
        printf("%c\n", o);
    */

}

void testDuLinkList() {
    DuLinkList L;
    initDuList_L(&L);
    /*
        // 初始化
        printf("%p\n", L->next);
        printf("%p\n", L->prior);
    */

    /*
        // 在最末添加元素
        DuListInster_Tail(L, 'a');
        DuListInster_Tail(L, 'b');
        DuListInster_Tail(L, 'c');
        DuListInster_Tail(L, 'd');
        printf("%c", L->next->next->next->next->data);
    */

    /*
            // 尾部插入法
            DuListInster_T(L, 5);
            printf("%c", L->next->next->next->next->data);
    */

    /*
        // 头部插入法
        DuListInster_H(L, 5);
        printf("%c", L->next->next->next->next->data);
    */

    /*
        // 删除某个位置的元素
            DuListInster_T(L, 5); // abcde
            ElemType elem;
            int site = 3;
            ListDelete_DuL(L, site, &elem);
            printf("%c\n", elem);
            printf("%c\n", L->next->next->next->data);
    */

    /*
        // 在第i个位置插入元素
        DuListInster_T(L, 5); // abcde
        ListInert_DuL(L, 3, 'o');
        printf("%c\n", L->next->next->next->data);
        printf("%c\n", L->next->next->next->next->data);
    */
}

void testSequenceList() {
    SqList La, Lb, Lc;
    InitList_Sq(&La);
    InitList_Sq(&Lb);
    InitList_Sq(&Lc);
    La.length = 4;
    /*
        *La.elem = 1;
        *(La.elem + 1) = 2;
        *(La.elem + 1) = 2;
        *(La.elem + 1) = 6;
    */
    ListAppend_Sq(&La, 1);
    ListAppend_Sq(&La, 2);
    ListAppend_Sq(&La, 2);
    ListAppend_Sq(&La, 6);

    Lb.length = 5;
    /*
        *Lb.elem = 3;
        *(Lb.elem + 1) = 3;
        *(Lb.elem + 1) = 4;
        *(Lb.elem + 1) = 6;
        *(Lb.elem + 1) = 8;
    */
    ListAppend_Sq(&Lb, 3);
    ListAppend_Sq(&Lb, 3);
    ListAppend_Sq(&Lb, 4);
    ListAppend_Sq(&Lb, 6);
    ListAppend_Sq(&Lb, 8);

    MergeList_Sq(La, Lb, &Lc);

    ElemInt *lc = Lc.elem;
    for (int i = 0; i < Lc.length; i++) {
        printf("%d\n", *lc);
        ++lc;
    }
}

void test_merge_by_single_link_list() {
    LinkList La;
    InitList_L(&La);
    ListInster_Tail(La, 1);
    ListInster_Tail(La, 2);
    ListInster_Tail(La, 2);
    ListInster_Tail(La, 6);

    LinkList Lb;
    InitList_L(&Lb);
    ListInster_Tail(Lb, 3);
    ListInster_Tail(Lb, 3);
    ListInster_Tail(Lb, 4);
    ListInster_Tail(Lb, 6);
    ListInster_Tail(Lb, 8);

    LinkList Lc;
    MergeList_L(La, Lb, &Lc);

    LNode *p = Lc->next;
    while (p) {
        printf("%d\n", p->data);
        p = p->next;
    }

}

int main() {
    //    testSingleLinst();
    //    testDuLinkList();
    testSequenceList();
    //    test_merge_by_single_link_list();
}
