#include<stdio.h>
#include<stdlib.h>

#include "nohead.h"

int main()
{
    int i;
    int err;
    struct node_st *list = NULL;
    struct score_st tmp;
    struct score_st *ret;
    for(i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIEZ, "stu%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        err = list_insert(&list, &tmp);
        if(err != 0)
            break;
    }

    list_display(list);

    list_delete(&list);

    printf("\n\n");

    list_display(list);

    printf("\n\n");
    int find_id = 3;
    ret = list_find(list, find_id);
    if(ret == NULL)
        printf("list_find failed!\n");
    else
        printf("%d %s %d %d \n", ret->id, ret->name, ret->math, ret->chinese);
    
    list_destory(list);
    return 0;
}