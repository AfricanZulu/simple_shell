#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>

void my_prompt(char **argv, char **env)
{
	char *str = NULL;
	int i, status;
	int num_char;
	pid_t child_pid;
	char prmt = '$';


	while (1)
{
	if (isatty (STDIN_FILENO))
printf("#smart$  ") ;
num_char = getline(&str, 0, stdin);

if (num_char == -1)
{
	free(str);
	exit(EXIT_FAILURE);
}
i = 0;
while (str[i])

{
	if (str[i] == '\n')
	str[i] = 0;
	i++;
}
argv[0] = str;
child_pid = fork();
if (child_pid == -1)

free(str);
exit(EXIT_FAILURE);
}

if (child_pid == 0)
{
if (execve(argv[0], argv, env) == -1)
{
printf("%s: No such file or directory\n", argv[0]);
exit(EXIT_FAILURE);
}
} else
{
    wait(&status);
}
}
