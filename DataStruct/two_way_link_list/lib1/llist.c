#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

LLIST *llist_create(int init_size)
{
    LLIST *me;

    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;

    me->size = init_size;
    me->head.data = NULL;
    me->head.prev = &me->head;
    me->head.next = &me->head;

    return me;
}

int llist_insert(LLIST *ptr, const void *data, int mode)
{
    struct llist_node_st *node;
    node = malloc(sizeof(*node));
    if (node == NULL)
        return -1;

    node->data = malloc(ptr->size);
    if (node->data == NULL)
        return -2;

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
    return find_(ptr, key, cmp_call)->data;
}

int llist_delete(LLIST *ptr, const void *key, llist_cmp_call *cmp_call)
{
    struct llist_node_st *target;
    target = find_(ptr, key, cmp_call);
    if(target == &ptr->head)
        return -1;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    free(target->data);
    free(target);
    return 0;
}

int llist_fetch(LLIST *ptr, const void *key, llist_cmp_call *cmp_call, void * data)
{
    struct llist_node_st *target;
    target = find_(ptr, key, cmp_call);
    if(target == &ptr->head)
        return -1;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    if(data != NULL)
        memcpy(data, target->data, ptr->size);
    free(target->data);
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
    for (cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        next = cur->next;
        free(cur->data);
        free(cur);
    }
    free(ptr);
}