/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:41:15 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/03 13:08:37 by vbleskin         ###   ########.fr       */
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
