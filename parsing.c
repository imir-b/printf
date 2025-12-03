/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:38:24 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/03 11:41:39 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_base(char format)
{
	char	*base;

	base = NULL;
	if (format == 'u')
		base = "0123456789";
	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	return (base);
}

int	ft_check_format(char format, va_list args, t_struct *list)
{
	int			len;
	char		*base;
	const char	*conversions = "cspdiuxX%";

	if (!ft_strchr(conversions, format))
		return (list->error = -1, -1);
	len = 0;
	base = NULL;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int), list);
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *), list);
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *), list);
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int), list);
	else if (format == 'u' || format == 'x' || format == 'X')
	{
		base = ft_check_base(format);
		len += ft_putnbrbase(va_arg(args, unsigned int), base, list);
	}
	else if (format == '%')
		len += ft_putchar('%', list);
	return (len);
}

int	ft_put_until_percent(const char *s, char *next_percent, t_struct *list)
{
	int	dist;
	int	bytes;

	dist = next_percent - s ;
	bytes = write (1, s, dist);
	if (bytes == -1)
		list->error = 1;
	return (bytes);
}

int	ft_parsing(const char *s, va_list args, t_struct *list)
{
	int		len;
	char	*next_percent;

	len = 0;
	while (*s)
	{
		next_percent = (char *)ft_strchr(s, '%');
		if (next_percent)
		{
			len += ft_put_until_percent(s, next_percent, list);
			s = next_percent;
			s = ft_check_flags(s, list);
			len += ft_check_format(*s, args, list);
			if (*s)
				s++;
		}
		else
		{
			len += ft_putstr((char *)s, list);
			break ;
		}
		if (list->error == 1)
			return (-1);
	}
	return (len);
}

// int	ft_parsing(const char *s, va_list args, t_struct *list)
// {
// 	int	len;

// 	len = 0;
// 	while (*s)
// 	{
// 		if (*s == '%')
// 		{
// 			s++;
// 			if (!*s)
// 				break ;
// 			len += ft_check_format(*s, args, list);
// 		}
// 		else
// 			len += ft_putstr(*s);
// 		if (*s)
// 			s++;
// 	}
// 	if (list->error == 1)
// 		return (-1);
// 	return (len);
// }
