/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_relevants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:48:23 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:48:23 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error(t_node **a)
{
	ft_putstr_fd("Error\n", 2);
	if (a == NULL)
		exit(1);
	free_all(a);
	exit(1);
}
