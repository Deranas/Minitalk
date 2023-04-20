/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:19:31 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:46:14 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str_size;
	int		i;
	int		z;

	i = 0;
	z = 0;
	str_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(str_size * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[z] != '\0')
		str[i++] = s2[z++];
	str[i] = '\0';
	return (str);
}
