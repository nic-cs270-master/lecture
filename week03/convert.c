/**
 * @file convert.c
 * @author Gabe de la Cruz
 * @date September 8, 2020
 */
#include "convert.h"

/**
 * Implement the NORMAL state of the DFA. c is the current
 * DFA character. Write c or its uppercase equivalent to 
 * stdout, as specified by the DFA. Return the next state.
 */
enum StateType handleNormalState(char c)
{
    enum StateType state;
    if (isalpha(c)) 
    { 
        putchar(toupper(c)); 
        state = INWORD; 
    } 
    else 
    { 
        putchar(c); 
        state = NORMAL; 
    } 
    return state;
}

/**
 * Implement the INWORD state of the DFA. c is the current 
 * DFA character. Write c to stdout, as specified by the DFA.
 * Return the next state.
 */
enum StateType handleInWordState(char c)
{
    enum StateType state;
    if (isalpha(c)) 
    { 
        putchar(c); 
        state = INWORD; 
    } 
    else 
    { 
        putchar(c);
        state = NORMAL; 
    }
    return state;
}