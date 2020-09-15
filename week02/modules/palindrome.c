#include "palindrome.h"
#include "reverse.h"
#include <string.h>

/**
 * Determines if str is a palindrome or not by
 * returning 0 for false and 1 for true.
 *
 * @param str a pointer to the source string
 */
int palindrome(char *str)
{
    char reversedStr[100];
    reverse(str, reversedStr);              // Reverse original
    return (strcmp(str, reversedStr) == 0); // Compare the two
}