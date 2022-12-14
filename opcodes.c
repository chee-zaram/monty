#include "stack_list.h"
#include <unistd.h>

PUSH {
	_INT_ i, node_data = 0;

	if (!misc_data.arg)
		FREE_STACK(*stack), CLOSE(ERR_PUSH_INT, line_number);

	for (i = 0; misc_data.arg[i]; i++)
	{
		if (_isdigit(misc_data.arg[i]))
			continue;
		FREE_STACK(*stack), CLOSE(ERR_PUSH_INT, line_number);
	}

	node_data = atoi(misc_data.arg);
	if (misc_data.stack)
	{
		if (!add_node_to_beg(stack, node_data))
			CLEAN_FOR_ZARAM(*stack);
	}
	else
	{
		if (!add_node_to_end(stack, node_data))
			CLEAN_FOR_ZARAM(*stack);
	}
}

PALL {
	STACK_STRUCT *temp;

	(NON)line_number;
	for (temp = *stack; temp; temp = temp->next)
		printf("%d\n", temp->n);
}

PINT {
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
		FREE_STACK(*stack), CLOSE(ERR_PINT, line_number);
}

POP {
	if (*stack)
		DEL_TOP(stack, 0);
	else
		FREE_STACK(*stack), CLOSE(ERR_POP, line_number);
}

SWAP {
	_INT_ old_top;

	if (!*stack || !(*stack)->next)
		FREE_STACK(*stack), CLOSE(ERR_SWAP, line_number);

	old_top = (*stack)->n;
	pop(stack, 0);

	if (!ADD_NODE_AT_IDX(stack, 1, old_top))
		CLEAN_FOR_ZARAM(*stack);
}
