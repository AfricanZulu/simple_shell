#include "shell.h"
/**
 *str_compare - tries comparing two strings
 *@str1:first string to compare
 *@str2: second string to compare
 *Return:Always 0 if yes
 */
int str_compare(char *str1, char *str2)
{
int e;

for (e = 0; str1[e] == str2[e]; e++)
	;
	if (str1[e] > str2[e])
		return (1);
	if (str1[e] < str2[e])
		return (-1);
	return (0);
}
/**
 * _str_duplicate - This section is for string duplicate
 *@str: the duplicated string
 *Return: return the new string
*/
char *_str_duplicate(const char *str)
{
	char *new_str;
	size_t length;

	length = _str_length(str);
	new_str = malloc(sizeof(char) * (length + 1));
	if (new_str == NULL)
	return (NULL);
	_memcopy(new_str, str, length + 1);
	return (new_str);
}
/**
 *_str_length - measures the length of a string
*@str:containig the string to be measured
 *Return:return the length of string
 */
int _str_length(const char *str)
{
	int length;

	for (length = 0; str[length] != 0; length++)
		;
	return (length);
}

/**
 *_memcopy - we are defining our copy here and we are casting our value to str
*@ptr:pointer to a constant character
*@newptr:stores the new created pointer
*@size:holds the size of the content in the new pointer
*/
void _memcopy(void *newptr, const char *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int e;

	for (e = 0; e < size; e++)
	{
/*here we try to off load*/
	char_newptr[e] = char_ptr[e];
	}
}
