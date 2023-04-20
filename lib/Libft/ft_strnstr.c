/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:00:50 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 12:19:10 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		z = 0;
		while (big[i + z] != '\0' && big[i + z] == little[z])
		{
			if ((i + z) >= len)
				return (NULL);
			if (little[z + 1] == '\0')
				return ((char *)&big[i]);
			z++;
		}
		i++;
	}
	return (NULL);
}
