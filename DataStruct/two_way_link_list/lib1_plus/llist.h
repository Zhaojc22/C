#ifndef LLIST_H__
#define LLIST_H__


#define LLIST_FORWARD       1
#define LILIST_BACKWARD     2

typedef void llist_print_call(const void *);

typedef int llist_cmp_call(const void *, const void *);

// 使用变长结构体来是实现,这里data[0]只有在C99上才支持,以前的可以写char data[1];然后在创建的时候减掉4就行了
struct llist_node_st
{
    struct llist_node_st *prev;
    struct llist_node_st *next;
    char data[0];
};

// 封装
typedef struct llist_head
{
    int size;
    struct llist_node_st head;
    int (*insert)(struct llist_head *, const void *, int);
    void *(*find)(struct llist_head *, const void *, llist_cmp_call *);
    int (*delete)(struct llist_head *, const void *, llist_cmp_call *);
    int (*fetch)(struct llist_head *, const void *, llist_cmp_call *, void *);
    void (*display)(struct llist_head *, llist_print_call *);
    
}LLIST;

LLIST *llist_create(int init_size);

int llist_insert(LLIST *,const void *data, int mode);

void *llist_find(LLIST *, const void *key, llist_cmp_call *);

int llist_delete(LLIST *, const void *, llist_cmp_call *);

int llist_fetch(LLIST *, const void *, llist_cmp_call *, void * data);

void llist_display(LLIST *, llist_print_call *);

void llist_destory(LLIST *);



#endif