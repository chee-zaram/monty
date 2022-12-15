#include <unistd.h>
#include "monty.h"

/*
 * Cleans up before program exits. Prints reason for ending to stderr.
 */
CLOSE_FUNC
{
	fprintf(stderr, msg, line_number);
	free(misc_data.line);
	misc_data.line = NULL;
	fclose(misc_data.f_ptr);
	exit(EXIT_FAILURE);
}

/*
 * Frees the linked list the holds items on the stack.
 */
FREE_STACK_FUNC
{
	if (*stack)
	{
		FREE_STACK(&(*stack)->next);
		free(*stack);
		*stack = NULL;
	}
}

/*
 * Custom function to check if the byte is an integer.
 * Returns 1 if yes, 0 otherwise.
 */
ISDIGIT_FUNC
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*
 * Frees allocations and closes file stream before exiting program with err msg
 */
CLEAN_FOR_MALLOC_FUNC
{
	fprintf(stderr, ERR_MALLOC);
	free(misc_data.line);
	misc_data.line = NULL;
	fclose(misc_data.f_ptr);
	FREE_STACK(stack);
}
