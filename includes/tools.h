/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 05:40:51 by matraore          #+#    #+#             */
/*   Updated: 2021/06/11 15:30:38 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>

void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_size(int nb);
char	*ft_fill_str(char *str, long long int n, int len);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
void	ft_putstr(char *s);
void	ft_putchar(char c);

#endif