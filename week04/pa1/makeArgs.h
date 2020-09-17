#ifndef MAKE_ARGS_H
#define MAKE_ARGS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int makearg(char *s, char ***args);
int countWords(char *s);
int countWords2(char *s);
void copyNChars(char *src, char *dest, int n);
int isSpace(char c);

#endif