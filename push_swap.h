
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

int		main(int argc, char **argv);
void	print_error(char *message);
void	print_info(char *message);
void	are_all_numbers(int size, char **nbrs);
size_t	ft_strlen_push_swap(char **argv);
void	push_swap(char **argv);

#endif