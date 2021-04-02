#include <stdio.h>
#include "shell.h"
#include <unistd.h>
#include <limits.h>

#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void print_prompt1(void)
{
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    fprintf(stderr, CYN "NUSH > " WHT "%s" CYN "$ " RESET,cwd);
}

void print_prompt2(void)
{
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    fprintf(stderr,CYN "NUSH > " WHT "%s" CYN "> " RESET,cwd);
}