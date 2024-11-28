/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:44:54 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:44:54 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	push_swap(char **argv, int argc)
{
	t_node	*a;
	t_node	*b;
	int		size_stack;

	a = NULL;
	b = NULL;
	if (argv[0] == NULL )
	{
		free_split(argv);
		print_error(&a);
	}
	init_validations(&a, argv, argc);
	size_stack = ft_stack_len(a);
	if (!already_sorted(a))
	{
		if (size_stack == 3)
			sort_three(&a);
		else if (size_stack == 2)
			swap_change(&a, 'a');
		else
			sort_stack(&a, &b);
	}
	free_all(&a);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		push_swap(argv, argc);
		if (argc == 2)
			free_split(argv);
	}
	return (0);
}
