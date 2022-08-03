#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

int llist_insert(LLIST *,const void *data, int mode);
void *llist_find(LLIST *, const void *key, llist_cmp_call *);
int llist_delete(LLIST *, const void *, llist_cmp_call *);
int llist_fetch(LLIST *, const void *, llist_cmp_call *, void * data);
void llist_display(LLIST *, llist_print_call *);

LLIST *llist_create(int init_size)
{
    LLIST *me;

    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;

    me->size = init_size;
    me->head.prev = &me->head;
    me->head.next = &me->head;

    me->insert = llist_insert;
    me->delete = llist_delete;
    me->find = llist_find;
    me->fetch = llist_fetch;
    me->display = llist_display;

    return me;
}

int llist_insert(LLIST *ptr, const void *data, int mode)
{
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

static struct llist_node_st *find_(LLIST *ptr, const void *key, llist_cmp_call *cmp_call)
{
    struct llist_node_st *cur;
    for (cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        if (cmp_call(key, cur->data) == 0)
            break;
    }
    return cur;
}

void *llist_find(LLIST *ptr, const void *key, llist_cmp_call *cmp_call)
{
    struct llist_node_st *node;
    node = find_(ptr, key, cmp_call);
    if (node == &ptr->head)
        return NULL;
    return node->data;
}

int llist_delete(LLIST *ptr, const void *key, llist_cmp_call *cmp_call)
{
    struct llist_node_st *target;
    target = find_(ptr, key, cmp_call);
    if (target == &ptr->head)
        return -1;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    free(target);
    return 0;
}

int llist_fetch(LLIST *ptr, const void *key, llist_cmp_call *cmp_call, void *data)
{
    struct llist_node_st *target;
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

void llist_display(LLIST *ptr, llist_print_call *print_call)
{
    struct llist_node_st *cur;
    for (cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        print_call(cur->data);
    }
}

void llist_destory(LLIST *ptr)
{
    struct llist_node_st *cur, *next;
    for (cur = ptr->head.next; cur != &ptr->head; cur = next)
    {
        next = cur->next;
        free(cur);
    }
    free(ptr);
}