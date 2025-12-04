/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:38:39 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/04 15:31:27 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_struct	*list;
	int			len;

	len = 0;
	list = ft_init_list();
	if (!list)
		return (-1);
	va_start(args, s);
	len = ft_parsing(s, args, list);
	va_end(args);
	if (list->error == 1)
		return (free(list), -1);
	return (free(list), len);
}
