/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:36:30 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/20 00:17:16 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static const char	*ft_base(char format)
{
	const char	*base;

	base = (NULL);
	if (format == 'X')
		base = "0123456789ABCDEF";
	else if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'u')
		base = "0123456789";
	return (base);
}

int	ft_putnbrbase(unsigned int nbr, int len, char format)
{
	const char	*base;

	base = ft_base(format);
	if (nbr >= ft_strlen(base))
		len += ft_putnbrbase(nbr / ft_strlen(base), len, format);
	len += ft_putchar(base[nbr % ft_strlen(base)]);
	return (len);
}
