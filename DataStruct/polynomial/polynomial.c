/*
 * @Author: Zhaojc
 * @Date: 2022-08-01 17:00:20
 * @LastEditTime: 2022-08-02 09:51:34
 * @Descripttion: 多项式合并具体实现
 */
#include <stdio.h>
#include <stdlib.h>

// 多项式节点结构体
struct node_st
{
    int coef; //系数
    int exp;  //指数
    struct node_st *next;
};
/**
 * @description: 创建多项式
 * @param {int} a 多项式表示，二维数组
 * @param {int} n 多项式项数
 * @return {*}  结构体指针
 */
struct node_st *poly_create(int a[][2], int n)
{
    struct node_st *me, *nnode, *cur;
    int i;
    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;

    me->next = NULL;

    cur = me;

    for (i = 0; i < n; i++)
    {
        nnode = malloc(sizeof(*nnode));
        if (nnode == NULL)
            return NULL;

        nnode->coef = a[i][0];
        nnode->exp = a[i][1];
        nnode->next = NULL;

        cur->next = nnode;
        cur = nnode;
    }
    return me;
}
/**
 * @description: 打印多项式,按照 (系数，指数) 的形式
 */
void poly_displey(struct node_st *me)
{
    struct node_st *cur;
    for (cur = me->next; cur != NULL; cur = cur->next)
    {
        printf("(%d, %d) ", cur->coef, cur->exp);
    }

    printf("\n");
}
/**
 * @description: 合并多项式
 * @param {node_st} *me1 多项式结构体指针1
 * @param {node_st} *me2 多项式结构体指针2
 */
void poly_union(struct node_st *me1, struct node_st *me2)
{
    struct node_st *p, *q;
    struct node_st *cur;
    p = me1->next;
    q = me2->next;
    cur = me1;
    while (p && q)
    {
        if (p->exp < q->exp)
        {
            cur->next = p;
            cur = p;
            p = p->next;
        }
        else if (p->exp > q->exp)
        {
            cur->next = q;
            cur = q;
            q = q->next;
        }
        else
        {
            p->coef += q->coef;
            if (p->coef)
            {
                cur->next = p;
                cur = p;
            }
            p = p->next;
            q = q->next;
        }
    }
    if (p)
        cur->next = p;
    else
        cur->next = q;
}

int main()
{
    int arr1[][2] = {{5, 0}, {2, 1}, {8, 8}, {3, 16}};
    int arr2[][2] = {{6, 1}, {16, 6}, {-8, 8}};
    struct node_st *p1, *p2;
    p1 = poly_create(arr1, 4);
    if (p1 == NULL)
        exit(1);

    p2 = poly_create(arr2, 3);
    if (p2 == NULL)
        exit(1);

    poly_displey(p1);

    poly_displey(p2);

    poly_union(p1, p2);

    poly_displey(p1);
    return 0;
}