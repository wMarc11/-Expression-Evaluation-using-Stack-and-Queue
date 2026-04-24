#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"
#include "queue.h"
#include "helper.h"

void infixToPostfix(Token* tokenSequence, int tokenSeqSize, Queue *postfixQ) {
    Stack opStack;
    int i;
    Token token;
    CreateStack(&opStack);

    for (i = 0; i < tokenSeqSize; i++) {
        strcpy(token, tokenSequence[i]);

        if (strcmp(token, "(") == 0) {
            Push(&opStack, token);
        }
        else if (strcmp(token, ")") == 0) {
            while (!StackEmpty(&opStack) && strcmp(Top(&opStack), "(") != 0) {
                Enqueue(postfixQ, Pop(&opStack));
            }
            if (!StackEmpty(&opStack) && strcmp(Top(&opStack), "(") == 0) {
                Pop(&opStack);
            }
        }
        else if (isOperator(token)) {
            while (!StackEmpty(&opStack) && (precedence(Top(&opStack)) >= precedence(token) &&
            (precedence(Top(&opStack)) > precedence(token) || !isRightAssociative(token)))) {
                Enqueue(postfixQ, Pop(&opStack));
            }
            Push(&opStack, token);
        }
        else {
            Enqueue(postfixQ, token);
        }
    }

    while (!StackEmpty(&opStack)) {
        Enqueue(postfixQ, Pop(&opStack));
    }
}
