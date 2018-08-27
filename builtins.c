#include "shell.h"


int builtins(const char *input, built_in *build, struct wrap *all)
{
	int count = 0, cmp = 0;

	while (build[count].cmd != NULL)
	{
		printf("im in the built loop\n");
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


}

int myenv (struct wrap *all)
{
	int count = 0, length = 0;

	while(all->env[count] != NULL)
	{
		printf("inloop\n");
		while(all->env[count][length] != '\0')
			length++;

		write(1, all->env[count], length);
		length = 0;
		count++;
	}
	write(1, "\n", 2);

	return (count);
}

int myexit (struct wrap *all)
{
	printf("about to exit\n");
	free(all->line);
	free(all->cmdarray);
	exit(all->retval);

	return (0);
}


