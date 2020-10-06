/**
 * @file spwd.c
 * @author Gabe de la Cruz
 * @brief Simplified version of pwd
 *        starts in current directory and recursively
 *        climbs up to root of filesystem, prints top part
 *        then prints current part
 *        
 *        uses readdir() to get info about each thing
 *        bug: prints an empty string if run from "/"
 * @version 0.1
 * @date 2020-10-06
 * 
 */
#include <stdio.h>
#include <stdlib.h> // exit()
#include <string.h> // strncpy()
#include <unistd.h> // chdir()
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

ino_t getInode(char *);
void printPathTo(ino_t);
void inumToName(ino_t, char *, int);

int main()
{
    // get the inode number of the current directory
    // print the path to the current directory
    printPathTo(getInode("."));
    putchar('\n');
    return 0;
}

/**
 * @brief Prints path leading down to an object with
 *        this inode recursive
 * 
 * @param thisInode  current inode number
 */
void printPathTo(ino_t thisInode)
{
    ino_t myInode;
    char itsName[BUFSIZ];  // BUFSIZ=8192 defined in stdio.h

    if (getInode("..") != thisInode)
    {
        // get filename for the current inode number
        inumToName(thisInode, itsName, BUFSIZ);

        // change to the parent directory
        chdir("..");

        // process is now in the parent directory
        // get the inode number of the current directory
        // current directory here is the parent of thisNode 
        myInode = getInode(".");
        // Recursive until you reach the root
        printPathTo(myInode);

        // as recursive call unwinds, print the name
        printf("/%s", itsName);
    }
}

/**
 * @brief Looks through current directory for a file with 
 *        this inode number and copies its name into namebuf
 * 
 * @param inodeToFind  inode number to find in current directory
 * @param nameBuf      filename of the inode number
 * @param buflen       size of array to store filename
 */
void inumToName(ino_t inodeToFind, char *nameBuf, int buflen)
{
    DIR *dirPtr;            // the directory
    struct dirent *direntp; // each entry
    
    // establish connection to current directory
    dirPtr = opendir(".");
    if (dirPtr == NULL)
    {
        perror(".");
        exit(1);
    }

    // search current directory for a file with specified 
    // inode number
    while ((direntp = readdir(dirPtr)) != NULL)
    {
        if (direntp->d_ino == inodeToFind)
        {
            strncpy(nameBuf, direntp->d_name, buflen);
            nameBuf[buflen-1] = '\0'; // Just in case
            closedir(dirPtr);
            return;
        }
    }

    fprintf(stderr, "error looking for inum %ld\n", inodeToFind);
    exit(1);
}

/**
 * @brief Return the inode number of the file fname
 * 
 * @param fname    filename
 * @return ino_t   inode number of the filename
 */
ino_t getInode(char *fname)
{
    struct stat info;

    // get file information of fname
    if (stat(fname, &info) == -1)
    {
        fprintf(stderr, "Cannot stat ");
        perror(fname);
        exit(1);
    }

    // return inode number of fname
    return info.st_ino;
}