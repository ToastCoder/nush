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

        command = read_command();

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

char *read_command(void)
{
    char buffer[1024];
    char *pointer = NULL;
    char pointer_length = 0;

    while(fgets(buffer, 1024, stdin))
    {
        int buffer_length = strlen(buffer);

        if(!pointer)
        {
            pointer = malloc(buffer_length+1);
        }
        else
        {
            char *pointer2 = realloc(pointer, pointer_length+buffer_length+1);

            if(pointer2)
            {
                pointer = pointer2;
            }
            else
            {
                free(pointer);
                pointer = NULL;
            }
        }

        if(!pointer)
        {
            fprintf(stderr, "Error: Failed to allocate Buffer: %s\n", strerror(errno));
            return NULL;
        }

        strcpy(pointer+pointer_length, buffer);

        if(buffer[buffer_length-1] == '\n')
        {
            if(buffer_length == 1 || buffer[buffer_length-2] != '\\')
            {
                return pointer;
            }

            pointer[pointer_length+buffer_length-2] = '\0';
            buffer_length -= 2;
            print_prompt2();
        }

        pointer_length += buffer_length;
    }

    return pointer;
}