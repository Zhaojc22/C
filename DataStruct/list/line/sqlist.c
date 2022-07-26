#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

sqlist *sqlist_create()
{
    sqlist *me;

    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    me->last = -1;

    return me;
}

void sqlist_create1(sqlist **ptr)
{
    *ptr = malloc(sizeof(**ptr));

    if(*ptr == NULL)
        return;
    (*ptr)->last = -1;

    return;  
}

int sqlist_insert(sqlist *me, int i, datatype *data)
{
    int j;

    if(me->last == DATASIZE - 1)
        return -1;
    if(i < 0 || i > me->last + 1)
        return -2;

    for(j = me->last; j >= i; j--)
        me->data[j+1] = me->data[j];

    me->data[i] = *data;
    me->last++;

    return 0;
}

int sqlist_delete(sqlist *me, int i)
{
    if(i < 0 || i > me->last)
        return -1;
    for(int j = i; j <= me->last; j++)
    {
        me->data[j] = me->data[j+1];
    }
    me->last--;
    return 0;
}

int sqlist_find(sqlist *me, datatype *data)
{
    if(sqlist_is_empty(me) == 0)
        return -1;
    for(int i = 0; i <= me->last; i++)
    {
        if(me->data[i] == *data)
            return i;
    }
    return -2;
}

int sqlist_is_empty(sqlist *me)
{
    if(me->last == -1)
        return 0;
    return -1;
}

int sqlist_set_empty(sqlist *me)
{
    me->last == -1;
    return 0;
}

int sqlist_get_memebr(sqlist *me)
{
    return (me->last + 1);
}

void sqlist_display(sqlist *me)
{
    if(me->last == -1)
        return;

    for(int i = 0; i <= me->last; i++)
        printf("%d ", me->data[i]);
    printf("\n");

    return;
}

int sqlist_destory(sqlist *me)
{
    free(me);
    return 0;
}

int sqlist_union(sqlist *me1, sqlist *me2)
{
    for(int i = 0; i <= me2->last; i++)
    {
        if(sqlist_find(me1, &me2->data[i]) < 0)
            sqlist_insert(me1, 0, &me2->data[i]);
    }
    return 0;
}