#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * struct path_list - singly linked list
 * @str: string
 * @next: points to the next node
 */
typedef struct path_list
{
	char *str;
	struct path_list *next;
} list_p;

void _strcpy(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
int _setenv(const char *name, const char *value, int overwrite);
int _strncmp(const char *s1, const char *s2, size_t num);
char *_strchr(const char *str, char c);
char *_strdup(const char *str);
char *_getenv(const char *name);

/**
 *ssize_t read_line(char **line, size_t *len);
 *void tokenize(char *path, char *argv[]);
 *void check_exit(char **argv, char *line);
 *void handle_path(char **argv);
 *void fwxec(char **argv);
 */

ssize_t read_line(char **line, size_t *len);
void check_exit(char *line);
void fwxec(char *argv);

list_p *add_node_end(list_p **head, const char *str);
list_p *create_path_list(void);
void print_list(const list_p *h);
void free_list(list_p *head);


#endif /* MAIN_H */
