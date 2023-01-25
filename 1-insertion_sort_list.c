#include "sort.h"

/**
 * insertion_sort_list - implements insertion sort on a doubly linked list
 * of integers
 * @list: the list to sort
 * Returns: sorted list in ascending order
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *swapNode, *next_swap;

	if (list == NULL || *list == NULL)
		return;

	swapNode = (*list)->next;
	while (swapNode != NULL)
	{
		next_swap = swapNode->next;
		while (swapNode->prev != NULL && swapNode->prev->n > swapNode->n)
		{
			swapNode->prev->next =  swapNode->next;
			if (swapNode->next != NULL)
				swapNode->next->prev = swapNode->prev;
			swapNode->next = swapNode->prev;
			swapNode->prev = swapNode->next->prev;
			swapNode->next->prev = swapNode;
			if (swapNode->prev == NULL)
				*list = swapNode;
			else
				swapNode->prev->next = swapNode;
			print_list(*list);
		}
		swapNode = next_swap;
	}
}
