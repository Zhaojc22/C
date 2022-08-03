#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{
    datatype arr[] = {2, 34, 12, 125};
    int i;

    queue *sq;
    sq = queue_create();
    if (sq == NULL)
        exit(1);

    for (i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        queue_entry(sq, &arr[i]);

    queue_travel(sq);
    exit(0);
}