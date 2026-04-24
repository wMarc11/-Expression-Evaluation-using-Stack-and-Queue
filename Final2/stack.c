#include <stdio.h>
#include "stack.h"

int StackEmpty(Stack *S)
{
    return S->top == -1;
}

int StackFull(Stack *S)
{
    return S->top == MAX - 1;
}

void CreateStack(Stack *S)
{
    S->top = -1;
}

void Push(Stack *S, char x[])
{
    if (StackFull(S))
    {
        printf("Overflow error\n");
    } else
    {
        S->top++;
        int j = 0;
        while (x[j] != '\0' && j < TOKEN_SIZE - 1) {
            S->data[S->top][j] = x[j];
            j++;
        }
        S->data[S->top][j] = '\0';
    }
}

char* Pop(Stack *S)
{
    if (StackEmpty(S))
    {
        printf("Underflow error\n");
        return "";
    } else {
        return S->data[S->top--];
    }
}

char* Top(Stack *S)
{
    if (StackEmpty(S))
    {
        printf("Stack is empty\n");
        return "";
    }
    return S->data[S->top];
}
