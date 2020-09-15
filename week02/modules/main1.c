/**
 * @file reverse.c
 *
 * Reverse a string.
 *
 * @author Glass and Ables
 * @date   September 3, 2020
 */
#include <stdio.h>
#include "reverse.h"

int main(int argc, char *argv[]) 
{ 
    char str[100];  // Buffer to hold reversed string
    reverse("cat", str); // Reverse the string "cat"
    printf("reverse (\"cat\") = %s\n", str);  // Display
    reverse("noon", str); // Reverse the string "noon"
    printf("reverse (\"noon\") = %s\n", str);  // Display

    return 0; 
}

