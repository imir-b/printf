/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 01:41:21 by vlad              #+#    #+#             */
/*   Updated: 2025/12/04 03:08:39 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_int(int nb, t_struct *list)
{
	int		len;
	int 	ret_len;
	char	padding;

	if (nb == 0 && list->precision == 0)
		return (0);
	len = ft_nbrlen(nb);
	//precision
	padding = ' ';
	if (list->is_zero && list->precision < 0)
		padding = '0';
	if (!list->is_minus)
	{
		ret_len += ft_put_padding(list->width, len, padding, list);
	}
	ret_len += ft_putnbr(nb, list);
	if (list->is_minus)
	{
		ret_len += ft_put_padding(list->width, len, padding, list);
	}
	return (ret_len);
}
