#include "monty.h"
#include <unistd.h>
#include <sys/fcntl.h>
#include <string.h>
#include <errno.h>

miscs misc_data = _INIT_MISC_;

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
			FREE_STACK(ref_stack_list);
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
			FREE_STACK(ref_stack_list);
			free(line);
			exit(EXIT_FAILURE);
		}
	} while (TRUE);
}

INIT_CHECKS
{
	if (argc != VALID_ARG_CNT)
	{
		fprintf(stderr, ERR_ARG_CNT);
		exit(EXIT_FAILURE);
	}
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
	FILE *f_ptr = OPEN_FILE;

	CHECKS();
	RUN_INTERPRETER();

	return (SUCCESS);
}
