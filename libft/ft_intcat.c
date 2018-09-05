/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:43:48 by jwu               #+#    #+#             */
/*   Updated: 2018/01/03 21:44:03 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intcat(int *dest, const int src)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	dest[i++] = src;
	dest[i] = '\0';
	return (dest);
}