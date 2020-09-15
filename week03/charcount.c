/**
 * @file charcount.c
 *
 * Write to stdout the number of chars in stdin.
 */
#include <stdio.h>

int main(void)
{
    int c;
    int charCount = 0;

    while (1)
    {
        c = getchar();
        if (c == EOF)
            break;
        ++charCount;
    }

    printf("%d\n", charCount);
    return 0;
}