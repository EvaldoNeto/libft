/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:47:18 by eneto             #+#    #+#             */
/*   Updated: 2018/04/05 20:05:50 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*(char *)(src + i) != c)
			*(char *)(dest + i) = *(char *)(src + i);
		else
		{
			*(char *)(dest + i) = *(char *)(src + i);
			return (void *)(src + i + 1);
		}
		i++;
	}
	return (NULL);
}
