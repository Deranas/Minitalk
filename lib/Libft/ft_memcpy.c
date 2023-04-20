/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:09:23 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:35:55 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p_src;
	char	*p_dst;

	if (!(dest) && !(src))
		return (dest);
	i = 0;
	p_src = (char *) src;
	p_dst = (char *) dest;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (dest);
}
