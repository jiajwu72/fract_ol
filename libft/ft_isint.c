/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:20:00 by jwu               #+#    #+#             */
/*   Updated: 2018/01/03 16:56:35 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnum(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s) == 0)
			return (0);
		s++;
	}
	return (1);
}

int			ft_isint(char *s)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (ft_isnum(s))
		return (1);
	if (*s == '0' && *(++s) == 'x')
	{
		s++;
		if (ft_strlen(s) <= 6)
		{
			while (*s)
			{
				if (!((*s >= 'a' && *s <= 'f') ||
					(*s >= 'A' && *s <= 'F') || (ft_isdigit(*s) == 1)))
					return (0);
				s++;
			}
			return (1);
		}
	}
	return (0);
}
