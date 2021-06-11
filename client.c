/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 05:16:00 by matraore          #+#    #+#             */
/*   Updated: 2021/06/09 14:14:32 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <zconf.h>
#include "includes/minitalk.h"

void		send_bit(int pid, char *msg, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
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


int main(int argc, char **argv)
{
    int pid;
    char *message;

    pid = 0;
    if (argc != 3)
    {
        write(1, "utilisation: ./client [serveur-pid] [message]\n", 39);
	    exit(0);
    }
    pid = ft_atoi(argv[1]);
	message = ft_strdup(argv[2]);
	printf("%s \n", message);
    send_bit(pid, message, ft_strlen(argv[2]));
    return (0);
}