#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child exiting\n");
        sleep(10);
    }
    else if (pid > 0)
    {
        printf("Parent sleeping\n");
        sleep(30);
    }
    else
    {
        perror("fork failed");
    }
}