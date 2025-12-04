/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:38:24 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/04 02:18:52 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_base(unsigned int arg, char format, t_struct *list)
{
	int		len;
	char	*base;

	len = 0;
	base = NULL;
	if (format == 'u')
		base = "0123456789";
	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	len += ft_handle_nbrbase(arg, base, list);
	return (len);
}

int	ft_check_format(char format, va_list args, t_struct *list)
{
	int			len;
	const char	*conversions = "cspdiuxX%";

	if (!ft_strchr(conversions, format))
		return (list->error = -1, -1);
	len = 0;
	if (format == 'c')
		len += ft_handle_char(va_arg(args, int), list);
	else if (format == 's')
		len += ft_handle_str(va_arg(args, char *), list);
	else if (format == 'p')
		len += ft_handle_ptr(va_arg(args, void *), list);
	else if (format == 'd' || format == 'i')
		len += ft_handle_int(va_arg(args, int), list);
	else if (format == 'u' || format == 'x' || format == 'X')
		len += ft_check_base(va_arg(args, unsigned int), format, list);
	else if (format == '%')
		len += ft_putchar('%', list);
	return (len);
}

int	ft_put_until_percent(const char *s, char *next_percent, t_struct *list)
{
	int	size;
	int	bytes;

	size = next_percent - s;
	bytes = write (1, s, size);
	if (bytes == -1)
		list->error = 1;
	return (bytes);
}

int	ft_process_percent(char **s, va_list args, t_struct *list)
{
	int	len;

	(*s)++;
	*s = ft_check_flags(*s, list);
	if (ft_isdigit(**s))
		list->width = ft_atoi_move(s);
	if (**s == '.')
	{
		list->is_dot = 1;
		(*s)++;
		if (ft_isdigit(**s))
		list->precision = ft_atoi_move(s);
		else
		list->precision = 0;
	}
	len = ft_check_format(**s, args, list);
	if (**s)
		(*s)++;
	return (ft_reset_list(list), len);
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
			len += ft_process_percent((char **)&s, args, list);
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
