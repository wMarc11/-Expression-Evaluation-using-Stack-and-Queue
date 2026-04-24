#include <stdio.h>
#include <string.h>
#include "queue.h"

int QueueEmpty(Queue *Q)
{
    return Q->size == 0;
}

int QueueFull(Queue *Q)
{
    return Q->size == MAX;
}

void CreateQueue(Queue *Q)
{
    Q->size = 0;
    Q->head = 0;
    Q->tail = 0;
}

void Enqueue(Queue *Q, char x[])
{
    if (QueueFull(Q)) {
        printf("Queue is full! Can't add any more elements!\n");
    } else {
        strncpy(Q->list[Q->tail], x, TOKEN_SIZE - 1);
        Q->list[Q->tail][TOKEN_SIZE - 1] = '\0';
        Q->tail = (Q->tail + 1) % MAX;
        Q->size++;
    }
}

char* Dequeue(Queue *Q)
{
    if (!QueueEmpty(Q))
    {
        char *x = Q->list[Q->head];
        Q->head = (Q->head + 1) % MAX;
        Q->size--;
        return x;
    } else
    {
        printf("Queue is empty!\n");
        return "";
    }
}

char* QueueHead(Queue *Q)
{
    if (!QueueEmpty(Q))
    {
        return Q->list[Q->head];
    } else {
        printf("Queue is empty!\n");
        return "";
    }
}
