/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:38:18 by aschmid           #+#    #+#             */
/*   Updated: 2023/02/28 13:28:48 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	c;

	c = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[c] != '\0')
	{
		write(1, &str[c], 1);
		c++;
	}
	return (c);
}

char	*reverse_string(char *str, int count)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = count - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
