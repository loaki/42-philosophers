#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../lib/libft.h"

typedef struct	s_stack
{
	int				*tab;
	int				size;
}				t_stack;

typedef struct	s_struct
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_stack		chunk;
	char		*instr;
	int			nb_instr;
	int			opt_v;
	int			opt_c;
}				t_struct;

static void	apply_p(t_stack *dest, t_stack *source);
void		op_p(t_struct *st, char *instr);
static void	apply_r(t_stack *stack);
void		op_r(t_struct *st, char *instr);
static void	apply_rr(t_stack *stack);
void		op_rr(t_struct *st, char *instr);
static void	apply_s(t_stack *stack);
void		op_s(t_struct *st, char *instr);

void		exec_instr(t_struct *st, char *op, int key);
int 		check_stack(t_struct *st);
int 		check_sort(t_struct *st);
int 		check_rsort(t_struct *st);

int			ft_strcmp(const char *s1, const char *s2);
static int	instr_cmp(char *line);
static int	check_if_valid_instr(t_struct *st, char buf[], int *index);
int			check_instr(t_struct *st);

void 		init_struct(t_struct *st);
int 		free_struct(t_struct *st);

int 		check_arg(t_struct *st, int ac, char **av);
int 		realloc_stack(t_stack *stack, int nb);
int			parse_arg(t_struct *st, int ac, char **av);

int			get_median(t_struct *st);
int			get_high(t_stack stack);
int			get_low(t_stack stack);
int			get_index(t_stack stack, int nb);
void		get_rotate_a(t_struct *st, int nb_move);


void		fill_chunk(t_struct *st, int *cp_stack);
int			check_index(t_struct *st, int nb_move);
void		insert_index(t_struct *st);
void		insert_to_b(t_struct *st, int nb_move, char *instr);
int			insertion_sort(t_struct *st);

void		sort_three(t_struct *st);
void		small_sort(t_struct *st);
int 		sort_stack(t_struct *st);

void		print_stack(t_struct *st, int size_max, int display_max);
int			get_moy(t_stack stack, int start, int end);
void		display(t_struct *st, char *op);

int 		check_print_a(t_struct *st, int i, int size_max, int display_max);
int 		check_print_b(t_struct *st, int i, int size_max, int display_max);

void 		print_a(t_struct *st, int i, int size_max, int display_max);
void		print_b(t_struct *st, int i, int size_max, int display_max);
void		print_ac(t_struct *st, int i, int size_max, int display_max);
void		print_bc(t_struct *st, int i, int size_max, int display_max);

#endif