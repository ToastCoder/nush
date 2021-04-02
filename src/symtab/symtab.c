#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"
#include "../node.h"
#include "../parser.h"
#include "symtab.h"


struct symtab_stack_s symtab_stack;
int    symtab_level;


void init_symtab(void)
{
    symtab_stack.symtab_count = 1;
    symtab_level = 0;

    struct symtab_s *global_symtab = malloc(sizeof(struct symtab_s));

    if(!global_symtab)
    {
        fprintf(stderr, "fatal error: no memory for global symbol table\n");
        exit(EXIT_FAILURE);
    }

    memset(global_symtab, 0, sizeof(struct symtab_s));
    symtab_stack.global_symtab  = global_symtab;
    symtab_stack.local_symtab   = global_symtab;
    symtab_stack.symtab_list[0] = global_symtab;
    global_symtab->level        = 0;
}

struct symtab_s *new_symtab(int level)
{
    struct symtab_s *symtab = malloc(sizeof(struct symtab_s));

    if(!symtab)
    {
        fprintf(stderr, "fatal error: no memory for new symbol table\n");
        exit(EXIT_FAILURE);
    }

    memset(symtab, 0, sizeof(struct symtab_s));
    symtab->level = level;
    return symtab;
}

void free_symtab(struct symtab_s *symtab)
{
    if(symtab == NULL)
    {
        return;
    }

    struct symtab_entry_s *entry = symtab->first;

    while(entry)
    {
        if(entry->name)
        {
            free(entry->name);
        }

        if(entry->val)
        {
            free(entry->val);
        }

        if(entry->func_body)
        {
            free_node_tree(entry->func_body);
        }

        struct symtab_entry_s *next = entry->next;
        free(entry);
        entry = next;
    }

    free(symtab);
}

void dump_local_symtab(void)
{
    struct symtab_s *symtab = symtab_stack.local_symtab;
    int i = 0;
    int indent = symtab->level * 4;

    fprintf(stderr, "%*sSymbol table [Level %d]:\r\n", indent, " ", symtab->level);
    fprintf(stderr, "%*s===========================\r\n", indent, " ");
    fprintf(stderr, "%*s  No               Symbol                    Val\r\n", indent, " ");
    fprintf(stderr, "%*s------ -------------------------------- ------------\r\n", indent, " ");

    struct symtab_entry_s *entry = symtab->first;

    while(entry)
    {
        fprintf(stderr, "%*s[%04d] %-32s '%s'\r\n", indent, " ",
                i++, entry->name, entry->val);
        entry = entry->next;
    }

    fprintf(stderr, "%*s------ -------------------------------- ------------\r\n", indent, " ");
}

