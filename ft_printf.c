/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:38:39 by vbleskin          #+#    #+#             */
/*   Updated: 2025/11/20 00:17:27 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parsing(char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int), format);
	else if (format == 'u' || format == 'x' || format == 'X')
		len += ft_putnbrbase(va_arg(args, unsigned int), 0, format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!*s)
				break ;
			len += ft_parsing(*s, args);
		}
		else
			len += ft_putchar(*s);
		if (*s)
			s++;
	}
	va_end(args);
	return (len);
}
