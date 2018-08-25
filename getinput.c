#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#define BUFFY 1024


char **getinput(char *argv)
{
        char **array, *buffer;
        int count, check = 0;
        size_t size = 0;

	freebuffer = NULL;

	if (isatty(0) == 1)
		write(2, "$ ", 2);

        check = getline(&buffer, &size, stdin);
	if (check == -1 || buffer == NULL || buffer[0] == 0)
        {
                if (isatty(0) == 1)
			write(2, "\n", 1);
		free(buffer);
		exit(98);
        }

	count = 0;
	while (buffer[count] != '\0')
		count++;

	if (buffer[count - 1] != '\n')
	{
		_error(argv, buffer, "1");
		write(2, "$\n", 2);
		free(buffer);
		exit(98);
	}

	check = stringprep(buffer, ' ', '\n');

	if (check != 0)
		array = buildarray(buffer, ' ', check);
	else
	{
		array = NULL;
		free(buffer);
	}

	freebuffer = buffer;

        return (array);
}
