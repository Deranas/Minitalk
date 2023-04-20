/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:37:03 by aschmid           #+#    #+#             */
/*   Updated: 2023/04/20 18:37:58 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Minitalk/minitalk.h"

void    send_string(int pid, char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
    if ((c & (0x01 << bit)))
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    usleep(500);
    bit++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    i = -1;
    while (argv[1][++i])
    {
        if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
            {
                ft_printf("Error!\nInvalid PID");
                return (1);
            }
    }
    if (argc != 3)
    {
        ft_printf("Error!\nUsage: ./client [server_pid] [string]");
        return (1);
    }
    pid = ft_atoi(argv[1]);
    i = -1;
    while (argv[2][++i])
        send_string(pid, argv[2][i]);
    send_string(pid, '\n');
    return (0);
}