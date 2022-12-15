#include "stack_list.h"

/* opcode for nop that does nothing */
NOP {
	(NON)line_number;
	(NON)stack;
}

/*
 * Handles the opcode pchar which prints the character equivalent of the integ
 * item on the top of the stack, if the character is printable.
 * If stack is empty, an error message is displayed and program exists.
 */
PCHAR {
	if (!*stack)
		FREE_STACK(stack), CLOSE(ERR_PCHAR_EMPTY, line_number);

	if ((*stack)->n < ASCII_MIN || (*stack)->n > ASCII_MAX)
		FREE_STACK(stack), CLOSE(ERR_PCHAR_VAL, line_number);

	printf("%c\n", (*stack)->n);
}

/*
 * Handles pstr opcode which prints the character equivalent of integers on the
 * stack, starting from the top, in succession until;
 * The stack if completely printed out, or
 * The item is zero, or
 * The item is outside the range of the ascii table.
 *
 * When the stack is completely printed out, or if the stack is empty,
 * a new line is printed.
 */
PSTR {
	STACK_STRUCT *temp = *stack;

	(NON)line_number;
	for ( ; temp && (temp->n >= ASCII_MIN && temp->n <= ASCII_MAX);
			temp = temp->next)
		putchar(temp->n);
	putchar('\n');
}

/*
 * Handles the rotl opcode.
 * It moves the top item of on the stack to the bottom.
 */
ROTL {
	(NON)line_number;
	add_node_to_end(stack, (*stack)->n);
	pop(stack, 0);
}

/*
 * Handles the rotr opcode which moves the bottom item of the stack to the top.
 */
ROTR {
	STACK_STRUCT *temp = *stack, *temp_2 = NULL;

	(NON)line_number;
	for (; temp; temp = temp->next)
	{
		if (temp->next == NULL)
		{
			add_node_to_beg(stack, temp->n);
			temp_2 = temp->prev;
			free(temp);
			temp_2->next = NULL;
			break;
		}
	}
}
