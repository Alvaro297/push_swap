
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	bool			median;
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

// ----- Validations ----- //
void	init_validations(t_node **a,char **nbrs);
void	already_sorted(t_node *a);
int		duplicate(t_node *a, int n);
void	are_all_numbers(int size, char **nbrs);

// ----- Prints ----- //
void	print_error(char *message);
void	print_info(char *message);

// ----- Utils ----- //
size_t	ft_strlen_push_swap(char **argv);
long  ft_atol(const char *nptr);
#endif