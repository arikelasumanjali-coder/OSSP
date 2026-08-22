#include <stdio.h>
#include <string.h>
#include "parser.h"

int tokenize(char *input, Token tokens[], int *count) {
    *count = 0;

    char *token = strtok(input, " \t\n");

    while (token != NULL && *count < MAX_TOKENS) {
        strcpy(tokens[*count].value, token);
        (*count)++;

        token = strtok(NULL, " \t\n");
    }

    return 0;
}

void print_tokens(Token tokens[], int count) {
    printf("\n--- Parsed Arguments ---\n");

    for (int i = 0; i < count; i++) {
        printf("Argument %d: %s\n",
               i + 1,
               tokens[i].value);
    }
}
