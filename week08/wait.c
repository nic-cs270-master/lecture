// wait.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pid;

    if ((pid = fork()) == 0)
    {
        printf("Child %d playing...\n", getpid());
        sleep(5);
        printf("Child %d is done playing!\n", getpid());
        exit(42);
    }
    else
    {
        printf("Parent needs to go home and do something\n");
        printf("But child is playing...\n");
        int status;
        int pidWait = wait(&status);
        printf("child %d has terminated ", pidWait);
        if (WIFEXITED(status))
        {
            printf(" with status = %d\n", WEXITSTATUS(status));
        }
        printf("Parent is going home\n");
    }
    return 0;
}