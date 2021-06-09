#include <signal.h>
#include <zconf.h>
#include "includes/minitalk.h"

void		send_bit_by_bit(int pid, char *msg, size_t len)
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
    send_bit(pid, argv[2], ft_strlen(argv[2]));
    return (0);
}