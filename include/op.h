/*
** op.h for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Tue Mar 22 16:44:20 2011 Astek
*/

#ifndef _OP_H_
# define _OP_H_

# define MEM_SIZE		(6*1024)
# define IDX_MOD		512 /* modulo of the index < */
# define MAX_ARGS_NUMBER	4   /* this may not be changed 2^*IND_SIZE */

# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

/*
** regs
*/

# define REG_NUMBER		16  /* r1 <--> rx */

/*
**
*/

typedef char	t_args_type;

# define T_REG		1   /* register */
# define T_DIR		2   /* direct  (ld  #1,r1  put 1 into r1) */
# define T_IND		4   /* indirect always relative
                               ( ld 1,r1 put what's in the address (1+pc)
                               into r1 (4 bytes )) */
# define T_LAB		8   /* LABEL */

struct		s_op
{
   char		*mnemonique;
   char		nbr_args;
   t_args_type	type[MAX_ARGS_NUMBER];
   char		code;
   int		nbr_cycles;
   char		*comment;
};

typedef struct s_op	t_op;

/*
** size (in bytes)
*/
# define IND_SIZE	2
# define DIR_SIZE	4
# define REG_SIZE	DIR_SIZE

/*
** op_tab
*/
extern t_op	g_op_tab[];

/*
** header
*/
# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048

struct		s_header
{
   int		magic;
# define COREWAR_EXEC_MAGIC	0xea83f3 /* why not */
   char		prog_name[PROG_NAME_LENGTH + 1];
   int		prog_size;
   char		comment[COMMENT_LENGTH + 1];
};

typedef struct s_header	t_header;

/*
** live 2048
*/
# define CYCLE_TO_DIE	1536 /* number of cycles before being declared dead */
# define CYCLE_DELTA	5
# define NBR_LIVE	2040

#endif
