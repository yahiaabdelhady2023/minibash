#include <stdio.h>
#include <stdlib.h>

char echo_message(char *text_buffer)
{

    printf("%s\n", text_buffer);
}

int main()
{
    char *text_buffer = "minecraft";

    echo_message(text_buffer);
    return 0;
}