#include <stdio.h>
#include <string.h>
#include "shell.h"
#include <stdlib.h>

/**
 *buildarray - builds array from given string containing delimeted arguments
 *@string: user's input
 *@delimeter: where to split arguments from string
 *@elements: amount of arguments
 *
 *Return: array
 */

char **buildarray(char *string, char *delimeter, int elements)
{
	int count;
	char **array = NULL;

/*array for size of pointers * element count + 1 for NULL element */
	array = malloc(sizeof(char *) * (elements + 1));
	if (array == NULL)
	{
		return (NULL);
	}

/* puts tokens into array elements */
	count = 0;
	array[count++] = strtok(string, delimeter);
	while (count < elements)
	{
		array[count++] = strtok(NULL, delimeter);
	}
	array[count] = NULL;
	return (array);
}
