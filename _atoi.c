#include "shell.h"
/**
 * get_length - we are defining our get_length here
 *@number:this ho;ds the number of total item gotten
 *Return:returns the length of a number
 */
int get_length(int number)
{
unsigned int num1;
int len = 1;

if (number < 0)
{
len++;
num1 = number * -1;
}
else
{
num1 = number;
}
while (num1 > 9)
{
len++;
num1 = num1 / 10;
}
return (len);
}

/**
 * aux_itoa - convert function into string
 * @n:number of strings to be converted
 * Return: returns converted strings
 */

char *aux_itoa(int n)
{

unsigned int num1;
int length = get_length(n);
char *buffer;

buffer = malloc(sizeof(char) * (length + 1));
if (buffer == NULL)
return (NULL);

*(buffer + length) = '\0';

if (n < 0)
{
num1 = n * -1;
buffer[0] = '-';
}
else
{
num1 = n;
}
length--;
do {
	*(buffer + length) = (num1 % 10) + '0';
	num1 = num1 / 10;
	length--;
}
while (num1 > 0)
return (buffer);
}

/**
 *_atoi - converts a string to an integer
 *@str : the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *str)

{
	int e, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (e = 0;  str[e] != '\0' && flag != 2; e++)
	{
		if (str[e] == '-')
		sign *= -1;

		if (str[e] >= '0' && str[e] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[e]   - '0');
		}
		else if (flag == 1)
		flag = 2;
	}

		if (sign == -1)
		output = -result;
		else
		output = result;

		return (output);
}
