#include<stdio.h>
#include<stdlib.h>

struct node_st
{
    int coef;   //系数
    int exp;    //指数
    struct node_st *next;
};

struct node_st *poly_create(int a[][2], int n)
{
    struct node_st *me, *nnode, *cur;
    int i;
    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;

    me->next = NULL;

    cur = me;

    for(i = 0; i < n; i++)
    {
        nnode = malloc(sizeof(*nnode));
        if(nnode == NULL)
            return NULL;

        nnode->coef = a[i][0];
        nnode->exp = a[i][1];
        nnode->next = NULL;

        cur->next = nnode;
        cur = nnode;
    }
    return me;
}

void poly_displey(struct node_st *me)
{
    struct node_st *cur;
    for(cur = me->next; cur != NULL; cur = cur->next)
    {
        printf("(%d, %d) ",cur->coef, cur->exp);
    }

    printf("\n");
}

int main()
{
    int arr1[][2] = {{5,0},{2,1},{8,8},{3,16}};
    int arr2[][2] = {{6,1},{16,6},{-8,8}};
    struct node_st *p1, *p2;
    p1 = poly_create(arr1,4);
    if( p1== NULL)
        exit(1);

    p2 = poly_create(arr2,3);
    if( p2== NULL)
        exit(1);


    poly_displey(p1);

    poly_displey(p2);
    return 0;
}