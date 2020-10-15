#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("The current process %d\n", getpid());
    printf("The parent process is %d\n", getppid());
    printf("The owner of this process has uid %d\n", getuid());
    sleep(3);
    return EXIT_SUCCESS;
}
