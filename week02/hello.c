/**
 * @file hello.c
 * 
 * Streams Hello, world! to stdout
 * 
 * @author Gabe de la Cruz
 * @date   September 3, 2020
 */
#include <stdio.h>
#define MAX 32

int main(int argc, char *argv[])
{
    int total;
    total = MAX * 4;
    printf("argc = %d\n", argc);
    printf("argv[0]: %s\n", argv[0]);
    for (int i = 1; i < argc; ++i)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    printf("Hello, world!\n");
    return 0;
}