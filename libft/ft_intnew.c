/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:11:47 by jwu               #+#    #+#             */
/*   Updated: 2018/01/11 20:14:38 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intnew(int len)
{
	int i;
	int *s;

	i = -1;
	s = (int *)malloc(sizeof(int) * (len + 1));
	while (++i < len + 1)
		s[i] = 0;
	return (s);
}
