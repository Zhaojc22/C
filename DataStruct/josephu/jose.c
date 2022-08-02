/*
 * @Author: Zhaojc
 * @Date: 2022-08-02 10:01:44
 * @LastEditTime: 2022-08-02 10:30:29
 * @Descripttion: 约瑟夫环简单实现
 * 这个程序要注意kill函数中二级指针的操作
 */
#include<stdio.h>
#include<stdlib.h>

#define JOSE_NUM    8

struct node_st
{
    int id;
    struct node_st *next;
};
/**
 * @description: 创建单向环链，没有头节点
 * @param {int} n  环链中元素个数
 * @return {*}  结构体指针
 */
struct node_st * jose_create(int n)
{
    int i = 1;
    struct node_st *list, *cur;
    struct node_st *node;
    list = malloc(sizeof(*list));
    if(list == NULL)
        return NULL;
    list->id = i;
    list->next = list;
    cur = list;
    i++;
    for( ; i <= n; i++)
    {
        node = malloc(sizeof(*node));
        if(node == NULL)
            return NULL;
        node->id = i;
        node->next = list;
        cur->next = node;
        cur = node;
    }
    return list;
}

void jose_display(struct node_st *me)
{
    struct node_st *cur;
    for(cur = me; cur->next != me; cur = cur->next)
    {
        printf("id = %d\n", cur->id);
    }
    printf("id = %d\n", cur->id);
}

void jose_kill(struct node_st **me, int n)
{
    struct node_st *cur, *q;
    cur = *me;
    int i = 1;
    while(cur != cur->next)
    {
        while(i < n)
        {
            q = cur;
            cur = cur->next;
            i++;
        }
        printf("delete = %d\n", cur->id);
        q->next = cur->next;
        free(cur);
        cur = q->next;
        i = 1;
    }
    // 这里是二级指针的关键
    *me = cur;
}

int main()
{
    struct node_st *list;
    int kill_n = 3;

    list = jose_create(JOSE_NUM);
    if(list == NULL)
        exit(1);
        
    jose_display(list);

    jose_kill(&list, kill_n);

    jose_display(list);

    return 0;
}