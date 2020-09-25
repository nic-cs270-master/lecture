/**
 * @file cp1.c
 * @author Gabe de la Cruz
 * @brief Uses read and write with tunable buffer size
 *        usage: cp1 src dest
 * @version 0.1
 * @date 2020-09-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFERSIZE   4096
#define COPYMODE     0644

void oops(char *, char *);

int main(int argc, char *argv[])
{
    int infd, outfd, nChars;
    char buf[BUFFERSIZE];

    // check args
    if (argc != 3)
    {
        fprintf(stderr, "usage: %s source destination\n", *argv);
        exit(1);
    }

    // open files
    if ((infd = open(argv[1], O_RDONLY)) == -1)
    {
        oops("Cannot open ", argv[1]);
    }

    if ((outfd = creat(argv[2], COPYMODE)) == -1)
    {
        oops("Cannot open ", argv[2]);
    }

    // copy files
    while ((nChars = read(infd, buf, BUFFERSIZE)) > 0)
    {
        if (write(outfd, buf, nChars) != nChars)
        {
            oops("Write error to ", argv[2]);
        }
    }
    if (nChars == -1)
    {
        oops("Read error from ", argv[1]);
    }

    if (close(infd) == -1 || close(outfd) == -1)
    {
        oops("Error closing files", "");
    }

    return 0;
}

/**
 * @brief Displays error to the standard error and
 *        prints error by the system call using perror().
 *        Program terminates when this function is called.
 * 
 * @param s1 type of error
 * @param s2 file that cause the error
 */
void oops(char *s1, char *s2)
{
    fprintf(stderr, "Error: %s ", s1);
    perror(s2);
    exit(1);
}