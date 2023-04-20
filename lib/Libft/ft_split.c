/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:52:47 by aschmid           #+#    #+#             */
/*   Updated: 2023/02/28 13:29:38 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	free_all(char **array, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
		free(array[i++]);
	free(array);
}

static int	w_count_alloc(char const *s, char c)
{
	int	index;
	int	w_count;

	index = 0;
	w_count = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == '\0'))
			w_count++;
		index++;
	}
	return (w_count);
}

static char	**w_size_alloc(char const	*s, char	**array, char c)
{
	int	index;
	int	w_len_count;
	int	pos;

	pos = 0;
	index = 0;
	w_len_count = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
			w_len_count++;
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == '\0'))
		{
			array[pos] = malloc((w_len_count + 1) * sizeof(char));
			if (!array[pos])
				free_all(array, pos);
			w_len_count = 0;
			pos++;
		}
		index++;
	}
	return (array);
}

static void	fill_array(char const *s, char **array, char c)
{
	int		i_str;
	int		i_arr;
	int		pos;

	i_str = 0;
	i_arr = 0;
	pos = 0;
	while (s[i_str] != '\0')
	{
		if (s[i_str] != c)
			array[pos][i_arr++] = s[i_str];
		if (s[i_str] != c && (s[i_str + 1] == c || s[i_str + 1] == '\0'))
		{
			array[pos++][i_arr] = '\0';
			i_arr = 0;
		}
		i_str++;
	}
	array[pos] = NULL;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		w_count;

	w_count = w_count_alloc(s, c);
	array = malloc((w_count + 1) * sizeof(char *));
	if (!(array))
		return (NULL);
	w_size_alloc(s, array, c);
	if (!(array))
		return (NULL);
	fill_array(s, array, c);
	return (array);
}
