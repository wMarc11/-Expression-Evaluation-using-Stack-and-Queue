#ifndef helper
#define helper

#include <string.h>
#include <math.h>

#define MAX 256
#define TOKEN_SIZE 256

typedef char Token[TOKEN_SIZE];

int isOperator(Token x);

int isRightAssociative(Token op);

int Hash(Token Operator);

int precedence(Token op);

int processTokens(char* input, Token* tokenSequence);

void convertToString(int Number, char* Token);

int convertToNum(char* String);

void Evaluate(int Operand1, int Operand2, Token Operator, Token Return);

#endif