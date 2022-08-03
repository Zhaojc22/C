#include<stdio.h>
#include<stdlib.h>

#include "nohead.h"

int list_insert(struct node_st **me, struct score_st *data)
{
    struct node_st *new;
    new = malloc(sizeof(*new));
    if(new == NULL)
        return -1;
    new->data = *data;
    new->next = NULL;

    new->next = *me;
    *me = new;
    return 0;
}
int list_delete(struct node_st **me)
{
    struct node_st *cur;
    if(*me == NULL)
        return -1;
    cur = *me;
    *me = (*me)->next;
    free(cur);
    return 0;
}
struct score_st *  list_find(struct node_st *me, int id)
{
    struct node_st *cur;
    for(cur = me; cur != NULL; cur = cur->next)
    {
        if(cur->data.id == id)
        {
            return &cur->data;
        }
    }
    return NULL;
}

void list_display(struct node_st *me)
{
    struct node_st *cur;
    for(cur = me; cur != NULL; cur = cur->next)
    {
        printf("%d %s %d %d \n", cur->data.id, cur->data.name, cur->data.math, cur->data.chinese);
    }
}

void list_destory(struct node_st *me)
{
    struct node_st *cur;

    if(me == NULL)
        return;

    for(cur = me; cur != NULL; cur = me)
    {
        me = cur->next;
        free(cur);
    }
}
