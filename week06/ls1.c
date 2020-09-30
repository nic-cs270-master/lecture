/**
 * @file ls1.c
 * @author Gabe de la Cruz
 * @brief List contents of directory or directories.
 *        If no args, use . else list files in args
 * @version 0.1
 * @date 2020-09-29
 * 
 */
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void doLs(const char*);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        doLs(".");
    }
    else
    {
        while (--argc)
        {
            printf("%s:\n", *++argv);
            doLs(*argv);
        }
    }

    return 0;
}

/**
 * @brief List files in directory called dirname
 * 
 * @param dirname 
 */
void doLs(const char *dirname)
{
    DIR *pDir;               // the directory
    struct dirent *pDirent;  // each entry

    if ((pDir = opendir(dirname)) == NULL)
    {
        fprintf(stderr, "ls1: cannot open %s\n", dirname);
    }
    else
    {
        while ((pDirent = readdir(pDir)) != NULL)
        {
            printf("%s\n", pDirent->d_name);
        }
        closedir(pDir);
    }
    
}