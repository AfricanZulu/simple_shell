#include "shell.h"
/**
*display_prompt - prompts the user to input data
*Return:Nothing
*/
void display_prompt(void)

{
	if (isatty(STDIN_FILENO))
	printf("smart$  ");
}
/**
 * handle_input - this takes care of what the user inputs
 * @str:set  of information from the user
 * Return:whatever the user types in
 */
void handle_input(char **str)
{
	int num_char, i;

num_char = getline(str, 0, stdin);
if (num_char == -1)
{
	free(*str);
	exit(EXIT_FAILURE);
}
i = 0;
while (str[i])
{
	if (str[i][0] == '\n')
	str[i][0] = 0;
	i++;
}
}
