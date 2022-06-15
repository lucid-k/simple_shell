/*
 * File: split.c
 * Dev: Tony Kipchirchir
 *       Anthony Kibet
 */

#include "shell.h"

/**
 * _strtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words.
 */
char **_strtok(char *line, char *delim)
{
	char *token;
	char **ptr;
	int index;
	size_t words = 0;

	for (index = 0; line[index]; index++)
	{
		if (line[index] != *delim)
		{
			if (line[index + 1] == *delim ||
			    line[index + 1] == '\0')
				words++;
		}
	}
	line[index - 1] = '\0';
	ptr = malloc(sizeof(char *) * (words + 1));
	if (!ptr)
	{
		return (NULL);
	}

	token = strtok(line, delim);

	for (index = 0; token != NULL; index++)
	{
		ptr[index] = malloc(strlen(token) + 1);
		if (!ptr[index])
		{
			for (index -= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}
		strcpy(ptr[index], token);
		token = strtok(NULL, delim);
	}
	ptr[index] = NULL;

	return (ptr);
}
