/**
 * @file intmath.c
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @version 0.1
 * @date 2020-09-14
 * 
 */
#include "intmath.h"

/**
 * @brief Computes for the greatest common divisor of i and j,
 *        where i and j must be positive values.
 * 
 * @param i any positive number
 * @param j any positive number
 * @return int greatest common divisor of i and j
 */
int gcd(int i, int j)
{
    int temp;
    while (j != 0)
    {
        temp = i % j;
        i = j;
        j = temp;
    }
    return i;
}

/**
 * @brief Computes for the least common multiple of i and j,
 *        where i and j must be positive values.
 * 
 * @param i any positive number
 * @param j any positive number
 * @return int 
 */
int lcm(int i, int j)
{
    return (i / gcd(i, j)) * j;
}
