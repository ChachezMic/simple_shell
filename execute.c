#include "shell.h"
/**
 * _my_child - creates the child process pid
 * @args: double pointer to arguments
 * Return: void
 */
void _my_child(char **args)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(args[0], args, environ);
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror("error");
	}
	else
	{
		wait(&status);
	}
}
