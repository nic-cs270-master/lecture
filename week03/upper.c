#include <stdio.h>
#include <ctype.h>
int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if ((c >= 'a') && (c <= 'z'))
        if (islower(c))
            c = toupper(c);
        putchar(c);
    }
}