#include "shell.h"
/**
 *get_builtin - this is supposed to take care of ctr command
 *@command:takes are of name command from the user
 *Return:returns builtin[e].f
 */
int (*get_builtin(char *command))(data_shell *)
{
int e;


builtin_t builtin[] = {
{NULL}

};

for (e = 0; builtin[e] .name; e++)
{
if (str_compare(builtin[e].name, command) == 0)
break;
}
return (builtin[e].f);
}
