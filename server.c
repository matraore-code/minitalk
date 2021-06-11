/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 05:15:28 by matraore          #+#    #+#             */
/*   Updated: 2021/06/09 05:25:06 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <zconf.h>
#include "includes/minitalk.h"



static t_msg g_msg;

void			get_bit_by_bit(int bit)
{
	g_msg.c += ((bit & 1) << g_msg.size);
	g_msg.size++;
	if (g_msg.size == 7)
	{
		ft_putchar(g_msg.c);
		if (!g_msg.c)
			ft_putchar('\n');
		g_msg.c = 0;
		g_msg.size = 0;
	}
}

int				main(void)
{
	g_msg.c = 0;
	g_msg.size = 0;
	ft_putstr("server pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR2, get_bit_by_bit);
		signal(SIGUSR1, get_bit_by_bit);
		pause();
	}
}