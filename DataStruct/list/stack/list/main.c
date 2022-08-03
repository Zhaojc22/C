#include<stdio.h>
#include<stdlib.h>

#include "stack.h"

#define NAMESIZE   32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

void print_score(struct score_st *score)
{
    printf("%d %s %d %d\n", score->id, score->name, score->math, score->chinese);
}


int main()
{
    STACK *ST;
    struct score_st tmp;
    struct score_st *pop_data;
    int i;
    ST = stack_create(sizeof(struct score_st));
    if(ST == NULL)
        exit(1);

    for(i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "Stu%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        printf("%d %s %d %d\n", tmp.id, tmp.name, tmp.math, tmp.chinese);
        if(stack_push(ST, &tmp))
            exit(1);
    }
    printf("\n\n\n");
    while(1)
    {
        if(stack_pop(ST, pop_data))
            break;
        print_score(pop_data);
    }
    stack_destory(ST);
    exit(0);
}