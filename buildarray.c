#include <stdio.h>
#include <string.h>
#include "shell.h"
#include <stdlib.h>

/*
 * buildarray - builds array from given string containing delimeted arguments
 * delimeter: where to split arguments from string
 * Description: copies string, calls strtok to store each argument into an
 * array of char string pointers, and adds null element at the end
 * Returns: array of strings
 */

char **buildarray(char *string, char delimeter, int elements)
{
        int count;
        char **array;

        /* builds array for size of pointers * element count + 1 for NULL element */
        printf("elements: %d\n", elements);
        array = malloc(sizeof(char *) * (elements + 1));

        printf("testaftermalloc\n");

        /* puts tokens into array elements */
        count = 0;
        array[count++] = strtok(string, &delimeter);

        printf("func array [%d] is %s\n", count - 1, array[0]);

        while (count < elements)
        {
                array[count++] = strtok(NULL, &delimeter);
                if(array[count - 1] != NULL)
                        printf("func array [%d] is %s\n", count - 1, array[count - 1]);
        }
        array[count] = NULL;
	printf("last array %s\n", array[count]);
	return (array);
}
