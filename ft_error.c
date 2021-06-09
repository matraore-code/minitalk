/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 05:15:35 by matraore          #+#    #+#             */
/*   Updated: 2021/06/09 05:26:35 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void ft_error(char *str)
{
    write(2, str, ft_strlen(str));
    exit(1);
}

void ft_print_pid(void)
{
    char    *tmp;

    tmp = ft_itoa(getpid());
    write(1, "pid: ", 5);
	write(1, tmp, ft_strlen(tmp));
	write(1, "\n", 1);
	free(tmp);
}