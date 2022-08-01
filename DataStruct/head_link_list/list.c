#include<stdio.h>
#include<stdlib.h>

#include "list.h"

list *list_create()
{
    list *me;
    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    me->next == NULL;
    return me;
}

int list_insert_at(list *me, int i, datatype *data)
{
    int j = 0;
    list *node = me;
    list *nnode;
    if(i < 0)
        return -1;
    while(j < i && node != NULL)
    {
        node = node->next;
        j++;
    }
    if(node)
    {
        nnode = malloc(sizeof(*nnode));
        if(nnode == NULL)
            return -3;
        nnode->data = *data;
        nnode->next = node->next;
        node->next = nnode;
        return 0;
    }
    else 
        return -2;
}

int list_order_insert(list *me, datatype *data)
{
    list *p = me, *q;

    while (p->next && p->next->data < *data)
        p = p->next;

    q = malloc(sizeof(*q));
    if (q == NULL)
        return -1;

    q->data = *data;
    q->next = p->next;
    p->next = q;
    
    return 0;
}

int list_delete_at(list *me, int i, datatype *data)
{
    int j = 0;
    list *p = me, *q;
    *data = NULL;

    if( i < 0)
        return -1;
    while(j < i && p)
    {
        p = p->next;
        j++;
    }
    if(p)
    {
        q = p->next;
        p->next = q->next;
        *data = q->data;
        q = NULL;
        return 0;
    }
    else
        return -2;
}
int list_delete(list *me, datatype *data)
{
    list *p = me, *q;
    while(p->next && p->next->data != *data)
        p = p->next;
    if(p->next == NULL)
        return -1;
    else
    {
        q = p->next;
        p->next = q->next;
        free(q);
        q = NULL;
    }
    return 0;
}
int list_is_empty(list *me)
{
    if(me->next == NULL)
        return 0;
    return -1;
}


void list_display(list *me)
{
    list *node = me->next;
    if(list_is_empty(me) == 0)
        return ;
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    return;
}
void list_destory(list *me)
{
    list *node, *next;
    for(node = me->next; node != NULL; node = next)
    {
        next = node->next;
        free(node);
    }
    free(me);
    return;
}
