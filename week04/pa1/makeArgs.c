#include "makeArgs.h"

int makearg(char *s, char ***args)
{
    assert(s != NULL);

    int argc = countWords(s); 
    printf("%d=%d\n", argc, countWords2(s));

    *args = (char**)malloc(sizeof(char*) * argc);

    int i = 0;
    int end = 0;
    char *startPtr = NULL;
    char *trackPtr = s;
    for(int j = 0; j < argc; ++j)
    {
        int strlen = 0;
        int startIndex = 0;
        
        while (isSpace(*trackPtr))
        {
            ++trackPtr;
        }
        
        if (*trackPtr == '\0')
            break;

        startPtr = trackPtr;
        while (!isSpace(*trackPtr) && *trackPtr != '\0')
        {
            ++strlen;
            ++trackPtr;
        }

        (*args)[j] = (char*)malloc(sizeof(char) * (strlen + 1));
        copyNChars(startPtr, (*args)[j], strlen);
    }

    return argc;
}

int countWords(char *s)
{
    int argc = 0;
    int i = 0;               // index counter
    int stateWhiteSpace = 1; // flag variable for whitespace state
    while (s[i] != '\0')
    {
        if (!isSpace(s[i]))
        {
            stateWhiteSpace = 0;
            ++argc;

            while (!stateWhiteSpace && s[i] != '\0')
            {
                ++i;
                stateWhiteSpace = isSpace(s[i]);
            }
        }
        else
        {
            ++i;
        }
    }

    return argc;
}

int countWords2(char *s)
{
    int state = 0;
    int argc = 0;
    while (*s != '\0') 
    { 
        switch (state) 
        { 
            case 0: 
                if (!isspace(*s)) 
                { 
                    putchar(*s);
                    ++argc; 
                    state = 1; 
                } 
                else 
                { 
                    // putchar(c); 
                    state = 0; 
                } 
                break; 

            case 1: 
                if (!isspace(*s)) 
                { 
                    putchar(*s); 
                    state = 1; 
                } 
                else 
                { 
                    // putchar(c);
                    state = 0; 
                } 
                break; 
        } 
        ++s;
    } 
    return argc;
}

void copyNChars(char *src, char *dest, int n)
{
    for (int k = 0; k < n; ++k)
    {
        dest[k] = src[k];
    }
    dest[n] = '\0';
}

int isSpace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}
