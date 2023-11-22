#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <string.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/*the advisable way to import our environment*/
extern char **environ;

/*defining our structure*/

/**
* struct data - struct that contains all relevant data on runtime
* @av: argument vector
* @input: command line written by the user
* @arguments: tokens of the command line
* @status: last status of the shell
* @counter: lines counter
* @_environ: environment variable
* @pid: process ID of the shell
*/

typedef struct data
{
	char **av;
	char *input;
	char **arguments;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 *struct builtin_s - takes in and saves data from user
 *@name:name of user
 *@f:a pointer to characters
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datasv);
} builtin_t;

/**auxilary function but I named it str_compare*/
char *_str_duplicate(const char *str);
int _str_length(const char *str);
int _atoi(char *str);
void _memcopy(void *newptr, const char *ptr, unsigned int size);
int str_compare(char *str1, char *str2);
char *aux_itoa(int n);

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/*prompt and input handler named looping*/
void display_prompt(void);
void handle_input(char **str);


/*main.c*/
void freeup_data(data_shell *datasv);
void set_data(data_shell *datasv, char **av);
int main(int acc, char **arguments);
/**
 *get_builtin - this will get our values and its returning a function
 *@sign:argument passed
 */
void get_sigint(int sign);
int (*get_builtin(char *command))(data_shell *);

#endif
