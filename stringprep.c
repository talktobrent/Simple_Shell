#include <stdio.h>
#include "shell.h"

/**
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

        printf("test\n");

        /* isolates arguments and finds element count, and replaces
	 * tabs with spaces*/

	if (string[0] == '\t')
		string[0] = ' ';

        while (string[count] != end && string[count] != '\0')
        {
                if (string[count + 1] == '\t')
			string[count + 1] = ' ';

		if (string[count] != delimeter)
                {

                        if (string[count + 1] == delimeter)
				elements++;

			if (string[count + 1] == end)
				elements++;

			if (string[count + 1] == '\0' && end != '\0')
				elements++;

                }
                count++;
        }

	/* terminates given string with a null byte */
	string[count] = '\0';

        return (elements);
}
