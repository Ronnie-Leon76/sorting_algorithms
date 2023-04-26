#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * @list: doubly linked list of integers
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			next = current->next;
			if (current->n > next->n)
			{
				swapped = 1;
				if (current->prev != NULL)
					current->prev->next = next;
				else
					*list = next;
				next->prev = current->prev;
				current->next = next->next;
				if (next->next != NULL)
					next->next->prev = current;
				next->next = current;
				current->prev = next;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			prev = current->prev;
			if (current->n < prev->n)
			{
				swapped = 1;
				if (prev->prev != NULL)
					prev->prev->next = current;
				else
					*list = current;
				current->prev = prev->prev;
				prev->next = current->next;
				if (current->next != NULL)
					current->next->prev = prev;
				current->next = prev;
				prev->prev = current;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
