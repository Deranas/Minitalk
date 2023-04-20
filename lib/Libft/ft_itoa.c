/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:51:34 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:29:54 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	d_len(int n)
{
	int	d_len;

	d_len = 1;
	if (n < 0)
		d_len++;
	while (n / 10 != 0)
	{
		n /= 10;
		d_len++;
	}
	return (d_len);
}

static void	putnbr(int n, int pos, char *num)
{
	num[pos + 1] = '\0';
	if (n == 0)
	{
		num[pos] = '0';
	}
	while (n > 0)
	{
		num[pos--] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		pos;
	char	*num;
	int		digit;

	pos = 0;
	digit = d_len(n);
	if (n == -2147483648)
	{
		num = ft_strdup("-2147483648");
		return (num);
	}
	num = malloc((digit + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	if (n < 0)
	{
		num[pos] = '-';
		n *= -1;
	}
	pos = digit - 1;
	putnbr(n, pos, num);
	return (num);
}
