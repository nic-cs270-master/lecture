#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

void myperror(const char* s);

int main()
{
    // FILE* fp = fopen("file.txt", "r");
    int file = open("file.txt", O_RDONLY);

    if (file < 0)
    {
        // print error code in errno
        // printf("%d\n", errno);
        // myperror(NULL);
        perror("Error!");
        return 1;
    }

    return 0;
}


// #define    EPERM   1   /* Operation not permitted */
// #define    ENOENT  2   /* No such file or directory */
// #define    ESRCH   3   /* No such process */
// #define    EINTR   4   /* Interrupted system call */
// #define    EIO     5   /* I/O error */
void myperror(const char* s)
{
    if (s != NULL)
        printf("%s: ", s);

    if (errno == EPERM)
        printf("Operation not permitted\n");
    else if (errno == ENOENT)
        printf("No such file or directory\n");
    else if (errno == ESRCH)
        printf("No such process\n");
    else if (errno == EINTR)
        printf("Interrupted system call\n");
    else if (errno == EIO)
        printf("I/O error\n");
    else
        printf("Succes");
    
    return;
}