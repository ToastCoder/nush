#include <errno.h>
#include "shell.h"
#include "source.h"

void unget_character(struct source_s *src)
{
    if(src->cursor_position < 0)
    {
        return;
    }

    src->cursor_position--;
}


char next_character(struct source_s *src)
{
    if(!src || !src->buffer)
    {
        errno = ENODATA;
        return ERRCHAR;
    }

    char c1 = 0;
    if(src->cursor_position == INIT_SRC_POS)
    {
        src->cursor_position  = -1;
    }
    else
    {
        c1 = src->buffer[src->cursor_position];
    }

    if(++src->cursor_position >= src->buffer_size)
    {
        src->cursor_position = src->buffer_size;
        return EOF;
    }

    return src->buffer[src->cursor_position];
}


char peek_char(struct source_s *src)
{
    if(!src || !src->buffer)
    {
        errno = ENODATA;
        return ERRCHAR;
    }

    long pos = src->cursor_position;

    if(pos == INIT_SRC_POS)
    {
        pos++;
    }
    pos++;

    if(pos >= src->buffer_size)
    {
        return EOF;
    }

    return src->buffer[pos];
}


void skip_white_spaces(struct source_s *src)
{
    char c;

    if(!src || !src->buffer)
    {
        return;
    }

    while(((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
    {
        next_char(src);
    }
}