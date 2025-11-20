#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute_program(char *path, char **arg_vector, char **env_args)
{
        pid_t pid;

        printf("\n Executing inside execute_program()");
        pid = fork();

        if (pid == -1)
        {
                perror("\n error happened while forking .. \n");
        }
        else if (pid == 0)
        {
                if (execve(path, arg_vector, env_args) == -1)
                {
                        perror("\n Error happened while executing execve()");
                }
        }
        else
        {
                // printf("\n waiting for child to execute first");
                int status;
                waitpid(pid, &status, 0);
                // printf("parent process : child finished with status %d \n", status);
        }
}

int main()
{

        char *prompt;
        char target[] = "exit";

        char path[] = "/bin/sh";
        char *arg_vector[] = {"sh", "-c", prompt, NULL};
        char *env_args[] = {NULL};

        while ((prompt = readline("\n Enter CMD: ")) != NULL)
        {
                printf("\n prompt ==>  %s", prompt);
                add_history(prompt); // saves each line string, user can move through via arrow key or arrow key down

                arg_vector[2]=prompt;
                
                execute_program(path, arg_vector, env_args); // executes external program e.g. ls

                free(prompt); // very important do not forget to clear to avoid memory leakage

                if (strcmp(prompt, target) == 0)
                {
                        rl_clear_history(); // clears working directory in linux
                }
        }

        return 0;
}
