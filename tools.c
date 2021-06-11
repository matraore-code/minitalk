/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 05:11:00 by matraore          #+#    #+#             */
/*   Updated: 2021/06/11 17:53:51 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/tools.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*src;
	size_t			i;

	src = s;
	i = 0;
	while (i < n)
	{
		src[i] = 0;
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > 2147483648 && neg == -1)
			return (0);
		if (nb > 2147483648)
			return (-1);
		i++;
	}
	return (nb * neg);
}

int	ft_size(int nb)
{
	int	r;

	r = 0;
	if (nb <= 0)
	{
		r++;
		nb = -1 * nb;
	}
	while (nb != 0)
	{
		r++;
		nb = nb / 10;
	}
	return (r);
}

char	*ft_fill_str(char *str, long long int n, int len)
{
	int	l;
	int	deb;

	deb = 0;
	len = ft_size(n);
	l = len;
	if (n < 0)
	{
		str[0] = '-';
		deb = 1;
		n *= -1;
	}
	while (len - 1 >= deb)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	str[l] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_size(n) + 1);
	if (str == NULL)
		return (0);
	return (ft_fill_str(str, n, i));
}
