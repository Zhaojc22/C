#ifndef LLIST_H__
#define LLIST_H__


#define LLIST_FORWARD       1
#define LILIST_BACKWARD     2

typedef void llist_print_call(const void *);

typedef int llist_cmp_call(const void *, const void *);

struct llist_node_st
{
    void *data;
    struct llist_node_st *prev;
    struct llist_node_st *next;
};

typedef struct
{
    int size;
    struct llist_node_st head;
}LLIST;

LLIST *llist_create(int init_size);

int llist_insert(LLIST *,const void *data, int mode);

void *llist_find(LLIST *, const void *key, llist_cmp_call *);

int llist_delete(LLIST *, const void *, llist_cmp_call *);

int llist_fetch(LLIST *, const void *, llist_cmp_call *, void * data);

void llist_display(LLIST *, llist_print_call *);

void llist_destory(LLIST *);



#endif