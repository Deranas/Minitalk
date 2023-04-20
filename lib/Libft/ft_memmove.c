/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:46:19 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:37:23 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_src;
	char	*p_dst;
	size_t	i;

	if (!(dest) && !(src))
		return (dest);
	i = n;
	p_src = (char *)src;
	p_dst = (char *)dest;
	if (p_src < p_dst)
		while (i-- > 0)
			p_dst[i] = p_src[i];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
