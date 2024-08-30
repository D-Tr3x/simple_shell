#ifndef MAIN_H
#define MAIN_H

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

list_p *add_node_end(list_p **head, const char *str);
list_p *create_path_list(void);
void print_list(const list_p *h);
void free_list(list_p *head);


/* char **tokenize(char *paths); */
void tokenize(char *line, char *argv);
void get_args(int argc, char *argv[]);

#endif /* MAIN_H */
