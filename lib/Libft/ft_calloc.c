/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:56:37 by aschmid           #+#    #+#             */
/*   Updated: 2023/01/04 13:31:39 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mptr;

	mptr = malloc(nmemb * size);
	if (mptr == NULL)
		return (NULL);
	ft_bzero(mptr, nmemb * size);
	return (mptr);
}
