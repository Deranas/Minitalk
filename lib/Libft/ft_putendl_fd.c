/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:27:57 by aschmid           #+#    #+#             */
/*   Updated: 2022/12/29 11:38:36 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putendl_fd(char *s, int fd)
{
	int		index;

	index = 0;
	while (s[index] != '\0')
		write(fd, &s[index++], 1);
	write(fd, "\n", 1);
	return ;
}
