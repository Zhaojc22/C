#include<stdio.h>
#include<stdlib.h>

#include "sqlist.h"

int main()
{
    sqlist *list = NULL;
    sqlist *list1 = NULL;
    datatype arr[] = {12,23,34,45,56};
    datatype arr1[] = {78,89,45,26,13};
    int i;
    int ret;
    list = sqlist_create();
    sqlist_create1(&list1);

    if(list == NULL || list1 == NULL)
    {
        fprintf(stderr, "sqlist_create failed\n");
        exit(1);
    }

    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        if((ret = sqlist_insert(list, 0, &arr[i])) != 0)
        {
            if(ret == -1)
                fprintf(stderr, "The arr is full.\n");
            else if(ret == -2)
                fprintf(stderr, "The pos insert is wrong.\n");
            else
                fprintf(stderr, "Error!\n");
            exit(1);
        }
    }

    for(i = 0; i < sizeof(arr1)/sizeof(*arr1); i++)
    {
        if((ret = sqlist_insert(list1, 0, &arr1[i])) != 0)
        {
            if(ret == -1)
                fprintf(stderr, "The arr is full.\n");
            else if(ret == -2)
                fprintf(stderr, "The pos insert is wrong.\n");
            else
                fprintf(stderr, "Error!\n");
            exit(1);
        }
    }

    sqlist_display(list);
    sqlist_display(list1);
#if 0
    ret = sqlist_delete(list, 1);
#endif
    sqlist_union(list, list1);
    sqlist_display(list);

    sqlist_destory(list);
    sqlist_destory(list1);

    return 0;
}