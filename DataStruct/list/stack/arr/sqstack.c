#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

sqstack *sqstack_create(void)
{
    sqstack *st;

    st = malloc(sizeof(*st));
    if (st == NULL)
        return NULL;

    st->top = -1;
    return st;
}

int sqstack_is_Empty(sqstack *st)
{
    return (st->top == -1);
}

int sqstack_push(sqstack *st, datatype *data)
{
    if (st->top == MAXSIZE - 1)
        return -1;

    st->data[++st->top] = *data;
    return 0;
}

int sqstack_pop(sqstack *st, datatype *data)
{
    if (sqstack_is_Empty(st))
        return -1;
    *data = st->data[st->top--];
    return 0;
}

int sqstack_top(sqstack *st, datatype *data)
{
    if (sqstack_is_Empty(st))
        return -1;
    *data = st->data[st->top];
    return 0;
}

void sqstack_travel(sqstack *st)
{
    if (sqstack_is_Empty(st))
        return;
    for (int i = 0; i <= st->top; i++)
        printf("%d ", st->data[i]);
    printf("\n");
}

void sqstack_destory(sqstack *st)
{
    free(st);
}