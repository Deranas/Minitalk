/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:49:24 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:49:14 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (src[i] != '\0')
	{
		if (size && (i < (size - 1)))
		{
			dst[i] = src[i];
			z++;
		}
		i++;
	}
	if (size > 0)
		dst[z] = '\0';
	return (i);
}
