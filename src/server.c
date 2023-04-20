/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmid <aschmid@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:37:07 by aschmid           #+#    #+#             */
/*   Updated: 2023/04/20 18:19:21 by aschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Minitalk/minitalk.h"

void    print_string(int signum)
{
    static int bit;
    static int i;

    if(signum == SIGUSR1)
        i |= (0x01 << bit);
    bit++;
    if(bit == 8)
    {
        ft_printf("%c", i);
        bit = 0;
        i = 0;
    }
}

int main(void)
{
    ft_printf("Hello! :-)\nServer's PID:%i\n", getpid());
    while(1)
    {
    signal(SIGUSR1, print_string);
    signal(SIGUSR2, print_string);
    pause();
    }
}