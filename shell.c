#include "shell.h"

/**
 * main - main entry point
 * Return:(0) ALWAYS success
 *
 */
int main(void);
int main(void)
{
	int count = 0;

	char *user_input = NULL;
	size_t user_buffsize = 0;
	int readbytes = 0;
	char *token = NULL;
	int c  = 1;
	char *args[7000] = {NULL};

	while (1)
	{
		c = isatty(STDIN_FILENO);

		if (c != 0)
			write(1, "$ ", 2);
		count = 0;
		readbytes = getline(&user_input, &user_buffsize, stdin);
		if (readbytes == -1)
		{
			break;
		}
		token = strtok(user_input, " \n\t\r");

		while (token != NULL)
		{
			args[count] = token;
			count++;
			token = strtok(NULL, " \n\t\r");
		}
		if (count == 0)
		{
			continue;
		}
		args[count] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			free(user_input);
			exit(1);
		}
		if (strcmp(args[0], "env") == 0)
		{
			_my_environ();
			continue;
		}
		_my_child(args);
		if (c == 0)
		{
			break;
		}
	}
	if (user_input != NULL)
		free(user_input);
	return (0);
}
