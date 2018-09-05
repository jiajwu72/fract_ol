/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:05:03 by jwu               #+#    #+#             */
/*   Updated: 2018/01/13 15:04:00 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		digit_to_char(int a)
{
	char c;

	if (a > 9 && a < 16)
		c = 'A' + a - 10;
	else
		c = a + '0';
	return (c);
}

static int		len(int nb)
{
	int i;

	i = 0;
	while (nb / 16 > 0)
	{
		nb /= 16;
		i++;
	}
	return (i + 1);
}

char			*ft_int_to_hexa(int nb)
{
	int		st;
	int		unite;
	char	c;
	char	*s;
	int		i;

	st = nb;
	s = ft_strnew(len(nb));
	i = 0;
	unite = len(nb);
	while (unite > 0)
	{
		nb = st;
		if (nb < ft_puiss(16, unite - 1))
			nb = 0;
		else
			while (nb > 16)
				nb = nb / 16;
		c = digit_to_char(nb);
		s[i++] = digit_to_char(nb);
		unite--;
		st -= (nb) * ft_puiss(16, unite);
	}
	return (s);
}
