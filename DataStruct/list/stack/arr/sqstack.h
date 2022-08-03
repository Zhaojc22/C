#ifndef SQSTACK_H__
#define SQSTACK_H__

#define MAXSIZE 5
typedef int datatype;

typedef struct node_st
{
    datatype data[MAXSIZE];
    int top;
} sqstack;

sqstack *sqstack_create(void);

int sqstack_is_Empty(sqstack *);

int sqstack_push(sqstack *, datatype *);

int sqstack_pop(sqstack *, datatype *);

int sqstack_top(sqstack *, datatype *);

void sqstack_travel(sqstack *);

void sqstack_destory(sqstack *);
#endif