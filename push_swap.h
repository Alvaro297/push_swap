
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf_git/ft_printf.h"
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>

# define ERROR_0 "Error: Missing arguments"
# define ERROR_1 "Error: Argument is not an integer"
# define ERROR_2 "Error: Duplicate numbers"
# define ERROR_3 "Error: Numbers greater than integer"
# define ERROR_4 "Error: No numbers in the arguments"
# define INFO_1 "Info: It's already sorted"

typedef struct s_node {
	int				number;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

// ----- Push_swap -----//
int		main(int argc, char **argv);
void	push_swap(char **argv);

// ----- Append & modify ------//
void	append_node(t_node **head, int n);
void	push_x(t_node **stack_dest, t_node **stack_src, char c);
void	rotates_swap(t_node **stack, char c);
void	rotates_both(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_swap(t_node **stack, char c);
void	reverse_rotate_both(t_node **stack_a, t_node **stack_b);
void	swap_change(t_node **stack, char c);
void	both_swap(t_node **stack_a, t_node **stack_b);

// ----- Validations & Initializer ----- //
void	init_validations(t_node **a,char **nbrs);
void	already_sorted(t_node *a);
int		duplicate(t_node *a, int n);
void	are_all_numbers(int size, char **nbrs);
int		ft_stack_len(t_node *head);
void	init_values_stack(t_node *stack_a, t_node *stack_b);

// ----- Prints ----- //
void	print_error(char *message);
void	print_info(char *message);

// ----- Utils ----- //
size_t	ft_strlen_push_swap(char **argv);
long  ft_atol(const char *nptr);
#endif