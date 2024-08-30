#include "main.h"

/**
 * add_node_end - adds a new node at the end of list_p list
 * @head: double pointer to head of list
 * @str: directory string to be added
 *
 * Return: address of new element, or NULL on failure
 */
list_p *add_node_end(list_p **head, const char *str)
{
	list_p *node, *temp;
	char *ptr;

	node = malloc(sizeof(list_p));
	if (node == NULL)
		return (NULL);

	ptr = _strdup(str);
	if (ptr == NULL)
	{
		free(node);
		return (NULL);
	}

	node->str = ptr;
	node->next = NULL;

	if (*head == NULL)
		*head = node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}

	return (node);
}

/**
 * create_path_list - creates a linked list of PATH directories
 *
 * Return: pointer to head of list
 */
list_p *create_path_list(void)
{
	char *path, *directory;
	list_p *head = NULL;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	directory = strtok(path, ":");
	while (directory != NULL)
	{
		if (!add_node_end(&head, directory))
		{
			while (head != NULL)
			{
				list_p *temp2 = head;

				head = head->next;
				free(temp2->str);
				free(temp2);
			}
			return (NULL);
		}
		directory = strtok(NULL, ":");
	}

	return (head);
}

/**
 * print_list - prints directories in the list
 * @h: pointer to head of list
 */
void print_list(const list_p *h)
{
	while (h != NULL)
	{
		printf("%s\n", h->str);
		h = h->next;
	}
}

/**
 * free_list - frees list_p list
 * @head: pointer to head of the list
 *
 */
void free_list(list_p *head)
{
	list_p *temp3;

	while (head != NULL)
	{
		temp3 = head;
		head = head->next;
		free(temp3->str);
		free(temp3);
	}
}
