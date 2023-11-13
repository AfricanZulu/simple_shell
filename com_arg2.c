#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND 8

void my_prompt(char **argv, char **env)
{
char *str = NULL;
int i, k, status;
int num_char;
pid_t child_pid;
char *argv[MAX_COMMAND];
char prmt = '$';


while (1)
{
	/* this is to get input from a user*/
if (isatty (STDIN_FILENO))
printf("smart$  ");

	num_char = getline(&str, 0, stdin);
	if (num_char == -1) /*this is incase of error*/
{
free(str), exit(EXIT_FAILURE);
}
/* this is to handle new_line*/
i = 0;
while (str[i])
{
if (str[i] == '\n')
str[i] = 0;
i++;
}
k = 0;
argv[k] = strtok(str, " ");

while (argv[k] != NULL)
{
k++;
	argv[k] = strtok(NULL, " ");


}
child_pid = fork();
if (child_pid == -1)

free(str), exit(EXIT_FAILURE);
}

if (child_pid == 0)
{
if (execve(argv[0], argv, env) == -1)
{
printf("%s: No such file or directory\n", argv[0]);
}
} else
{
    wait(&status);
}
}
