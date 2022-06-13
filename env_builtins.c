#include "shell.c"


/**
 * shellby_env - prints the current env
 * @args: an array of arguments passes on the shell stdio
 * @front: a double pointer to the beginning of the arguments
 *
 * Return: if an error occurs = -1
 *         otherwise = 0
 */
int shellby_env(char **args, char __attribute__((__unused__)) **front){
	int index = 0;
	char new_line = '\n';

	if (!environ)
		return (-1);

	while (environ[index])
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &new_line, 1);
		index++;
	}

	(void)args;
	return (0);
}


/**
 *  shellby_setenv - changes or adds an environmentsl variable to the path.
 * @args: An array of arguments passed to the shell.
 * @front: a double pointer to the beginning of the argument array
 * Description: args[1] is the name of the new or existing PATH variable.
 *              args[2] is the value to set the new or changed variable to.
 *
 * Return: if an error occurs = -1
 *         otherwise = 0.
 */

int shellby_setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var = NULL, **new_environ, *new_value;
	size_t size = 0;
	int index;

	if (!args[0] || !args[1])
		return(create_error(args, -1));

	new_value =  malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (new_value == NULL)
		return (create_error(args, -1));

	_strcpy(new_value, args[0]);
	_strcpy(new_value, "=");
	_strcpy(new_value, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
		return (0);
	}

	while (environ[size])
		size++;

	new_environ = malloc(sizeof(char *) * (size + 2));
	if (new_environ == NULL)
	{
		free(new_value);
		return (create_error(args, -1));
	}

	index = 0;
	while (environ[index])
	{
		new_environ[index] = environ[index];
		index++;
	}

	free(environ);
	environ = new_environ;
	environ[index] = new_value;
	environ[index + 1] = NULL;

	return (0);
}

/**
 * shellby_unsetenv - Deletes an environmental variable from the PATH
 * @args: an array of arguments passed to the shell
 * @front: A double pointer to the beginning of an array
 * Description: args[1] is the path vaiable to remove
 * Return: if an error occurs = -1
 *         Otherwise = 0
 */
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var, **new_environ;
	size_t size = 0;
	int index, index2;

	if (!args[0])
		return (create_error(args, -1));
	env_var = _getenv(args[0]);
	if (!env_var)
		return (0);

	while (environ[size])
	{
		size++
	}

	new_environ = malloc(sizeof(char *) * size);
	if (!new_environ)
		return (create_error(args, -1));

	for (index = 0, index2 = 0; environ[index]; index++)
	{
		if (*env_var == environ[index])
		{
			free(*env_var);
			continue;
		}
		new_environ[index2] = environ[index];
		index2++;
	}
	free(environ);
	environ = new_environ;
	environ[size - 1] = NULL;

	return (0);
}
