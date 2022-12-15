#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/************************ int constants ***********************/
#define FAIL			(-1)
#define SUCCESS			(0)
#define FALSE			(0)
#define TRUE			(1)
#define ASCII_MAX		(127)
#define ASCII_MIN		(32)

/********************* error strings *********************************/
#define ERR_ARG_CNT		"USAGE: monty file\n"
#define ERR_FILE_OPEN		"Error: Can't open file %s\n"
#define ERR_FILE_READ		"Error: Can't read file %s\n"
#define ERR_MALLOC		"Error: malloc failed\n"
#define ERR_INV_INSTR		"L%lu: unknown instruction %s\n"
#define ERR_PUSH_INT		"L%u: usage: push integer\n"
#define ERR_PINT		"L%u: can't pint, stack empty\n"
#define ERR_POP			"L%u: can't pop an empty stack\n"
#define ERR_SWAP		"L%u: can't swap, stack too short\n"
#define ERR_ADD			"L%u: can't add, stack too short\n"
#define ERR_SUB			"L%u: can't sub, stack too short\n"
#define ERR_DIV			"L%u: can't div, stack too short\n"
#define ERR_DIV_ZERO		"L%u: division by zero\n"
#define ERR_MUL			"L%u: can't mul, stack too short\n"
#define ERR_MOD			"L%u: can't mod, stack too short\n"
#define ERR_MOD_ZERO		"L%u: division by zero\n"
#define ERR_PCHAR_VAL		"L%u: can't pchar, value out of range\n"
#define ERR_PCHAR_EMPTY		"L%u: can't pchar, stack empty\n"

/************************ misc **************************/
#define DELIM			" \n\t"
#define BYTE_CODE_FILE		(argv[1])
#define VALID_ARG_CNT		(2)
#define READ_ONLY		"r"
#define _INIT_MISC_		{TRUE, NULL, NULL, NULL}
#define FREE_STACK		free_stack

/*********************** data types ************************/
typedef unsigned int		_UI_;
typedef int			_INT_;
typedef char			_CHAR_;
typedef void			NON;
typedef size_t			_SIZE__T_;
typedef ssize_t			_SSIZE_T_;
#define STACK_STRUCT		stack_t

/************************ functions for ops and some more ********************/
#define CHECKS()		init_checks(argc, argv, f_ptr)
#define RUN_INTERPRETER()	loop_monty()
#define PUSH			void push(stack_t **stack, _UI_ line_number)
#define PALL			void pall(stack_t **stack, _UI_ line_number)
#define PINT			void pint(stack_t **stack, _UI_ line_number)
#define POP			void pop(stack_t **stack, _UI_ line_number)
#define SWAP			void swap(stack_t **stack, _UI_ line_number)
#define ADD			void __add__(stack_t **stack, _UI_ line_number)
#define SUB			void __sub__(stack_t **stack, _UI_ line_number)
#define DIV			void __div__(stack_t **stack, _UI_ line_number)
#define MUL			void __mul__(stack_t **stack, _UI_ line_number)
#define MOD			void __mod__(stack_t **stack, _UI_ line_number)
#define NOP			void nop(stack_t **stack, _UI_ line_number)
#define PCHAR			void pchar(stack_t **stack, _UI_ line_number)
#define PSTR			void pstr(stack_t **stack, _UI_ line_number)
#define ROTL			void rotl(stack_t **stack, _UI_ line_number)
#define ROTR			void rotr(stack_t **stack, _UI_ line_number)
#define STACK			void stack(stack_t **stack, _UI_ line_number)
#define QUEUE			void queue(stack_t **stack, _UI_ line_number)
#define OPEN_FILE()		fopen(BYTE_CODE_FILE, READ_ONLY)

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	_INT_ n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	_CHAR_ *opcode;

	NON(*f)(stack_t **stack, _UI_ line_number);
} instruction_t;


/**
 * struct misc - Holds miscellaneous data.
 * @stack: Whether to load data as stack or queue
 * @arg: Argument to push operator
 * @line: Op code line
 * @f_ptr: File stream associated with bytecode file
 */
typedef struct misc
{
	_INT_	stack;
	_CHAR_	*arg;
	_CHAR_	*line;
	FILE	*f_ptr;
} miscs;


extern miscs misc_data;


/******************************* monty.c ************************************/
NON loop_monty(NON);
#define LOOP		NON loop_monty(NON)
NON open_file(_INT_ argc, _CHAR_ **argv, FILE *f_ptr);
#define INIT_CHECKS	NON init_checks(_INT_ argc, _CHAR_ **argv, FILE *f_ptr)


/************** opcodes.c *****************/
NON push(stack_t **stack, _UI_ line_number);
NON pall(stack_t **stack, _UI_ line_number);
NON pint(stack_t **stack, _UI_ line_number);
NON pop(stack_t **stack, _UI_ line_number);
NON swap(stack_t **stack, _UI_ line_number);


/************ opcodes_arthmtcs.c *************/
NON __add__(stack_t **stack, _UI_ line_number);
NON __sub__(stack_t **stack, _UI_ line_number);
NON __div__(stack_t **stack, _UI_ line_number);
NON __mul__(stack_t **stack, _UI_ line_number);
NON __mod__(stack_t **stack, _UI_ line_number);


/************** opcodes_2.c ****************/
NON nop(stack_t **stack, _UI_ line_number);
NON pchar(stack_t **stack, _UI_ line_number);
NON pstr(stack_t **stack, _UI_ line_number);
NON rotl(stack_t **stack, _UI_ line_number);
NON rotr(stack_t **stack, _UI_ line_number);


/************ stack_and_queue.c ************/
NON stack(stack_t **stack, _UI_ line_number);
NON queue(stack_t **stack, _UI_ line_number);


/************************* misc.c ***************************/
NON FREE_STACK(stack_t *stack);
#define FREE_STACK_FUNC		NON FREE_STACK(stack_t *stack)

#define CLOSE			end_prog_on_op_err
NON CLOSE(_CHAR_ *msg, _UI_ line_number);
#define CLOSE_FUNC		NON CLOSE(_CHAR_ *msg, _UI_ line_number)

#define ISDIGIT	_isdigit
_INT_ ISDIGIT(_INT_ c);
#define ISDIGIT_FUNC		_INT_ ISDIGIT(_INT_ c)

#define CLEAN_FOR_ZARAM		clean_for_malloc
NON CLEAN_FOR_ZARAM(stack_t *stack);
#define CLEAN_FOR_MALLOC_FUNC	NON CLEAN_FOR_ZARAM(stack_t *stack)


/***************************************************************/
#define OP_FUNCS						\
instruction_t op_funcs[] = {					\
	{"push", push}, {"pall", pall}, {"pint", pint},		\
	{"pop", pop}, {"swap", swap},				\
	{"add", __add__}, {"sub", __sub__}, {"div", __div__},	\
	{"mul", __mul__}, {"mod", __mod__},			\
	{"nop", nop}, {"pchar", pchar}, {"pstr", pstr},		\
	{"rotl", rotl}, {"rotr", rotr},				\
	{"stack", stack}, {"queue", queue},			\
	{NULL, NULL}						\
}

/***************************************************************/
#define LOOP_VARS						\
_SSIZE_T_ line_num = 0, i, reval;				\
_SIZE__T_ len;							\
_CHAR_ *line = NULL, *op_code, *arg;				\
stack_t *ref_stack_list = NULL					\

/***************************************************************/
#define CALL_OP_CODE						\
misc_data.arg = arg;						\
misc_data.line = line;						\
op_funcs[i].f(&ref_stack_list, line_num);			\
free(line)							\

#endif /* !_MONTY_H_ */
