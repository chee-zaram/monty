#include "stack_list.h"

NOP {
	(NON)line_number;
	(NON)stack;
}

PCHAR {
	if (!*stack)
		FREE_STACK(*stack), CLOSE(ERR_PCHAR_EMPTY, line_number);

	if ((*stack)->n < ASCII_MIN || (*stack)->n > ASCII_MAX)
		FREE_STACK(*stack), CLOSE(ERR_PCHAR_VAL, line_number);

	printf("%c\n", (*stack)->n);
}

PSTR {
	STACK_STRUCT *temp = *stack;

	(NON)line_number;
	for ( ; temp && (temp->n >= ASCII_MIN && temp->n <= ASCII_MAX);
			temp = temp->next)
		putchar(temp->n);
	putchar('\n');
}

ROTL {
	(NON)line_number;
	add_node_to_end(stack, (*stack)->n);
	pop(stack, 0);
}

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
