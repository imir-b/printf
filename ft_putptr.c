/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:16:48 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/20 00:17:13 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptrbase(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_putptrbase(n / 16, base);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	n;

	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		len = ft_putstr("0x");
		n = (unsigned long)ptr;
		len += ft_putptrbase(n, "0123456789abcdef");
	}
	return (len);
}
