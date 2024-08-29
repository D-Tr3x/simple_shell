#include "main.h"

/**
 *
 */
int main(void)
{
	list_p *head;

	head = create_path_list();
	if (head == NULL)
	{
		printf("Failed!\n");
		exit(EXIT_FAILURE);
	}

	print_list(head);
	free_list(head);

	exit(EXIT_SUCCESS);
}
