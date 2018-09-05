/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 13:01:00 by jwu               #+#    #+#             */
/*   Updated: 2018/01/04 13:03:41 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		convertir(char c)
{
	if (ft_isdigit(c) == 1)
		return (c - '0');
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else
		return (-1);
}

int				ft_hexa_to_int(char *s)
{
	int res;
	int val;
	int unite;

	res = 0;
	unite = (int)ft_strlen(s) - 1;
	while (*s)
	{
		val = convertir(*s);
		res += val * ft_puiss(16, unite);
		s++;
		unite--;
	}
	return (res);
}
