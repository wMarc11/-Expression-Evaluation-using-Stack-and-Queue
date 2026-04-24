#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "helper.h"

void computePostFix(Queue Postfix)
{
    int Result;
    int Start, End;
    int num1, num2;
    int isError = 0;
    
    Stack Expression;
    Token x;
    Token operand1;
    Token operand2;
    Token operator;
    Token stringResult;

    CreateStack(&Expression);

    End = Postfix.tail;
    if (Postfix.head > Postfix.tail) {
        End += MAX;
    }

    for (Start = Postfix.head; Start < End; Start++) {
        strcpy(x, Postfix.list[Start % MAX]);
        if (!isOperator(x)) {
            Push(&Expression, x);
        }
        else {
            if (strcmp(x, "!") == 0) {
                strcpy(operand1, Pop(&Expression));
                num1 = convertToNum(operand1);
                num1 = !num1;
                convertToString(num1, stringResult);
            }
            else {
                strcpy(operand2, Pop(&Expression));
                strcpy(operand1, Pop(&Expression));
                strcpy(operator, x);
                num1 = convertToNum(operand1); 
                num2 = convertToNum(operand2);
                
                if (num2 == 0 && strcmp(operator, "/") == 0) {
                    isError = 1;
                    break;
                }    
                Evaluate(num1, num2, operator, stringResult);
            }        
            Push(&Expression, stringResult);
        }
    }
    
    if (isError) {
        printf("Division by zero error!\n");
    }
    else {
        Result = convertToNum(Pop(&Expression));
        printf("%d\n", Result);
    }
}
