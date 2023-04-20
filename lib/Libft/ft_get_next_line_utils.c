/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:24:47 by aschmid           #+#    #+#             */
/*   Updated: 2023/02/28 12:56:05 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_stack(int fd, char *stack)
{
	char	*buf;
	int		fd_count;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	fd_count = 1;
	while (!ft_strchr(stack, '\n') && fd_count != 0)
	{
		fd_count = read(fd, buf, BUFFER_SIZE);
		if (fd_count < 0)
		{
			free(buf);
			if (stack)
				free(stack);
			return (NULL);
		}
		buf[fd_count] = '\0';
		stack = ft_gnl_strjoin(stack, buf);
	}
	free(buf);
	return (stack);
}

char	*make_line(char *stack)
{
	int		i;
	char	*str;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] != '\n' && stack[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i])
	{
		str[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n' && stack[i])
		str[i] = '\0';
	return (str);
}

char	*new_stack(char *stack)
{
	int		i;
	int		z;
	char	*str;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	str = malloc((ft_strlen(stack) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	z = 0;
	i++;
	while (stack[i])
		str[z++] = stack[i++];
	str[z] = '\0';
	free(stack);
	return (str);
}

char	*ft_gnl_strjoin(char *stack, char *buf)
{
	char	*str;
	int		i;
	int		z;

	i = -1;
	z = 0;
	if (!stack)
	{
		stack = malloc(1 * sizeof(char));
		stack[0] = '\0';
	}
	str = malloc((ft_strlen(stack) + ft_strlen(buf) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (stack[++i] != '\0')
		str[i] = stack[i];
	while (buf[z] != '\0')
		str[i++] = buf[z++];
	str[i] = '\0';
	free (stack);
	return (str);
}
