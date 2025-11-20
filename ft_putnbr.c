/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:15:55 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/20 00:17:19 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr, char format)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (nbr < 0)
		{
			len += ft_putchar('-');
			nbr *= -1;
		}
		if (nbr > 9)
			len += ft_putnbr(nbr / 10, format);
		len += ft_putchar(nbr % 10 + '0');
	}
	return (len);
}
