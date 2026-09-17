#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "executor.h"

void execute_command(Token tokens[], int count) {

    char *args[MAX_TOKENS + 1];

    for (int i = 0; i < count; i++) {
        args[i] = tokens[i].value;
    }

    args[count] = NULL;

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return;
    }

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());

        execvp(args[0], args);

        perror("Command execution failed");
        exit(EXIT_FAILURE);
    }

    waitpid(pid, NULL, 0);

    printf("Command execution completed.\n");
}
