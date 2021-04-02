#include <stdio.h>
#include "shell.h"
#include <unistd.h>
#include <limits.h>

#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void print_prompt1(void)
{
    char user[PATH_MAX];
    char cwd[PATH_MAX];
    cuserid(user);
    getcwd(cwd, sizeof(cwd));
    fprintf(stderr, CYN "NUSH@%s>" WHT "%s" CYN "$ " RESET,user,cwd);
}

void print_prompt2(void)
{
    char user[PATH_MAX];
    char cwd[PATH_MAX];
    cuserid(user);
    getcwd(cwd, sizeof(cwd));
    fprintf(stderr,CYN "NUSH@%s>" WHT "%s" CYN "> " RESET,user,cwd);
}