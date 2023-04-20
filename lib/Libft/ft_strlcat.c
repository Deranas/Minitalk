/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:12:09 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:49:34 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destl;

	i = 0;
	destl = ft_strlen(dst);
	if (!size)
		return (ft_strlen(src));
	while (src[i] && (destl + i) < size - 1)
	{
		dst[destl + i] = src[i];
		i++;
	}
	dst[destl + i] = '\0';
	if (destl > size)
		return (size + ft_strlen(src));
	return (destl + ft_strlen(src));
}
