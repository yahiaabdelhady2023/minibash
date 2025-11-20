#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

int main()
{

        while (1)
        {

                char *prompt;
                char target[] = "clear";

                while ((prompt = readline("\n Enter CMD: ")) != NULL)
                {
                        printf("\n prompt ==>  %s", prompt);
                        add_history(prompt); // saves each line string, user can move through via arrow key or arrow key down
                        free(prompt);        // very important do not forget to clear to avoid memory leakage

                        if (strcmp(prompt, target) == 0)
                        {
                                rl_clear_history(); // clears working directory in linux
                        }
                }
        }

        return 0;
}
