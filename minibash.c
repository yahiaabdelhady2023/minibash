#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{

        printf("\nAsk me random questions:");

        char *prompt;
        readline("Enter cmd : ");

        printf("Result of prompt is : %s",prompt);

        return 0;
}
