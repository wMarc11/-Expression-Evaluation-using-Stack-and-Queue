#ifndef queue
#define queue

#include <stdio.h>
#include <string.h>
#include "helper.h"

typedef struct
{
    char list[MAX][TOKEN_SIZE];
    int size;
    int head;
    int tail;
} Queue;

int QueueEmpty(Queue *Q);

int QueueFull(Queue *Q);

void CreateQueue(Queue *Q);

void Enqueue(Queue *Q, char x[]);

char* Dequeue(Queue *Q);

char* QueueHead(Queue *Q);

#endif