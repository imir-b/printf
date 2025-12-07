/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:29:13 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/07 18:34:57 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int i, t_struct *list)
{
	char	c;
	int		bytes;

	c = (char)i;
	bytes = write(1, &c, 1);
	if (bytes == -1)
		list->error = 1;
	return (bytes);
}

int	ft_putstr(char *str, int len, t_struct *list)
{
	int	bytes;

	if (!str)
	{
		bytes = write(1, "(null)", 6);
		if (bytes == -1)
			list->error = 1;
		return (bytes);
	}
	bytes = write(1, str, len);
	if (bytes == -1)
		list->error = 1;
	return (bytes);
}

int	ft_putnbr(int nbr, t_struct *list)
{
	int	bytes;

	bytes = 0;
	if (nbr == -2147483648)
	{
		bytes = ft_putstr("-2147483648", 11, list);
		return (bytes);
	}
	else
	{
		if (nbr < 0)
		{
			bytes += ft_putchar('-', list);
			nbr *= -1;
		}
		if (nbr > 9)
			bytes += ft_putnbr(nbr / 10, list);
		bytes += ft_putchar(nbr % 10 + '0', list);
	}
	return (bytes);
}

int	ft_putnbrbase(unsigned long long nbr, const char *base, t_struct *list)
{
	int	bytes;

	bytes = 0;
	if (nbr >= (unsigned long long)ft_strlen(base))
		bytes += ft_putnbrbase(nbr / ft_strlen(base), base, list);
	bytes += ft_putchar(base[nbr % ft_strlen(base)], list);
	return (bytes);
}
