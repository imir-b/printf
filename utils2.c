/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:59:53 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/07 18:34:22 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi_move(char **s)
{
	int	nb;

	nb = 0;
	while (**s && ft_isdigit((int)**s))
	{
		nb = nb * 10 + (**s - '0');
		(*s)++;
	}
	return (nb);
}

int	ft_nbaselen(unsigned long long n, int base_len)
{
	int	len;

	len = 1;
	while (n >= (unsigned long long)base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

int	ft_isupper(const char *str)
{
	while (*str)
	{
		if (*str <= 'z' && *str >= 'a')
			return (0);
		else if (*str <= 'Z' && *str >= 'A')
			return (1);
		str++;
	}
	return (0);
}
