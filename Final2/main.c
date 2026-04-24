#include "computePostfix.c"
#include "infixToPostfix.c"
#include "queue.c"
#include "stack.c"
#include "helper.c"

int main(void)
{
        Token tokenSequence[MAX];
        Queue postfix;

        int keep_running = 1;
        int tokenSize;
        
        char input[MAX];

        while (keep_running == 1)
        {
                fgets(input, MAX + 1, stdin);

                if (strcmp(input, "QUIT\n") == 0 || strcmp(input, "QUIT") == 0)
                {
                keep_running = 0;
                }
                else
                {
                        CreateQueue(&postfix);
                        tokenSize = processTokens(input, tokenSequence);
                        infixToPostfix(tokenSequence, tokenSize, &postfix);

                        for (int i = 0; i < postfix.size; i++)
                        {
                                int index = (postfix.head + i) % MAX;
                                printf("%s ", postfix.list[index]);
                        }
                        printf("\n");

                        computePostFix(postfix);
                }
                printf("\n");
        }
}
