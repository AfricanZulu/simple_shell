#include "shell.h"

char *checkfile(char *str)
{
	DIRECT *dir = opendir("/bin/");
	char *shrt, *cats;
	struct_dirent *entire;

	if (dir == NULL)
		return (NULL);
	entire = readdir(dir);
	while (entire != NULL)
	{
		shrt = entire->_name;
		if (_strcmp(shrt, str) == 0)
		{
			cat = _strcats("/bin/", str)
				closedir(dir);
				return (cat);
		}
		entire = readdir(dir);
	}
		closedir(dir);
return (NULL);
}
