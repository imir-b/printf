/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:58:29 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/03 10:32:32 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

const char	*ft_strchr(const char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (*str == '\0')
		return (NULL);
	return (str);
}

t_struct	*ft_init_list(void)
{
	t_struct	*list;

	list = malloc(sizeof(t_struct));
	if (!list)
		return (NULL);
	list->error = 0;
	list->is_minus = 0;
	list->is_zero = 0;
	list->is_dot = 0;
	list->is_hash = 0;
	list->is_space = 0;
	list->is_plus = 0;
	return (list);
}
