#ifndef QUEUE_H__
#define QUEUE_H__

#define MAXSIZE 5
typedef int datatype;

typedef struct node_st
{
    datatype data[MAXSIZE];
    int head;
    int tail;
} queue;

queue *queue_create();

int queue_is_empty(queue *);

int queue_entry(queue *, datatype *);

int queue_export(queue *, datatype *);

void queue_travel(queue *);

void queue_clear(queue *);

void queue_destory(queue *);

#endif