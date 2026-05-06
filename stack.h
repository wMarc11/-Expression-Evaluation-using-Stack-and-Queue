#ifndef stack
#define stack

#include <stdio.h>
#include "helper.h"

typedef struct {
    char data[MAX][TOKEN_SIZE];
    int top;
} Stack;

int StackEmpty(Stack *S);

int StackFull(Stack *S);

void CreateStack(Stack *S);

void Push(Stack *S, char x[]);

char* Pop(Stack *S);

char* Top(Stack *S);

#endif