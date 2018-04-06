/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:35:44 by eneto             #+#    #+#             */
/*   Updated: 2018/04/06 19:07:04 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		num_of_words(char const *s, char c)
{
	int i;
	int n;

	n = 0;
	i = 0;
	if (s[0] != c)
		n++;
	while (s[i] && s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			n++;
		i++;
	}
	return (n);
}

static int		**words_pos(char const *s, char c, int n_words)
{
	int **pos;
	int i;
	int j;

	j = 0;
	i = 0;
	pos = (int **)malloc(sizeof(int *) * 2);
	if (!(*pos = (int *)malloc(sizeof(int) * n_words)))
		return (NULL);
	if (!(*(pos + 1) = (int *)malloc(sizeof(int) * n_words)))
		return (NULL);
	if (s[0] != c)
		pos[0][i] = 0;
	while (s[j] && s[j + 1])
	{
		if (s[j] == c && s[j + 1] != c)
			pos[0][i] = j + 1;
		if (s[j] != c && s[j + 1] == c)
		{
			pos[1][i] = j;
			i++;
		}
		j++;
	}
	if (s[j] != c)
		pos[1][i] = j;
	return (pos);
}

char			**ft_strsplit(char const *s, char c)
{
	int		n_words;
	int		**pos;
	int		i;
	int n;
	char	**str;

	n = 0;
	while (s[n])
		n++;
	n_words = num_of_words(s, c);
	pos = words_pos(s, c, n_words);
	i = 0;
	if (!(str = (char **)malloc(sizeof(char *) * (n_words + 1))))
		return (str);
	while (i < n_words)
	{
		if(!(*(str + i) = ft_strsub(s, pos[0][i], pos[1][i] - pos[0][i] + 1)))
		{
			i--;
			while (i >= 0)
			{
				free(*(str + i));
				*(str + i) = NULL;
				i--;
			}
			return str;
		}
		i++;
	}
	if(!(*(str + i) = (char *)malloc(sizeof(char))))
		return (str);
	*(str + i) = NULL;
	return (str);
}

/*int main()
{
	char *s = "";
	char **r = ft_strsplit(s, '\65');

	//char *s = "      split       this for   me  !       ";
	//char **r = ft_strsplit(s, ' ');

	while (*r)
	{
		for (int j = 0; j < 10; j++)
			printf("mopa %d : %x\n", j, **r);
		r++;
	}
	return (0);
	}*/
