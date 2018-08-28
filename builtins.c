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
int builtins(const char *input, built_in *build, struct wrap *all)
{
	int count = 0; 
	int cmp = 0;

	(void)(input);

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
		if (all->ac != 1)
		{
			_error(all, "No such file or directory");
			break;
		}

		while(all->env[count][length] != '\0')
			length++;
	        
		write(1, all->env[count], length);
		write(1, "\n", 2);
        
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
	if (all->ac != 1)
		_error(all, "Illegal number");
        free(all->line);
	free(all->cmdarray);
	exit(all->retval);

	return (0);
}


