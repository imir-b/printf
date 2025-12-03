/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:41:15 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/04 00:20:18 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_flags(char *s, t_struct *list)
{
	const char	*flags = "-0# +";

	while (ft_strchr(flags, *s) && *s)
	{
		if (*s == '-')
			list->is_minus = 1;
		else if (*s == '0')
			list->is_zero = 1;
		else if (*s == '#')
			list->is_hash = 1;
		else if (*s == ' ')
			list->is_space = 1;
		else if (*s == '+')
			list->is_plus = 1;
		s++;
	}
	return (s);
}

char	*ft_align(char *dest, char *src, int is_minus, int dest_len)
{
	int	src_len;

	if (is_minus)
	{
		src_len = 0;
		while (*src)
			dest[src_len++] = (*src)++;
	}
	else
	{
		src_len = ft_strlen(src);
		while (src_len > 0)
			dest[dest_len--] = src[src_len--];
	}
	return (dest);
}

char	*ft_update_width(char *src, t_struct *list, char c)
{
	int		len;
	char	*dest;

	dest = malloc(sizeof(char) * (list->width) + 1);
	if (!dest)
		return (list->error = 1, NULL);
	if (c == '0' && list->is_dot)
		c = ' ';
	while (dest[len])
		dest[len++] = c;
	dest[len] = '\0';
	dest = ft_align(dest, src, list->is_minus, list->width);
	return (dest);
}
