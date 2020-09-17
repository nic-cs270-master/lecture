#include <stdio.h>
#include "makeArgs.h"

#define MAX_STR_LEN 512

int main()
{
    char **args, str[MAX_STR_LEN];
    int argc;

    printf("$ ");
    fgets(str, MAX_STR_LEN, stdin);

    argc = makearg(str, &args);
    printf("\n");
    for (int i = 0; i < argc; ++i)
    {
        printf("%d: %s\n", i+1, args[i]);
    }

    return 0;
}