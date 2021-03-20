#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "shell.h"

int main(int argc, char **argv)
{
    char *command;

    do
    {
        print_prompt1();

        command = read_cmd();

        if(!command)
        {
            exit(EXIT_SUCCESS);
        }

        if(command[0] == '\0' || strcmp(command, "\n") == 0)
        {
            free(command);
            continue;
        }

        if(strcmp(command, "exit\n") == 0)
        {
            free(command);
            break;
        }

        printf("%s\n", command);

        free(command);

    } while(1);

    exit(EXIT_SUCCESS);
}