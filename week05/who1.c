/**
 * @file who1.c
 * @author Gabe de la Cruz
 * @brief First version of the who program open,
 *        read UTMP file, and show results
 * @version 0.1
 * @date 2020-09-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h> // exit()

#define SHOWHOST  // include remote machine an output

void showInfo(struct utmp *utbufp);

int main()
{
    struct utmp currentRecord; // read info into here
    int utmpfd;
    int reclen = sizeof(struct utmp);

    if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1)
    {
        perror(UTMP_FILE);    // UTMP_FILE is in utmp.h
        exit(1);
    }

    // read a struct utmp from UTMP_FILE one at a time
    while (read(utmpfd, &currentRecord, reclen) == reclen)
    {
        showInfo(&currentRecord);
    }

    return 0;
}

/**
 * @brief Displays contents of the utmp struct in human readable form
 *        *note* these sizes should not be hardwired
 * 
 * @param utbufp pointer to struct utmp data
 */
void showInfo(struct utmp *utbufp)
{
    // the logname
    printf("%-8.8s ", utbufp->ut_user);

    // the tty (terminal)
    printf("%-8.8s ", utbufp->ut_line);

    // login time
    printf("%10d ", utbufp->ut_time);

#ifdef SHOWHOST
    printf("(%s)", utbufp->ut_host);
#endif

    printf("\n");
}