/**
 * @file testintmath.c
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Program that computes for the greatest common divisor
 *        and least common multiple of i and j.
 * @version 0.2
 * @date 2020-09-15
 * 
 */
#include "intmath.h"
#include <stdio.h>

int main()
{
    int i, j;
    printf("Enter the first integer: ");
    scanf("%d", &i);
    printf("Enter the second integer: ");
    scanf("%d", &j);
    printf("Greatest common divisor: %d.\n", gcd(i, j));
    printf("Least common multiple: %d.\n", lcm(i, j));
    return 0;
}
