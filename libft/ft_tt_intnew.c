/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tt_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:24:01 by jwu               #+#    #+#             */
/*   Updated: 2018/01/05 18:24:02 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_tt_intnew(int len, int w)
{
	int		**s;
	int		i;

	i = 0;
	s = malloc(sizeof(int *) * (len + 1));
	while (i < len)
		s[i++] = malloc(sizeof(int) * (w + 1));
	s[i] = 0;
	return (s);
}
