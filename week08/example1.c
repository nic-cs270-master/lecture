#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    // printf("hello\n");
    // fork(); // <---
    // printf("hello\n");

    printf("[%d] parent process id: %d\n", getpid(), getppid());
    fork();
    printf("\n[%d] parent process id: %d\n", getpid(), getppid());

    // fork bomb
    // while(1)
    // {
    //     fork();
    // }

    return 0;
}