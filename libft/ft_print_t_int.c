/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_t_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:55:09 by jwu               #+#    #+#             */
/*   Updated: 2018/01/13 15:02:44 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_t_int(int *s)
{
	ft_putstr("(");
	while (*s)
	{
		ft_putnbr(*s);
		ft_putstr(" ");
		s++;
	}
	ft_putendl(")");
}
