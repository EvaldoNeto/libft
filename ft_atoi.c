/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:30:20 by eneto             #+#    #+#             */
/*   Updated: 2018/04/05 19:59:23 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	int			j;
	long int	result;

	result = 0;
	j = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (ft_isdigit(nptr[i + j]))
	{
		result = result * 10 + (nptr[i + j] - '0');
		j++;
	}
	if (sign * result == (int)(sign * result))
		return ((int)(sign * result));
	else
		return ((sign > 0) ? -1 : 0);
}
