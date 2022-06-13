#ifndef _SHELL_H_
#define _SHELL_H_

/*
 * File: shell.h
 * Dev: Tony Kipchirchir
 *       Anthony Maiyo
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct lst_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct lst_s 
{
	char *dir;
	struct lst_s *next;
} lst_t;

/* Helper Functions */
char **_strtok(char *line, char *delim);
char *get_location(char *command);
lst_t *get_path_dir(char *path);
lst_t *add_node_end(lst_t **head, char *dir);
void free_list(lst_t *head);

/* Builtins */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif
