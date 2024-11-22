/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:48:57 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:48:57 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_x(t_node **stack_src, t_node **stack_dest, char c)
{
	t_node	*tmp;

	if (stack_src && *stack_src)
	{
		tmp = *stack_src;
		*stack_src = (*stack_src)->next;
		tmp->next = *stack_dest;
		*stack_dest = tmp;
	}
	set_current_position(*stack_dest, *stack_src);
	ft_printf("p%c\n", c);
}

void	set_current_position(t_node *stack_dest, t_node *stack_src)
{
	int		i;
	t_node	*current;

	current = stack_dest;
	i = 0;
	while (current != NULL)
	{
		current->index = i;
		i++;
		current = current->next;
	}
	i = 0;
	current = stack_src;
	while (current != NULL)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}
