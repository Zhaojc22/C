#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

#define NAMESIZE 32
struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

static void print_callback(const void *record)
{
    const struct score_st *r = record;
    printf("%d %s %d %d \n", r->id, r->name, r->math, r->chinese);
}

static int cmp_id_callback(const void *key, const void  *record)
{
    const int *k = key;
    const struct score_st *r = record;
    return (*k - r->id);
}

static int cmp_name_callback(const void *key, const void *record)
{
    const char *k = key;
    const struct score_st *r = record;
    return  strcmp(k, r->name);
}

int main()
{
    int i, ret;
    LLIST *handler;
    struct score_st tmp;
    int id = 3;
    char *del_name = "Std5";
    struct score_st *find_ret;
    handler = llist_create(sizeof(struct score_st));
    if (handler == NULL)
        exit(1);

    for (i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "Std%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        ret = handler->insert(handler, &tmp, LILIST_BACKWARD);

        if(ret)
            exit(1);
    }

    handler->display(handler, print_callback);
#if 0   
    printf("\n");

    find_ret = llist_find(handler, &id, cmp_id_callback);
    if(find_ret == NULL)
        printf("Not found!\n");
    else
        print_callback(find_ret);

    printf("根据id删除上面的找到的元素\n");
    ret = llist_delete(handler, &id, cmp_id_callback);
    if(ret)
        printf("delete filed!\n");

    llist_display(handler, print_callback);


    printf("根据名字删除上面的找到的元素\n");
    ret = llist_delete(handler, del_name, cmp_name_callback);
    if(ret)
        printf("delete filed!\n");

    llist_display(handler, print_callback);

    llist_destory(handler);
#endif
    return 0;
}