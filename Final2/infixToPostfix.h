#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"
#include "queue.h"
#include "helper.h"

void infixToPostfix(Token* tokenSequence, int tokenSeqSize, Queue *postfixQ);