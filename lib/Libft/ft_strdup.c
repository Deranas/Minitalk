/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:42:33 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:46:48 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*nstr;

	i = 0;
	while (s[i] != '\0')
		i++;
	nstr = malloc((i + 1) * sizeof(*nstr));
	if (nstr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		nstr[i] = s[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
