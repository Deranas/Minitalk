/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:15:39 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:30:43 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	p = (char *) s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (char) c)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
