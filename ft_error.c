#include "libft.h"

void ft_error(char *str)
{
    write(2, str, ft_strlen(str));
    exit(1);
}

void ft_print_pid(void)
{
    char    tmp;

    tmp = ft_itoa(getpid());
    write(1, "pid: ", 5);
	write(1, tmp, ft_strlen(tmp));
	write(1, "\n", 1);
	free(tmp);
}