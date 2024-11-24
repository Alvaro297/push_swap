/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:45:15 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:45:15 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_pas/libft.h"
# include "ft_printf_git/ft_printf.h"
# include "GNL_github/get_next_line_bonus.h"
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>

# define ERROR_0 "Missing arguments"
# define ERROR_1 "Argument is not an integer"
# define ERROR_2 "Duplicate numbers"
# define ERROR_3 "Numbers greater than integer"
# define INFO_1 "It's already sorted"

typedef struct s_node
{
	int				number;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// ----- Push_swap -----//
int		main(int argc, char **argv);
void	push_swap(char **argv);

// ----- Append & modify ------//
void	append_node(t_node **head, int n);
void	push_x(t_node **stack_dest, t_node **stack_src, char c);
void	set_current_position(t_node *stack_dest, t_node *stack_src);
void	rotates_swap(t_node **stack, char c);
void	rotates_both(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_swap(t_node **stack, char c);
void	reverse_rotate_both(t_node **stack_a, t_node **stack_b);
void	swap_change(t_node **stack, char c);
void	both_swap(t_node **stack_a, t_node **stack_b);
void	set_values(t_node *stack, int i);
void	set_final_values(t_node *stack, t_node *first_target,
			bool first_cheapest, int first_push_cost);
void	free_all(t_node **stack);
// ----- Stack three ------//
void	sort_three(t_node **stack);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_stack_few(t_node **stack_a, t_node **stack_b, int len_a);
void	sort_stack(t_node **stack_a, t_node **stack_b);
// ----- Validations & Initializer ----- //
void	init_validations(t_node **a, char **nbrs);
bool	already_sorted(t_node *a);
int		duplicate(t_node *a, int n);
void	are_all_numbers(int size, char **nbrs);
int		ft_stack_len(t_node *head);
void	init_values_stack(t_node *stack_a, t_node *stack_b);
void	set_cheapest(t_node *stack);
t_node	*ischeapest(t_node	*stack);
void	move_values(t_node **stack_a, t_node **stack_b);
void	finish_rotation(t_node **stack_a, t_node **stack_b, char stack_name);
void	finish_rotation2(t_node **stack, t_node **stack_b, t_node *top_node, char stack_name);
void	smallest_to_top(t_node *stack);
t_node	*get_minimum_value(t_node	*stack_x);
void	medianvalue(t_node *stack_a, t_node *stack_b);
void	get_target_node(t_node *stack_a, t_node *stack_b);
void	set_pricecost(t_node *stack_a, t_node *stack_b);

// ----- Prints ----- //
void	print_error(char *message);
void	print_info(char *message);

// ----- Utils ----- //
size_t	ft_strlen_push_swap(char **argv);
long	ft_atol(const char *nptr);
t_node	*find_smallest(t_node *stack);
int		find_min_index(t_node *stack);
char	**ft_split(char const *s, char c);
#endif