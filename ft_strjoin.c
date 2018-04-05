/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:20:56 by eneto             #+#    #+#             */
/*   Updated: 2018/04/05 20:02:32 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(str = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	str[i + j] = '\0';
	while (j > 0)
	{
		str[i + j - 1] = s2[j - 1];
		j--;
	}
	while (i > 0)
	{
		str[i - 1] = s1[i - 1];
		i--;
	}
	return (str);
}
