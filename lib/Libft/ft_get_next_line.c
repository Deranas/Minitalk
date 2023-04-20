/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:24:33 by aschmid           #+#    #+#             */
/*   Updated: 2023/02/28 12:45:31 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*stack[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack[fd] = make_stack(fd, stack[fd]);
	if (!stack[fd])
		return (NULL);
	line = make_line(stack[fd]);
	stack[fd] = new_stack(stack[fd]);
	return (line);
}
