#ifndef NOHEAD_H__
#define NOHEAD_H__

#define NAMESIEZ    32

struct score_st
{
    int id;
    char name[NAMESIEZ];
    int math;
    int chinese;
};

struct node_st
{
    struct score_st data;
    struct node_st *next;
};

int list_insert(struct node_st **, struct score_st *);

int list_delete(struct node_st **);

struct score_st * list_find(struct node_st *, int);

void list_display(struct node_st *);

void list_destory(struct node_st *);

#endif