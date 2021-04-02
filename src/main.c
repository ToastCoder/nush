#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "shell.h"
#include "source.h"
#include "parser.h"
#include "executor.h"

int main(int argc, char **argv)
{
    char *command;
    initsh();
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

        struct source_s src;
        src.buffer   = command;
        src.buffer_size  = strlen(command);
        src.cursor_position   = INIT_SRC_POS;
        parse_and_execute(&src);

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

int parse_and_execute(struct source_s *src)
{
    skip_white_spaces(src);

    struct token_s *tok = tokenize(src);

    if(tok == &eof_token)
    {
        return 0;
    }

    while(tok && tok != &eof_token)
    {
        struct node_s *command = parse_simple_command(tok);

        if(!command)
        {
            break;
        }

        do_simple_command(command);
        free_node_tree(command);
        tok = tokenize(src);
    }

    return 1;
}