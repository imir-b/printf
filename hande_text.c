/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hande_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:37:57 by vlad              #+#    #+#             */
/*   Updated: 2025/12/04 09:53:48 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hande_str(char *str, t_struct *list)
{
 	int		len;
	int		ret_len;
	char	padding;

	len = ft_strlen(str);
	//precision
	padding = ' ';
	if (list->is_zero)
		padding = '0';
	ret_len = 0;
	if (!list->is_minus)
    {
		ret_len += ft_put_padding(list->width, len, padding, list);
	}
	ret_len += ft_putstr(str, list);
	if (list->is_minus)
	{
		ret_len += ft_put_padding(list->width, len, padding, list);
	}
	return (ret_len);
}

int	ft_handle_char(char c, t_struct *list)
{
	int		len;
	int		ret_len;
	char	padding;

	len = 1;
	//precision
	padding = ' ';
	if (list->is_zero)
		padding = '0';
	ret_len = 0;
	if (!list->is_minus)
    {
		ret_len += ft_put_padding(list->width, len, padding, list);
	}
	ret_len += ft_putchar(c, list);
	if (list->is_minus)
    {
		ret_len += ft_put_padding(list->width, len, padding, list);
	}
	return (ret_len);
}

int	ft_handle_ptr(void *ptr, t_struct *list)
{
 	int		len;
	int		ret_len;
	char	padding;

	len = ; //len ?
	//precision
	padding = ' ';
	if (list->is_zero)
		padding = '0';
	ret_len = 0;
	if (!list->is_minus)
    {
		ret_len += ft_put_padding(list->width, len, padding, list);
	}
	ret_len += ft_putptr(ptr, list);
	if (list->is_minus)
	{
		ret_len += ft_put_padding(list->width, len, padding, list);
	}
	return (ret_len);
}