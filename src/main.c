#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "executor.h"

int main(void) {
    char input[MAX_INPUT];
    Token tokens[MAX_TOKENS];
    int count;

    while (1) {
        printf("myShell> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        if (strcmp(input, "exit\n") == 0) {
            printf("Exiting shell.\n");
            break;
        }

        if (tokenize(input, tokens, &count) != 0) {
            continue;
        }

        if (count == 0) {
            printf("Empty command.\n");
            continue;
        }

        print_tokens(tokens, count);
execute_command(tokens,count);
    }

    return 0;
}
