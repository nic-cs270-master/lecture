#include <stdio.h>
#include "palindrome.h"

/**
 * Output:
 * palindrome (“cat”) = 0
 * palindrome (“noon”) = 1
 */


int main()
{
    printf("palindrome (\"cat\") = %d\n", palindrome("cat"));
    printf("palindrome (\"noon\") = %d\n", palindrome("noon"));
    return 0;
}