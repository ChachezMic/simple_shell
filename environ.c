#include "shell.h"
/**
 * _my_environ -  all enivironment variables
 * Return: (void)
 */
void _my_environ(void)
{
	int count;

	char nl = '\n';

	for (count = 0; environ[count] != NULL; count++)
	{
		write(1, environ[count], strlen(environ[count]));
		write(1, &nl, 1);
	}
}
