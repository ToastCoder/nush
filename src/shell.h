#ifndef SHELL_H
#define SHELL_H

#include "source.h"

void print_prompt1(void);
void print_prompt2(void);

char *read_command(void);

int  parse_and_execute(struct source_s *src);

void initsh(void);

int dump(int argc, char **argv);

/* struct for builtin utilities */
struct builtin_s
{
    char *name;    /* utility name */
    int (*func)(int argc, char **argv); /* function to call to execute the utility */
};

/* the list of builtin utilities */
extern struct builtin_s builtins[];

/* and their count */
extern int builtins_count;

#endif