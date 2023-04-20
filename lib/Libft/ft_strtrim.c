/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:20:32 by aschmid           #+#    #+#             */
/*   Updated: 2023/01/05 11:58:39 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	fset(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*substr;

	start = 0;
	while (fset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (fset(s1[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	substr = malloc((end - start + 2) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s1[start], (end - start + 2));
	return (substr);
}
