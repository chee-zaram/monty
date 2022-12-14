#include "monty.h"

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

	if ((*stack)->n == 0)
		FREE_STACK(*stack), CLOSE(ERR_DIV, line_number);

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

	if ((*stack)->n == 0)
		FREE_STACK(*stack), CLOSE(ERR_MOD_ZERO, line_number);

	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, 0);
}
