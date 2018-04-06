/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:30:13 by eneto             #+#    #+#             */
/*   Updated: 2018/04/06 14:57:11 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned int	mod(int n)
{
	return ((n < 0) ? (-1 * (unsigned int)n) : (unsigned int)n);
}

static int			number_of_digits(int n)
{
	int n_digits;
	int aux;

	n_digits = 1;
	aux = n;
	while (aux > 9 || aux < -9)
	{
		n_digits++;
		aux = aux / 10;
	}
	return (n_digits);
}

char				*ft_itoa(int n)
{
	int		n_digits;
	int		aux;
	char	*str;

	n_digits = number_of_digits(n);
	aux = 0;
	if (n < 0)
		n_digits++;
	if (!(str = (char *)malloc(sizeof(char) * (n_digits + 1))))
		return (NULL);
	str[n_digits] = '\0';
	if (n < 0)
		str[0] = '-';
	while (aux < n_digits && str[n_digits - aux - 1] != '-')
	{
		str[n_digits - aux - 1] = mod(n) % 10 + '0';
		n = n / 10;
		aux++;
	}
	return (str);
}

int main()
{
  srand(clock());
  int i = 0;
  char *s;
  int n;

  while (i < 10)
    {
      n = rand();
      s = ft_itoa(n);
      if(atoi(s) == n)
	printf("%s : %d\n", s, n);
      i++;
    }
  printf("OK\n");
  return (0);
}
