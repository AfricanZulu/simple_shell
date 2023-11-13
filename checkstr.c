#include "shell.h"

char **checkstr(char *str)
{
	char **conta, *pass;
	int e = 0, k = 0;

	conta = malloc(10 * sizeof(char *));
	if (conta == NULL)
	{
		perror("allocation of space failed");
		exit(1);
	}
			pass = strtok(str, " ");
			while (pass != NULL)
			{
			while (pass[k])
			{
				if (pass[k] == '\n')
		pass[k] = '\0';
	       k++;
			}
	conta[e] = pass;
	e++;

	k = 0;
	pass = strtok(NULL, " ");
}
conta[e] = NULL;
return (conta);
}
