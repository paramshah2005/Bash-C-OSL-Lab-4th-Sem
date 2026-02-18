#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    int status;
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        printf("Error Child Not Created\n");
    }
    else if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
        printf("Child PPID: %d\n", getppid());
    }
    else
    {
        wait(&status);
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Parent PPID: %d\n", getppid());
    }
    return 0;
}
