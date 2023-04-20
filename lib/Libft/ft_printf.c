/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:23:44 by aschmid           #+#    #+#             */
/*   Updated: 2023/02/24 18:04:26 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_string(const char c, va_list args, int *l_count)
{
	int	letter_count;

	letter_count = 0;
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), l_count);
	else if (c == 'c')
		letter_count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		letter_count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		letter_count += ft_putptr(va_arg(args, unsigned long long));
	else if (c == 'x' || c == 'X')
		letter_count += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		letter_count += ft_putchar('%');
	else if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int), l_count);
	return (letter_count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		letter_count;
	int		index;

	index = 0;
	letter_count = 0;
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			index++;
			letter_count += format_string(str[index], args, &letter_count);
		}
		else
			letter_count += ft_putchar(str[index]);
		index++;
	}
	va_end(args);
	return (letter_count);
}
