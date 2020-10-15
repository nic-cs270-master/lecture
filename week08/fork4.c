#include <sys/types.h>
#include <sys/file.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pid = fork();
    
    int i = 0;
    while (i++ < 5)
    {
        if (pid == 0)
        {
            printf("This is child process %d\n", getpid());
        }
        else
        {
            printf("This is parent process %d\n", getpid());
        }
        sleep(1);
    }

    return 0;
}