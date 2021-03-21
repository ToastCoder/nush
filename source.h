#ifndef SOURCE_H
#define SOURCE_H

#define EOF             (-1)
#define ERRCHAR         ( 0)

#define INIT_SRC_POS    (-2)

struct source_s
{   
    char *buffer;      
    long buffer_size;       
    long  cursor_position;       
};

char next_character(struct source_s *src);
void unget_character(struct source_s *src);
char peek_character(struct source_s *src);
void skip_white_spaces(struct source_s *src);

#endif