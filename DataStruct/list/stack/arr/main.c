#include<stdio.h>
#include<stdlib.h>

#include "sqstack.h"

int main()
{
    datatype arr[] = {19,23,0,15,67};
    int i, ret;
    datatype pop_data;
    sqstack *st;
    st = sqstack_create();
    if(st == NULL)
        exit(1);

    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
        sqstack_push(st, &arr[i]);

    sqstack_travel(st);

#if 0
    ret = sqstack_push(st, &arr[0]);
    if(ret)
        printf("push failed!\n");
    else
        sqstack_travel(st);
    // sqstack_pop();
#endif 

    while(sqstack_pop(st, &pop_data) == 0)
    {
        printf("Pop: %d\n", pop_data);
    }

    sqstack_destory(st);


    return 0;
}