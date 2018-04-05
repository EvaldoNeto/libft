/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:34:15 by eneto             #+#    #+#             */
/*   Updated: 2018/04/05 20:07:51 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int len;

	i = 0;
	while (s[i])
		i++;
	len = i;
	while (i > 0)
	{
		if (s[i] == c)
			return (char *)(s + i);
		i--;
	}
	if (c == '\0')
		return (char *)(s + len);
	return (NULL);
}
