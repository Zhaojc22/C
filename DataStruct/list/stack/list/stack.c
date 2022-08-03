#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

LLIST *stack_create(int init_size)
{
    return llist_create(init_size);
}

int stack_push(STACK *ptr, void *data)
{
    return llist_insert(ptr, data, LLIST_FORWARD);
}
static int always_match(const void *p, const void *q)
{
    return 0;
}

int stack_pop(STACK *ptr, void *data)
{
    return llist_fetch(ptr, (void *)0, always_match, data);
}

void stack_destory(STACK *ptr)
{
    llist_destory(ptr);
}