/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 05:16:08 by matraore          #+#    #+#             */
/*   Updated: 2021/06/09 05:42:11 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define BUFFSIZE 1024

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "tools.h"

typedef struct	s_stack
{
	char		message[BUFFSIZE];
	int			top_bit;
	int			top_byte;
	int		all_receive;
	int		buff_overflow;
}				t_stack;

t_stack			g_to_print = {{0}, 1 << 6, 0, FALSE, FALSE};

void			ft_error(char *str_error);
void			ft_print_pid(void);
#endif
