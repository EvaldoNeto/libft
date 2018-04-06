/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:54:20 by eneto             #+#    #+#             */
/*   Updated: 2018/04/06 20:33:59 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	temp[n];
	size_t			i;

	i = 0;
	while (i < n)
	{
		temp[i] = *(unsigned char *)(src + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = temp[i];
		i++;
	}
	return (dest);
}

int main()
{
	int size = 128 * 1024 * 1024;
	char *dst = (char *)malloc(sizeof(char) * size);
	char *data = (char *)malloc(sizeof(char) * size);

	printf("MOPA\n");
	ft_memmove(dst, data, size);

	return (0);
}
