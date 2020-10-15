#include <sys/types.h>
#include <sys/file.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pid;
    char letterA = 'a', letterB = 'b';

    int fd = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    if (fd == -1)
    {
        perror("");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == 0)
    {
        for (int i = 0; i < 30; ++i)
        {
            write(fd, &letterA, 1);
            sleep(1);
        }
    }
    else
    {
        for (int i = 0; i < 30; ++i)
        {
            write(fd, &letterB, 1);
            sleep(1);
        }
    }
    
    return 0;
}