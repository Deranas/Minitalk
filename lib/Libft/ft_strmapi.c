/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:00:27 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:52:03 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index;

	str = ft_strdup(s);
	index = 0;
	if (!(str))
		return (NULL);
	while (str[index] != '\0')
	{
		str[index] = (*f)(index, str[index]);
		index++;
	}
	return (str);
}
