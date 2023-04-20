/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_ptr_hex_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:47:29 by aschmid           #+#    #+#             */
/*   Updated: 2023/04/10 14:15:04 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX_DIGIT 20

int	print_ptr(unsigned long long nbr)
{
	int		hex_count;
	int		remainder;
	char	hex[MAX_DIGIT + 1];

	hex_count = 0;
	while (nbr > 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			hex[hex_count++] = remainder + '0';
		else
			hex[hex_count++] = remainder - 10 + 'a';
		nbr /= 16;
	}
	hex[hex_count] = '\0';
	ft_putstr(reverse_string(hex, hex_count));
	return (hex_count);
}

int	ft_putptr(unsigned long long ptr)
{
	int	ptr_count;

	ptr_count = 0;
	if (!ptr)
		return (ptr_count += ft_putstr("(nil)"));
	ptr_count += ft_putstr("0x");
	if (ptr == 0)
		ptr_count += ft_putchar('0');
	else
		ptr_count += print_ptr(ptr);
	return (ptr_count);
}

int	ft_puthex(unsigned int nbr, const char c)
{
	int		hex_count;
	int		remainder;
	char	hex[MAX_DIGIT + 1];

	hex_count = 0;
	if (nbr == 0)
		return (hex_count += ft_putchar('0'));
	while (nbr > 0)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			hex[hex_count++] = remainder + '0';
		else
		{
			if (c == 'X')
				hex[hex_count++] = remainder - 10 + 'A';
			else if (c == 'x')
				hex[hex_count++] = remainder - 10 + 'a';
		}
		nbr /= 16;
	}
	hex[hex_count] = '\0';
	return (ft_putstr(reverse_string(hex, hex_count)));
}

void	ft_putnbr(int nb, int *l_count)
{
	if (nb == -2147483648)
		*l_count += ft_putstr("-2147483648");
	else if (nb < 0)
	{
		*l_count += ft_putchar('-');
		ft_putnbr(nb * -1, l_count);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, l_count);
		ft_putnbr(nb % 10, l_count);
	}
	else
	{
		*l_count += ft_putchar(nb + '0');
	}
}

void	ft_putunbr(unsigned int nb, int *l_count)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10, l_count);
		ft_putnbr(nb % 10, l_count);
	}
	else
	{
		*l_count += ft_putchar(nb + '0');
	}
}
