/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:38:49 by eneto             #+#    #+#             */
/*   Updated: 2018/04/05 20:00:21 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	i--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	if (j > 0 && !s[j])
		return ("");
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	if (!(str = (char *)malloc(sizeof(char) * (i - j + 2))))
		return (NULL);
	str[i - j + 1] = '\0';
	while (i - j >= 0)
	{
		str[i - j] = s[i];
		i--;
	}
	return ((char *)str);
}
