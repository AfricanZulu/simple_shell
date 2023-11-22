#include "shell.h"
/**
 *read_line - read the input string.
 *@e_of:marks the end of line
 *Return:return the total input from the user
 */
char *read_line(int *e_of)
{
	char *input = NULL;
	size_t bufsize = 0;

	*e_of = getline(&input, &bufsize, stdin);

	return (input);
}
