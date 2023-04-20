/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:22:06 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:34:26 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			z;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	z = 0;
	p_s1 = (unsigned char *) s1;
	p_s2 = (unsigned char *) s2;
	while (z < n)
	{
		if (p_s1[z] != p_s2[z])
			return (p_s1[z] - p_s2[z]);
		z++;
	}
	return (0);
}
