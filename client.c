/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 05:16:00 by matraore          #+#    #+#             */
/*   Updated: 2021/06/11 17:54:03 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <zconf.h>
#include "includes/minitalk.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	send_bit(int pid, char *msg, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift <= 7)
		{
			if ((msg[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	pid = 0;
	if (argc != 3)
	{
		ft_putstr("utilisation: ./client [serveur-pid] [message]\n");
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	message = ft_strdup(argv[2]);
	send_bit(pid, message, ft_strlen(argv[2]));
	return (0);
}
