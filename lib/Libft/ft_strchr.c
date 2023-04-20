/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:19:46 by aschmid           #+#    #+#             */
/*   Updated: 2023/02/28 12:55:16 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != (char) c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
