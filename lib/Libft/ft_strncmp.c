/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:11:43 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 12:18:36 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	z;

	z = 0;
	while (z < n)
	{
		if (s1[z] != s2[z])
			return ((unsigned char) s1[z] - (unsigned char) s2[z]);
		if (s1[z] == '\0')
			return (0);
		z++;
	}
	return (0);
}
