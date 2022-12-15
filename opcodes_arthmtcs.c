#include "monty.h"

/*
 * Handles the basic arithmetic operators.
 * Performs said operation on the top two elements on the stack if they exist
 * If any of both do not, they program is exited on that line with an error
 * message to stderr.
 * If they both exist, computation is done
 * Result is stored in the second top element of the stack, and the top element
 * is pop'd.
 */

ADD {
	if (!*stack || !(*stack)->next)
		FREE_STACK(*stack), CLOSE(ERR_ADD, line_number);

	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	pop(stack, 0);
}

SUB {
	if (!*stack || !(*stack)->next)
		FREE_STACK(*stack), CLOSE(ERR_SUB, line_number);

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, 0);
}

DIV {
	if (!*stack || !(*stack)->next)
		FREE_STACK(*stack), CLOSE(ERR_DIV, line_number);

	/* if zero division error, print to stderr and exit */
	if ((*stack)->n == 0)
		FREE_STACK(*stack), CLOSE(ERR_DIV_ZERO, line_number);

	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, 0);
}

MUL {
	if (!*stack || !(*stack)->next)
		FREE_STACK(*stack), CLOSE(ERR_MUL, line_number);

	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, 0);
}

MOD {
	if (!*stack || !(*stack)->next)
		FREE_STACK(*stack), CLOSE(ERR_MOD, line_number);

	/* if zero division error, print to stderr and exit */
	if ((*stack)->n == 0)
		FREE_STACK(*stack), CLOSE(ERR_MOD_ZERO, line_number);

	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, 0);
}
