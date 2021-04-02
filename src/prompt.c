#include <stdio.h>
#include "shell.h"
#include <unistd.h>
#include <limits.h>
#include "symtab/symtab.h"

#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void print_prompt1(void)
{   
    struct symtab_entry_s *entry = get_symtab_entry("PS1");
    char user[PATH_MAX];
    char cwd[PATH_MAX];
    cuserid(user);
    getcwd(cwd, sizeof(cwd));
    if(entry && entry->val)
    {
        fprintf(stderr,CYN "NUSH@%s>" WHT "%s" CYN "%s" RESET,user,cwd,entry->val);
    }
    else
    {
        fprintf(stderr, CYN "NUSH@%s>" WHT "%s" CYN "$ " RESET,user,cwd);
    }
}

void print_prompt2(void)
{
    char user[PATH_MAX];
    char cwd[PATH_MAX];
    cuserid(user);
    getcwd(cwd, sizeof(cwd));
    fprintf(stderr,CYN "NUSH@%s>" WHT "%s" CYN "> " RESET,user,cwd);
}