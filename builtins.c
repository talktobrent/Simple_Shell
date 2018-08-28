#include "shell.h"

/**
 *builtins - check to see if user's input is a builtin
 *if so, command is executed
 *@input: user's input
 *@build: array of builtins
 *@all: all variables
 *
 *Return: 0 upon success, 1 if input is not a built-in
 */
int builtins(struct wrap *all)
{
	int count = 0;
	int cmp = 0;

	built_in build [] = {
		{"exit", myexit},
		{"env", myenv},
		{NULL, NULL}
		};

	if (all->size > 1)
		return (1);
	while (build[count].cmd != NULL)
	{
		/*printf("im in the built loop\n");*/
		while(build[count].cmd[cmp] == all->cmdarray[0][cmp])
		{
		 	if (all->cmdarray[0][cmp] == '\0')
				if (build[count].cmd[cmp] == '\0')
				{
					build[count].call(all);
					return (0);
				}
			cmp++;
		}
	        count++;
	}
	if (build[count].cmd ==NULL)
		return (1);

	return (0);
}

/**
 *myenv - prints current enviroment
 *@all: all variables
 *
 *Return: 0 upon success
 */
int myenv (struct wrap *all)
{
	int count = 0, length = 0;

	while(all->env[count] != NULL)
	{
		while(all->env[count][length] != '\0')
			length++;

		write(STDOUT_FILENO, all->env[count], length);
		write(STDOUT_FILENO, "\n", 2);

		length = 0;
		count++;

        }
        free(all->cmdarray);
	return (0);
}

/**
 *myexit - exits customs shell
 *@all: all variables
 *
 *Return: 0 upon success
 */
int myexit (struct wrap *all)
{
        free(all->line);
	free(all->cmdarray);
	exit(all->retval);

	return (0);
}


