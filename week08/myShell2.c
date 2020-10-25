#include <stdio.h>
#include <string.h> // strcmp
#include <stdlib.h> // exit
#include <unistd.h> // fork, exec
#include <sys/wait.h> // wait

#define MAXARGS 20
#define ARGLEN 256

void execute(char *arglist[]);
void cmdToArray(char *cmd, char *arglist[]);

int main(void)
{
    char *arglist[MAXARGS+1];   // array of pointers
    char cmd[ARGLEN];           // read stuff here

    while (1)
    {
        printf("cs270> ");
        fgets(cmd, ARGLEN, stdin);

        // remove newline from cmd
        cmd[strlen(cmd) - 1] = '\0';

        // exit if user types exit
        if (strcmp(cmd, "exit") == 0)
        {
            exit(0);
        }
        else if (*cmd != '\0')
        {
            // TODO: break cmd into individual strings as elements of arglist
            cmdToArray(cmd, arglist);
            execute(arglist);
        }
    }

    return 0;
}

void cmdToArray(char *cmd, char *arglist[])
{
    // cmd = "cp file1.txt file2.txt"
    // arglist[0] = "cp"
    // arglist[1] = "file1.txt"
    // arglist[2] = "file2.txt"
    // arglist[3] = NULL

    // cmd = "cp f.txt at"
    // char cmd[25] = {'c', 'p', ' ', 'f','.', 't', 'x', 't', ' ', 'a', 't', '\0'};
    // arglist[0] = &cmd[0];
    // arglist[1] = &cmd[3];
    // arglist[2] = &cmd[9];
    // arglist[3] = NULL;
    // printf("%s\n", arglist[0]);
    // printf("%s\n", arglist[1]);
    // printf("%s\n", arglist[2]);

    int argc = 0;
    int newString = 0;
    int length = strlen(cmd);
    for (int i = 0; i < length; ++i)
    {
        if (cmd[i] != ' ' && newString == 0)
        {
            newString = 1;
            arglist[argc] = &cmd[i];
            ++argc;
        }
        else if (cmd[i] == ' ')
        {
            newString = 0;
            cmd[i] = '\0';
        }
    }
    arglist[argc] = NULL;
}

void execute(char *arglist[])
{
    int pid, exitstatus;

    pid = fork();  // make new process
    if (pid == -1)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        execvp(arglist[0], arglist);
        // exec cannot return
        fprintf(stderr, "Cannot execute %s\n", arglist[0]);
        exit(1); // exec failed
    }
    else 
    {
        int got_pid = wait(&exitstatus);
        if (got_pid == pid)
        {
            printf("The child we were waiting for died\n");

            if (WIFEXITED(exitstatus))
            {
                printf("child process %d exited with value %d\n", pid, WEXITSTATUS(exitstatus));
            }
        }
        else if (got_pid == -1)
        {
            perror("wait failed");
        }
    }
}
