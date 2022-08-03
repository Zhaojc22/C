#include<stdio.h>
#include<stdlib.h>

#include "list.h"

int main()
{
    list *l;
    int err = 0;
    datatype arr[] = {12,6,23,9,34,3,45};

    l = list_create();
    if(l == NULL)
        exit(1);

    for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {

        if(list_order_insert(l, &arr[i]))
            exit(1);
    }

    list_display(l);

#if 0
    list_delete(l, &arr[0]);
#endif

#if 1
    datatype value;
    err = list_delete_at(l, 2, &value);
    if(err)
        exit(1);
    printf("delete:%d\n", value);
#endif

    list_display(l);

    list_destory(l);

    return 0;
}