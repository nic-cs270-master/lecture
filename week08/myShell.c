#include <stdio.h>
#include <string.h> // strcmp
#include <stdlib.h> // exit
#include <unistd.h> // fork, exec
#include <sys/wait.h> // wait

#define MAXARGS 20
#define ARGLEN 256

void execute(char *cmd);

int main(void)
{
    char cmd[ARGLEN];   // read the command

    while (1)
    {
        // prompt the user
        printf("gvd> ");
        // user enters a command
        fgets(cmd, ARGLEN, stdin);

        // remove newline at the end of cmd
        cmd[strlen(cmd) - 1] = '\0';

        // if the user enters "exit"
        if (strcmp(cmd, "exit") == 0)
        {
            exit(0);
        }
        else if (cmd[0] != '\0')
        {
            execute(cmd);
        }

    }

    return 0;
}

void execute(char *cmd)
{
    int pid, exitstatus;

    pid = fork();

    if (pid == -1) // error
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) // child
    {
        execlp(cmd, cmd, "-l", NULL);
        // error
        fprintf(stderr, "Cannot execute %s\n", cmd);
        exit(1);
    }
    else // parent
    {
        // pid????
        int gotPid = wait(&exitstatus);
        if (pid == gotPid)
        {
            printf("The child we created and waited for died\n");
        }
    }
}