/*
-----------------------------------------------------------

NUSH

NuSH or Null Shell is an open source custom shell for UNIX-based Operating Systems.

Developed by: Vigneshwar Ravichandar

-----------------------------------------------------------
*/

// HEADER FILES
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/unistd.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

// DEFINE AREA
#define clear() printf("\033[H\033[J") 

// FUNCTION FOR STARTUP MESSAGE
void startup()
{
    clear();
    printf("\nNuSH Shell is Started...");
    char *username = getenv("USER");
    printf("\nUser: @%s",username);
    printf(']\n');
    sleep(1);
    clear();
}




