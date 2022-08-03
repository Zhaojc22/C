#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

queue *queue_create()
{
    queue *sq;
    sq = malloc(sizeof(*sq));
    if (sq == NULL)
        return NULL;
    sq->head = 0;
    sq->tail = 0;
    return sq;
}

int queue_is_empty(queue *sq)
{
    if (sq->tail == sq->head)
        return -1;
    return 0;
}

int queue_entry(queue *sq, datatype *data)
{
    if ((sq->tail + 1) % MAXSIZE == sq->head)
        return -1;
    sq->tail = (sq->tail + 1) % MAXSIZE;
    sq->data[sq->tail] = data;
    return 0;
}

int queue_export(queue *sq, datatype *data)
{
}

void queue_travel(queue *sq)
{
    int i;
    if (queue_is_empty(sq))
    {
        i = (sq->head + 1) % MAXSIZE;
        while (i != sq->tail)
        {
            printf("%d ", sq->data[i]);
            i = (i + 1) % MAXSIZE;
        }
        printf("\n");
    }
}

void queue_clear(queue *sq)
{
}

void queue_destory(queue *sq)
{
    free(sq);
}
