/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 10:02:02 by alvamart          #+#    #+#             */
/*   Updated: 2024-10-18 10:02:02 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		check_params(char param, va_list arg);
//UTILS STRINGS//
int		ft_print_char(char c);
int		ft_print_str(char *str);
//******//
//UTILS NUMS//
int		ft_print_base(int nbr, char *base);
int		ft_printf_nbr(int nbr);
int		ft_print_ubase(unsigned long int nbr, char *base);
int		ft_print_pbase(unsigned long int nbr, char *base);
//******//
#endif