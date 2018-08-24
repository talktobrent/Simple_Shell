#include <stdio.h>
#include "shell.h"

/*
 * stringprep - finds amount of arguments in a string
 * @delimeter: argument delimeter
 * @end: when to stop looking
 * Returns: number of arguments found
 * Description: terminates string with a null byte, and is intended to
 * determine malloc array size before a strtok operation
 */

int stringprep(char *string, char delimeter, char end)
{
        size_t count = 0;
	int elements = 0;

	count = 0;

        printf("test\n");

        /* isolates arguments and finds element count */
        while (string[count] != end /*&& string[count] != '\0'*/)
        {
                printf("inloop\n");
                if (string[count] != delimeter)
                {

                        if (string[count + 1] == delimeter)
				elements++;

			if (string[count + 1] == end)
				elements++;

			if (string[count + 1] == '\0' && end != '\0')
				elements++;

                }
                printf("count = %lu and buffer is %c\n", count, string[count]);
                count++;
        }

	/* terminates given string with a null byte */
	string[count] = '\0';

        return (elements);
}
