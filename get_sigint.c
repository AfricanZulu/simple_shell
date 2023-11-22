#include "shell.h"
/**
 * get_sigint - handles the ctr + c call prompt
 * @sign:saves input from the user
 * Return:input from the user
 */
void get_sigint(int sign)
{
	(void)sign;
	write(STDOUT_FILENO, "\n^-^  ", 5);
}
