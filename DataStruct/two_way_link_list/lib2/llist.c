#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

struct llist_node_st
{
    struct llist_node_st *prev;
    struct llist_node_st *next;
    char data[0];
};

// 封装
struct llist_head_st
{
    int size;
    struct llist_node_st head;
};

LLIST *llist_create(int init_size)
{
    struct llist_head_st *me;

    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;

    me->size = init_size;
    me->head.prev = &me->head;
    me->head.next = &me->head;
    return me;
}

int llist_insert(LLIST *p, const void *data, int mode)
{
    struct llist_head_st *ptr = p;
    struct llist_node_st *node;
    node = malloc(sizeof(*node) + ptr->size);
    if (node == NULL)
        return -1;

    memcpy(node->data, data, ptr->size);

    if (mode == LLIST_FORWARD)
    {
        node->prev = &ptr->head;
        node->next = ptr->head.next;
    }
    else if (mode == LILIST_BACKWARD)
    {
        node->prev = ptr->head.prev;
        node->next = &ptr->head;
    }
    else
    {
        return -3;
    }
    node->prev->next = node;
    node->next->prev = node;
    return 0;
}

static struct llist_node_st *find_(struct llist_head_st *ptr, const void *key, llist_cmp_call *cmp_call)
{
    struct llist_node_st *cur;
    for (cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        if (cmp_call(key, cur->data) == 0)
            break;
    }
    return cur;
}

void *llist_find(LLIST *p, const void *key, llist_cmp_call *cmp_call)
{
    struct llist_head_st *ptr = p;
    struct llist_node_st *node;
    node = find_(ptr, key, cmp_call);
    if (node == &ptr->head)
        return NULL;
    return node->data;
}

int llist_delete(LLIST *p, const void *key, llist_cmp_call *cmp_call)
{
    struct llist_head_st *ptr = p;
    struct llist_node_st *target;
    target = find_(ptr, key, cmp_call);
    if (target == &ptr->head)
        return -1;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    free(target);
    return 0;
}

int llist_fetch(LLIST *p, const void *key, llist_cmp_call *cmp_call, void *data)
{
    struct llist_node_st *target;
    struct llist_head_st *ptr = p;
    target = find_(ptr, key, cmp_call);
    if (target == &ptr->head)
        return -1;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    if (data != NULL)
        memcpy(data, target->data, ptr->size);
    free(target);
    return 0;
}

void llist_display(LLIST *p, llist_print_call *print_call)
{
    struct llist_node_st *cur;
    struct llist_head_st *ptr = p;
    for (cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        print_call(cur->data);
    }
}

void llist_destory(LLIST *p)
{
    struct llist_head_st *ptr = p;
    struct llist_node_st *cur, *next;
    for (cur = ptr->head.next; cur != &ptr->head; cur = next)
    {
        next = cur->next;
        free(cur);
    }
    free(ptr);
}