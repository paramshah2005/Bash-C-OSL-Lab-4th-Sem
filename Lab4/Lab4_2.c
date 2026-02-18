#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
    } else {
        wait(NULL);
        printf("Parent finished\n");
    }

    return 0;
}
