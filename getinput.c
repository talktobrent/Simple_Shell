#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#define BUFFY 1024


char **getinput(void)
{
        char **array, *buffer;
        int check;
        size_t size = 0;

	if (isatty(0) == 1)
		write(2, "$ ", 2);

        check = getline(&buffer, &size, stdin);
	if (check == -1 || buffer == NULL || buffer[0] == 0)
        {
                free(buffer);
		exit(98);
        }

	check = stringprep(buffer, ' ', '\n');

	array = buildarray(buffer, ' ', check);

        return (array);
}
