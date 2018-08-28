#include "shell.h"

/**
 *getinput - gets buffer from standard input
 *@all: all variables
 *
 *Return: buffer
 */
char *getinput(struct wrap *all)
{
        char *buffer;
        int count, check = 0;
        size_t size = 0;

	if (isatty(0) == 1)
		write(STDOUT_FILENO, "$ ", 2);

	if (all->off == 1)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(all->retval);
	}


        check = getline(&buffer, &size, stdin);
	if (check == -1 || buffer == NULL || buffer[0] == 0)
        {
                if (isatty(0) == 1)
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		exit(all->retval);
        }

	count = 0;
	while (buffer[count] != '\0')
		count++;

	if (buffer[count - 1] != '\n')
		all->off = 1;

        return (buffer);
}
