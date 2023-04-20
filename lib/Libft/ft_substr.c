/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:46:20 by aschmid           #+#    #+#             */
/*   Updated: 2023/04/10 14:16:29 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	if (len > s_len - start)
		str = malloc(s_len - start + 1);
	else
		str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], (len + 1));
	return (str);
}
