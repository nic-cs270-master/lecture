/**
 * @file upper1.c
 * 
 * Read text from stdin. Convert the first character of 
 * each "word" to uppercase, where a word is a sequence 
 * of letters. Write the result to stdout.Return 0.
 * 
 * @author Gabe de la Cruz
 * @date September 8, 2020
 */
#include <stdio.h>
#include "convert.h"


int main() 
{ 
    int c; 
    enum StateType state = NORMAL; 

    while ((c = getchar()) != EOF) 
    { 
        switch (state) 
        { 
            case NORMAL: 
                state = handleNormalState(c);
                break; 

            case INWORD: 
                state = handleInWordState(c);
                break; 
        } 
    } 
    return 0; 
}
