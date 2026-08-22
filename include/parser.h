#ifndef PARSER_H
#define PARSER_H

#define MAX_INPUT 1024
#define MAX_TOKENS 100

typedef struct {
    char value[MAX_INPUT];
} Token;

int tokenize(char *input, Token tokens[], int *count);
void print_tokens(Token tokens[], int count);

#endif
