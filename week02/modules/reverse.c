#include <string.h>
#include "reverse.h"

void reverse(char *src, char *dest)
{
    int len = strlen(src);

    for (int i = (len - 1), j = 0; i >= 0; --i, j++)
    {
        dest[j] = src[i];
    }
    dest[len] = '\0';
}