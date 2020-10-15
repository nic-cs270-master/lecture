// zombieProblem.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;
    pid = fork(); 

    if (pid > 0) // pid is non-zero, MUST be the parent
    {
        while (1) // infinite loop
        {
            sleep(1000);
        }
    }
    else if (pid == 0) // child process
    {
        exit(42); // Exit with some status value of 42
    }
}