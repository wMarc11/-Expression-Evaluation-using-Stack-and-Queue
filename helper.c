#include <string.h>
#include <math.h>
#include "helper.h"

int isOperator(Token x)
{
    return strcmp(x, "+") == 0 || strcmp(x, "-") == 0 || strcmp(x, "/") == 0 || strcmp(x, "%") == 0 ||
           strcmp(x, "*") == 0 || strcmp(x, "^") == 0 || strcmp(x, ">") == 0 || strcmp(x, "<") == 0 ||
           strcmp(x, ">=") == 0 || strcmp(x, "<=") == 0 || strcmp(x, "!=") == 0 || strcmp(x, "==") == 0 ||
           strcmp(x, "!") == 0 || strcmp(x, "&&") == 0 || strcmp(x, "||") == 0;
}

int isRightAssociative(Token op)
{
    return strcmp(op, "^") == 0 || strcmp(op, "!") == 0;
}

int Hash(Token Operator)
{
    if (strcmp(Operator, "+") == 0)
        return 1;
    else if (strcmp(Operator, "-") == 0)
        return 2;
    else if (strcmp(Operator, "/") == 0)
        return 3;
    else if (strcmp(Operator, "%") == 0)
        return 4;
    else if (strcmp(Operator, "*") == 0)
        return 5;
    else if (strcmp(Operator, "^") == 0)
        return 6;
    else if (strcmp(Operator, ">") == 0)
        return 7;
    else if (strcmp(Operator, "<") == 0)
        return 8;
    else if (strcmp(Operator, ">=") == 0)
        return 9;
    else if (strcmp(Operator, "<=") == 0)
        return 10;
    else if (strcmp(Operator, "!=") == 0)
        return 11;
    else if (strcmp(Operator, "==") == 0)
        return 12;
    else if (strcmp(Operator, "&&") == 0)
        return 13;
    return 14; // For " || " Operator
}

int precedence(Token op)
{
    if (strcmp(op, "||") == 0)
        return 1;
    else if (strcmp(op, "&&") == 0)
        return 2;
    else if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0)
        return 3;
    else if (strcmp(op, ">") == 0 || strcmp(op, "<") == 0 ||
            strcmp(op, ">=") == 0 || strcmp(op, "<=") == 0)
        return 4;
    else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
        return 5;
    else if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0 ||
             strcmp(op, "%") == 0)
        return 6;
    else if (strcmp(op, "^") == 0)
        return 7;
    else if (strcmp(op, "!") == 0)
        return 8;
    else
        return 0;
}

int processTokens(char* input, Token* tokenSequence)
{
    int i = 0, j;
    int len = strlen(input);
    int tokenSeqSize = 0;
    Token token;

    while (i < len && input[i] != '\n') {
        if (input[i] >= '0' && input[i] <= '9') { // if number
            j = 0;

            while (i < len && input[i] >= '0' && input[i] <= '9' && j < TOKEN_SIZE - 1) {
                token[j++] = input[i];
                i++;
            }

            token[j] = '\0';
        } 
        else if ((input[i] == '>' || input[i] == '<' || input[i] == '!' || input[i] == '=') && input[i + 1] == '=') { // if relational
            token[0] = input[i++];
            token[1] = input[i++];
            token[2] = '\0';
        }
        else if (input[i] == '&' || input[i] == '|' ) { // if logical
            j = 0;
            token[j++] = input[i++];
            token[j++] = input[i++];
            token[j] = '\0';
        }
        else {
            token[0] = input[i];
            token[1] = '\0';
            i++;
        }
        strcpy(tokenSequence[tokenSeqSize], token);
        tokenSeqSize++;
    }

    return tokenSeqSize;
}

void convertToString(int Number, char* Token)
{
    int tempNum = Number, count = 0, Divider;

    Token[0] = '\0';

    if (Number < 0) {
        strcat(Token, "-");
        tempNum = -tempNum;
        Number = -Number;
    }
    
    if (Number == 0) {
        strcat(Token, "0");
    }
    else {
        while(tempNum != 0) {
            count++;
            tempNum /= 10;
        }
    
        Divider = (int) pow(10, count - 1); 
        do {
            switch (Number / Divider) {
                case 0: strcat(Token, "0"); break;
                case 1: strcat(Token, "1"); break; 
                case 2: strcat(Token, "2"); break;
                case 3: strcat(Token, "3"); break;
                case 4: strcat(Token, "4"); break;
                case 5: strcat(Token, "5"); break;
                case 6: strcat(Token, "6"); break;
                case 7: strcat(Token, "7"); break;
                case 8: strcat(Token, "8"); break;
                case 9: strcat(Token, "9"); break;
            }
            Number %= Divider; 
            Divider /= 10; 
        } while (Divider != 0);
    }
}

int convertToNum(char* String)
{
    int i = 0, number = 0, hasNegativeSign = 0;

    if (String[i] == '-') {
        hasNegativeSign = 1;
        i++;
    }

    while (String[i] != '\0') {
        number = number * 10 + (String[i] - '0');
        i++;
    }

    if (hasNegativeSign)
        number = -number;

    return number;
}

void Evaluate(int Operand1, int Operand2, Token Operator, Token Return)
{
    int Hashed = Hash(Operator);
    int Result;
    Token token;
    
    switch (Hashed) {
        case 1:
            Result = Operand1 + Operand2; break;
        case 2:
            Result = Operand1 - Operand2; break;
        case 3:
            Result = Operand1 / Operand2; break;
        case 4:
            Result = Operand1 % Operand2; break;
        case 5:
            Result = Operand1 * Operand2; break;
        case 6:
            Result = (int) pow(Operand1, Operand2); break;
        case 7:
            Result = Operand1 > Operand2; break;
        case 8:
            Result = Operand1 < Operand2; break;
        case 9:
            Result = Operand1 >= Operand2; break;
        case 10:
            Result = Operand1 <= Operand2; break;
        case 11:
            Result = Operand1 != Operand2; break;
        case 12:
            Result = Operand1 == Operand2; break;
        case 13:
            Result = Operand1 && Operand2; break;
        case 14:
            Result = Operand1 || Operand2; break;
    }

    convertToString(Result, token);
    strcpy(Return, token);
}
