#include <stdio.h>

int main()
{
    int num1 = 2, num2 = 3;
    float someFloat = 2.31234;

    printf("num1: %d, num2: %d\n", num1, num2);

    fprintf(stdout, "someFloat: %.2f\n", someFloat);

    if ((fputs("Hello world", stdout)) == EOF)
    {
        fprintf(stderr, "Whoops, something went wrong");
    }

    char *cptr;
    char buffer[256];

    printf("Enter something: ");
    cptr = fgets(buffer, 256, stdin);
    if (cptr  != NULL)
    {
        printf("You entered %s\n", cptr);
    }

    return 0;
}
