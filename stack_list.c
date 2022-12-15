#include "stack_list.h"

/**
 * add_node_to_end - Adds new node at given index.
 * @head: Head of the list.
 * @n: Data.
 *
 * Return: Pointer to the newly added node.
 */
STACK_STRUCT *add_node_to_end(STACK_STRUCT **head, const _INT_ n)
{
	STACK_STRUCT *new = NULL;

	if (head)
	{
		if (*head && (*head)->next)
			return (add_node_to_end(&(*head)->next, n));
		new = malloc(sizeof(*new));
		if (new)
		{
			new->prev = NULL;
			new->next = NULL;
			new->n = n;
			if (*head)
			{
				(*head)->next = new;
				new->prev = (*head);
			}
			else
			{
				*head = new;
			}
			return (new);
		}
	}
	return (NULL);
}

/**
 * add_node_to_beg - Add a node to the beginning of a list.
 * @head: Address of head pointer.
 * @n: Data.
 *
 * Return: Pointer to newly created node.
 */
STACK_STRUCT *add_node_to_beg(STACK_STRUCT **head, const _INT_ n)
{
	STACK_STRUCT *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->n = n;

	if (!*head)
	{
		*head = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return (*head);
}

/**
 * add_node_at_idx - Adds a node at given index.
 * @h: Address of head pointer.
 * @idx: Index at which to find the node.
 * @n: Data.
 *
 * Return: Pointer to new node.
 */
STACK_STRUCT *add_node_at_idx(STACK_STRUCT **h, _UI_ idx, _INT_ n)
{
	STACK_STRUCT *new = NULL, *temp = NULL;
	_UI_ i = 0;

	if (h)
	{
		if (idx == 0)
			return (add_node_to_beg(h, n));

		for (i = 0, temp = *h; temp && i < idx; temp = temp->next, i++)
			if (i == idx - 1)
			{
				if (temp->next)
				{
					new = malloc(sizeof(*new));
					if (!new)
						return (new);
					new->n = n;
					new->next = temp->next;
					new->prev = temp;
					temp->next->prev = new;
					temp->next = new;
					return (new);
				}
				return (add_node_to_end(h, n));
			}
	}
	return (new);
}

/**
 * del_top - Deletes the top of the stack.
 * @head: Address of head pointer.
 */
void del_top(STACK_STRUCT **head)
{
	STACK_STRUCT *temp;

	if (*head)
	{
		temp = *head;
		if ((*head)->next)
			(*head)->next->prev = NULL;
		*head = (*head)->next;
		free(temp);
		temp = NULL;
	}
}
