#include "stack_list.h"
#include <unistd.h>

/*
 * Handles the push opcode which accepts an int as argument and places it on
 * the stack.
 * Format could either be stack LIFO or queue FIFO specified in misc_data.stack
 * If an error occurs, an error message is printed to stderr and the program is
 * exited.
 * Error include: no arg push. invalid arg to push, malloc fail.
 */
PUSH {
	_INT_ i, node_data = 0;

	/* check for arg to push */
	if (!misc_data.arg)
		FREE_STACK(stack), CLOSE(ERR_PUSH_INT, line_number);

	for (i = 0; misc_data.arg[i]; i++)
	{
		/* check arg contains only digits */
		if (_isdigit(misc_data.arg[i]))
			continue;
		FREE_STACK(stack), CLOSE(ERR_PUSH_INT, line_number);
	}

	node_data = atoi(misc_data.arg);
	/* push in stack format */
	if (misc_data.stack)
	{
		if (!add_node_to_beg(stack, node_data))
			CLEAN_FOR_ZARAM(stack);
	}
	/* push in queue format */
	else
	{
		if (!add_node_to_end(stack, node_data))
			CLEAN_FOR_ZARAM(stack);
	}
}

/*
 * Handles the pall opcode which prints all items on the stack, one per line.
 * If stack is empty, it print nothing.
 */
PALL {
	STACK_STRUCT *temp;

	(NON)line_number;
	for (temp = *stack; temp; temp = temp->next)
		printf("%d\n", temp->n);
}

/*
 * Handles the pint opcode which prints the integer value at the top of the
 * stack.
 * If the stack is empty, a msg is printed to stderr and the program exits.
 */
PINT {
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
		FREE_STACK(stack), CLOSE(ERR_PINT, line_number);
}

/*
 * Handles the pop opcode which deletes the top item on the stack.
 * If the stack is empty, an error msg is printed to stderr and program exits.
 */
POP {
	if (*stack)
		DEL_TOP(stack);
	else
		FREE_STACK(stack), CLOSE(ERR_POP, line_number);
}

/*
 * Handles swap opcode which swaps the top two elements on the stack if they
 * exist. Else, an error message is printed to stderr and the program exits.
 */
SWAP {
	_INT_ old_top;

	if (!*stack || !(*stack)->next)
		FREE_STACK(stack), CLOSE(ERR_SWAP, line_number);

	old_top = (*stack)->n;
	pop(stack, 0);

	if (!ADD_NODE_AT_IDX(stack, 1, old_top))
		CLEAN_FOR_ZARAM(stack);
}
