#include "shell.h"

/**
 *freeup_data - To free up spaces thats will be created
 *@datasv:this saves the recieved data from the user
 */
void freeup_data(data_shell *datasv)
{
	unsigned int e;

	for (e = 0; datasv->_environ[e]; e++)
	{
		free(datasv->_environ[e]);
	}
	free(datasv->_environ);
	free(datasv->pid);
}
/**
 * set_data - getting the global variable in our enviroment
 *@av:An array odf characters
 *@datasv: this takes care of saving our data
 */
void set_data(data_shell *datasv, char **av)
{
unsigned int e;/*it will help to asign the status for this envir*/

datasv->av = av;
datasv->input = NULL;
datasv->arguments = NULL;
datasv->status = 0;
datasv->counter = 1;/*this is to keep track of the number of our process*/

/*getting the global variable in our enviroment */
for (e = 0; environ[e]; e++)
	;
datasv->_environ = malloc(sizeof(char *) * (e + 1));
if (datasv == NULL)

for (e = 0; environ[e]; e++)
{
datasv->_environ[e] = strdup(environ[e]);  /*to make child env clean*/
}
datasv->_environ[e] = NULL;
datasv->pid = aux_itoa(getpid());/*to keep track of parent id*/

}
/**
 * main - data structure for saving the data of our process
 *@arguments:An array of characters
 *@acc:not useful at moment
 *Return: return datasv.status
 */
int main(int acc, char **arguments)
{
	data_shell datasv;
	(void) acc; /*silenece because its not useful now*/

	signal(SIGINT, get_sigint);
	set_data(&datasv, arguments);

	if (datasv.status == -1)
	return (255);/*this returns if error occurs*/

	return (datasv.status);
}
