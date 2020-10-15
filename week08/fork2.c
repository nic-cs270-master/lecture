#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pid;

    if ((pid = fork()) == 0)
    {
        if ((pid = fork()) == 0)
        {
            printf("Hello from grand child\n");
        }
        else
        {
            printf("Hello from a child's parent\n");
        }
    }
    else
    {
        printf("Hello from grand parent\n");
    }
    
    return 0;
}