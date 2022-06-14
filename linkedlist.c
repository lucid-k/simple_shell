/*
 * File: linkedlist.c
 * Dev: Tony Kipchirchir
 *       Anthony Maiyo
 */

#include "shell.h"

lst_t *add_node_end(lst_t **head, char *dir);
void free_list(lst_t *head);
lst_t *get_path_dir(char *path);

/**
 * add_node_end - Adds a node to the end of a list_t linked list.
 * @head: A pointer to the head of the list_t list.
 * @dir: The directory path for the new node to contain.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
lst_t *add_node_end(lst_t **head, char *dir)
{
	lst_t *new_node = malloc(sizeof(lst_t));
	lst_t *last;

	if (!new_node)
		return (NULL);

	new_node->dir = dir;
	new_node->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
	{
		*head = new_node;
	}

	return (new_node);
}

/**
 * free_list - Frees a list_t linked list.
 * @head: The head of the list_t list.
 */
void free_list(lst_t *head)
{
	lst_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}

/**
 * get_path_dir - Tokenizes a colon-separated list of
 *                directories into a list_s linked list.
 * @path: The colon-separated list of directories.
 *
 * Return: A pointer to the initialized linked list.
 */
lst_t *get_path_dir(char *path)
{
	int index;
	char **dirs;
	lst_t *head = NULL;

	dirs = _strtok(path, ":");
	if (!dirs)
		return (NULL);
	for (index = 0; dirs[index]; index++)
	{
		if (add_node_end(&head, dirs[index]) == NULL)
		{
			free_list(head);
			free(dirs);
			return (NULL);
		}
	}

	free(dirs);
	return (head);
}
