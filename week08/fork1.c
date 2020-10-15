#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pid = getpid();

    printf("from parent %d\n", pid);

    pid = fork();

    if (pid == 0)
    {
        pid = getpid();
        sleep(3);
        printf("this is child %d\n", pid);
    }
    else
    {
        pid = getpid();
        printf("this is parent %d\n", pid);
    }
    return 0;
}