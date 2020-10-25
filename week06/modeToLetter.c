#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void modeToLetters(int mode, char str[]);

int main()
{
    char str[10];
    int mode = 0100664;

    modeToLetters(mode, str);
    printf("mode: %o\n", mode);
    printf("%s\n", str);
    
    return 0;
}

void modeToLetters(int mode, char str[])
{
    strcpy(str, "----------");
    if (S_ISDIR(mode)) str[0] = 'd';  // directory
    if (S_ISCHR(mode)) str[0] = 'c';  // char device
    if (S_ISBLK(mode)) str[0] = 'b';  // block device

    // 3 bits for user
    // if (mode & S_IRUSR) str[1] = 'r';
    // if (mode & S_IWUSR) str[2] = 'w';
    // if (mode & S_IXUSR) str[3] = 'x';
    if (mode & 0400) str[1] = 'r';
    if (mode & 0200) str[2] = 'w';
    if (mode & 0100) str[3] = 'x';

    // 3 bits for group
    // if (mode & S_IRGRP) str[4] = 'r';
    // if (mode & S_IWGRP) str[5] = 'w';
    // if (mode & S_IXGRP) str[6] = 'x';
    if (mode & 0040) str[4] = 'r';
    if (mode & 0020) str[5] = 'w';
    if (mode & 0010) str[6] = 'x';

    // 3 bits for other
    // if (mode & S_IROTH) str[7] = 'r';
    // if (mode & S_IWOTH) str[8] = 'w';
    // if (mode & S_IXOTH) str[9] = 'x';
    if (mode & 0004) str[7] = 'r';
    if (mode & 0002) str[8] = 'w';
    if (mode & 0001) str[9] = 'x';
}