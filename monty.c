#include "monty.h"
#include <unistd.h>
#include <sys/fcntl.h>
#include <string.h>
#include <errno.h>

/* Initialize structure for miscellaneous data */
miscs misc_data = _INIT_MISC_;

/* Runs the loop for every line in our code file */
LOOP {
	LOOP_VARS;
	OP_FUNCS;

	do {
		len = 0;
		reval = getline(&line, &len, misc_data.f_ptr);
		line_num++;
		if (reval == FAIL)
		{
			fclose(misc_data.f_ptr);
			FREE_STACK(&ref_stack_list);
			free(line);
			if (errno == ENOMEM)
			{
				fprintf(stderr, ERR_MALLOC);
				exit(EXIT_FAILURE);
			}
			break;
		}

		op_code = strtok(line, DELIM);
		arg = strtok(NULL, DELIM);
		/* if its an empty line or if it is a comment line */
		if (!op_code || op_code[0] == '#')
		{
			free(line);
			continue;
		}

		for (i = 0; op_funcs[i].opcode; i++)
		{
			if (strcmp(op_funcs[i].opcode, op_code) == 0)
			{
				CALL_OP_CODE;
				break;
			}
		}
		if (!op_funcs[i].opcode)
		{
			fprintf(stderr, ERR_INV_INSTR, line_num, op_code);
			fclose(misc_data.f_ptr);
			FREE_STACK(&ref_stack_list);
			free(line);
			exit(EXIT_FAILURE);
		}
	} while (TRUE);
}

/* Runs initial checks to make sure program has requirements to run */
INIT_CHECKS
{
	/* makes sure we have a potential (path to a) file */
	if (argc != VALID_ARG_CNT)
	{
		fprintf(stderr, ERR_ARG_CNT);
		exit(EXIT_FAILURE);
	}

	/* f_ptr the pointer associated with the (opened) file stream. */
	if (f_ptr == NULL)
	{
		fprintf(stderr, ERR_FILE_OPEN, BYTE_CODE_FILE);
		exit(EXIT_FAILURE);
	}
	misc_data.f_ptr = f_ptr;
}

/**
 * main - Entry point of program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: SUCCESS always.
 */
int main(int argc, char **argv)
{
	FILE *f_ptr = OPEN_FILE();

	CHECKS();
	RUN_INTERPRETER();

	return (SUCCESS);
}
